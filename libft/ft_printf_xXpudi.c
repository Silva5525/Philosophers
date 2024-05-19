/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_xXpudi.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 16:26:11 by wdegraf           #+#    #+#             */
/*   Updated: 2024/01/21 13:19:37 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	v_x(va_list *args, const char *base_char, ssize_t *wr_i)
{
	char				hex[18];
	void				*p;
	unsigned int		c;
	int					i;

	i = 0;
	p = va_arg(*args, void *);
	c = (uintptr_t)p;
	if (c == 0)
		hex[i++] = '0';
	while (c)
	{
		hex[i] = base_char[c % 16];
		i++;
		c = c / 16;
	}
	hex[i] = '\0';
	while (i > 0)
	{
		*wr_i = write(1, &hex[--i], 1);
		if (*wr_i == -1)
			return (-1);
	}
	return (ft_strlen(hex));
}

int	v_p_else( ssize_t *wr_i, char *hex, int i)
{
	int		remain;

	remain = i;
	*wr_i = write(1, "0x", 2);
	if (*wr_i == -1)
		return (-1);
	while (i--)
	{
		*wr_i = write(1, &hex[i], 1);
		if (*wr_i == -1)
			return (-1);
	}
	return (remain + 2);
}

int	v_p(va_list *args, const char *base_char, ssize_t *wr_i)
{
	void			*p;
	char			hex[256];
	unsigned long	c;
	int				i;

	i = 0;
	p = va_arg(*args, void *);
	c = (unsigned long)p;
	if (p == NULL)
	{
		*wr_i = write(1, "0x0", 3);
		if (*wr_i == -1)
			return (-1);
	}
	else
	{
		while (c != 0)
		{
			hex[i++] = base_char[c % 16];
			c = c / 16;
		}
		*wr_i = v_p_else(wr_i, hex, i);
	}
	return (*wr_i);
}

int	v_u(va_list *args, ssize_t *wr_i)
{
	ssize_t	hold;
	int		di;
	int		i;
	char	str[10];

	di = 0;
	hold = va_arg(*args, unsigned int);
	if (hold == 0)
		str[di++] = hold % 10 + '0';
	while (hold)
	{
		str[di++] = hold % 10 + '0';
		hold /= 10;
	}
	i = di;
	while (i)
	{
		*wr_i = write(1, &str[--i], 1);
		if (*wr_i == -1)
			return (-1);
	}
	return (di);
}

int	v_di(va_list *args)
{
	char	*di;
	int		i;
	int		wr_i;

	i = va_arg(*args, int);
	if (i == 0)
	{
		wr_i = write(1, "0", 1);
		if (wr_i == -1)
			return (-1);
		return (1);
	}
	di = ft_itoa(i);
	if (!di)
		return (-1);
	wr_i = write(1, di, ft_strlen(di));
	if (wr_i == -1)
	{
		free(di);
		return (-1);
	}
	i = ft_strlen(di);
	free(di);
	return (wr_i);
}
