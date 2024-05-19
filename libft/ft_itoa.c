/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 18:07:56 by wdegraf           #+#    #+#             */
/*   Updated: 2024/01/21 16:25:47 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/// @brief itoa Allocates (with malloc(3)) and returns a string
/// representing the integer received as an argument.
/// free it in the main.
/// @param n integer (number)
/// @return a string representing the integer n
char	*ft_invert(char *a, int n)
{
	char	b;
	int		start;
	int		end;

	start = 0;
	end = n;
	while (start < end)
	{
		b = a[start];
		a[start] = a[end];
		a[end] = b;
		start++;
		end--;
	}
	return (a);
}

static int	ft_negativ(char *out, int n, int i)
{
	int		hold;

	i = 0;
	n = -n;
	if (n == -2147483648)
	{
		ft_strlcpy(out, "-2147483648", 12);
	}
	else
	{
		while (n != 0)
		{
			hold = n % 10;
			out[i++] = hold + '0';
			n /= 10;
		}
		out[i++] = '-';
		out[i] = '\0';
	}
	return (i);
}

static int	ft_sizeint(int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		n = n - 1;
		i++;
	}
	if (n == 0)
		i++;
	while (n)
	{
		n /= 10;
		i++;
	}
	i++;
	return (i);
}

char	*ft_itoa(int n)
{
	char	*out;
	int		hold;
	int		i;

	i = 0;
	out = (char *)malloc(ft_sizeint(n));
	if (!out)
		return (NULL);
	if (n < 0)
		i = ft_negativ(out, n, i);
	else
	{
		if (n == 0)
			out[i++] = 0 + '0';
		while (n != 0)
		{
			hold = n % 10;
			out[i++] = hold + '0';
			n /= 10;
		}
		out[i] = '\0';
	}
	ft_invert(out, i - 1);
	return (out);
}

// #include <stdio.h>
// int	main(void)
// {
// 	int		n;
// 	char	*int_c;

// 	n = -2147483648;
// 	int_c = ft_itoa(n);
// 	printf("%s\n", int_c);
// 	free(int_c);
// 	return (0);
// }
