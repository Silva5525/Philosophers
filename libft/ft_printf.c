/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:42:59 by wdegraf           #+#    #+#             */
/*   Updated: 2024/01/21 12:19:08 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

static int	v_c(va_list *args)
{
	char	c;
	int		count;
	int		wr_i;

	count = 0;
	c = va_arg(*args, int);
	wr_i = write(1, &c, 1);
	if (wr_i == -1)
		return (-1);
	return (++count);
}

static int	v_s(va_list *args)
{
	char	*s;
	int		wr_i;

	s = va_arg(*args, char *);
	if (s == NULL)
	{
		wr_i = write (1, "(null)", 6);
		if (wr_i == -1)
			return (-1);
		return (6);
	}
	wr_i = write(1, s, ft_strlen(s));
	if (wr_i == -1)
		return (-1);
	return (ft_strlen(s));
}

int	v_remix(char format, va_list *args, ssize_t *wr_i)
{
	if (format == 'd' || format == 'i')
		return (v_di(args));
	else if (format == 'c')
		return (v_c(args));
	else if (format == 's')
		return (v_s(args));
	else if (format == 'u')
		return (v_u(args, wr_i));
	else if (format == 'p')
		return (v_p(args, "0123456789abcdefx", wr_i));
	else if (format == 'x')
		return (v_x(args, "0123456789abcdefx", wr_i));
	else if (format == 'X')
		return (v_x(args, "0123456789ABCDEFX", wr_i));
	else if (format == '%')
	{
		*wr_i = write(1, "%", 1);
		if (*wr_i == -1)
			return (-1);
		return (1);
	}
	else
		return (-1);
}

int	ft_print_one(const char *format, va_list *args, ssize_t *wr_i)
{
	int			count_hold;
	char		format_hold;

	count_hold = 0;
	while (*format)
	{
		if (*format == '%')
		{
			++format;
			format_hold = *format;
			*wr_i = v_remix(format_hold, args, wr_i);
		}
		else
			*wr_i = write(1, format, 1);
		format++;
		if (*wr_i == -1)
			return (-1);
		count_hold = *wr_i + count_hold;
	}
	return (count_hold);
}

int	ft_printf(const char *format, ...)
{
	va_list		args;
	ssize_t		*wr_i;
	ssize_t		hold;

	hold = 0;
	wr_i = &hold;
	va_start(args, format);
	*wr_i = ft_print_one(format, &args, wr_i);
	if (*wr_i == -1)
		return (-1);
	va_end(args);
	return (*wr_i);
}

// #include <stdio.h>
// int	main(void)
// {
// 	// int		i_pri = 0;
// 	// int		t_pri = 0;

// 	int		a;
// 	int		b;

// 	// int		d = 10;
// 	// int		u = -2147483648;
// 	// char	c = 'Z';
// 	// char	*s = NULL;

// // i_pri = ft_printf("My logtime is %d %x %X %% %u and %c %s liv in %p \n",
// // 		d, d, d, u, c, s, s);
// // t_pri = printf("My logtime is %d %x %X %% %u and %c %s liv in %p \n",
// // 		d, d, d, u, c, s, s);
// // printf("my counter %d\n .. test counter %d\n", i_pri, t_pri);
// 	a = ft_printf("a%%");
// 	b = printf("b%%");
// 	printf("my %i test %i\n", a, b);
// 	return (0);
// }
