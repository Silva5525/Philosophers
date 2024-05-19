/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 22:01:03 by wdegraf           #+#    #+#             */
/*   Updated: 2024/05/18 12:45:11 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/// @brief Allocates (with malloc(3)) and returns an array
/// of strings obtained by splitting ’s’ using the
/// character ’c’ as a delimiter. The array must end
/// with a NULL pointer.
/// @param s The string to be split
/// @param c The delimeter character
/// @return array of new strings resulting from the split. Null if fails.
static char	*ft_ssubstr(char const *s, size_t len)
{
	char	*a;
	size_t	i;

	if (!s || !*s || 0 >= ft_strlen(s) || len == 0)
		return (NULL);
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	a = (char *)malloc(len + 1);
	if (a == NULL)
		return (NULL);
	i = 0;
	while (i < len && s[i] != '\0')
	{
		a[i] = s[i];
		i++;
	}
	a[i] = '\0';
	return (a);
}

static size_t	ft_subscount(char const *s, char c)
{
	size_t	subs;
	int		i;

	i = 1;
	subs = 0;
	while (*s)
	{
		if (*s == c)
		{
			i = 1;
		}
		else
		{
			if (i)
			{
				subs++;
				i = 0;
			}
		}
		s++;
	}
	return (subs);
}

void	f_it(char **out1)
{
	int		i;

	i = 0;
	while (out1[i])
	{
		free(out1[i]);
		out1[i] = NULL;
		i++;
	}
	free(out1);
}

static char	**split_i_ft_split(const char *s, char c, char **out1)
{
	const char	*start;
	int			i;

	i = 0;
	while (*s)
	{
		if (*s && *s != c)
		{
			start = s;
			while (*s && *s != c)
				s++;
			if (s - start == 0)
				return (out1);
			out1[i++] = ft_ssubstr(start, s - start);
			if (out1[i - 1] == NULL)
			{
				f_it(out1);
				return (NULL);
			}
		}
		else
			s++;
	}
	return (out1);
}

/// @brief Allocates (with malloc(3)) and returns an array
/// of strings obtained by splitting ’s’ using the
/// character ’c’ as a delimiter. The array must end
/// with a NULL pointer.
/// @param s string to be split
/// @param c character to split the string
/// @return the double array of new strings resulting from the split. 
/// Null if fails.
char	**ft_split(const char *s, char c)
{
	size_t	sub_i;
	char	**out1;

	if (s == NULL)
		return (NULL);
	sub_i = ft_subscount(s, c);
	out1 = (char **)malloc((sub_i + 1) * sizeof(char *));
	if (out1 == NULL)
		return (NULL);
	out1[sub_i] = NULL;
	out1 = split_i_ft_split(s, c, out1);
	if (!out1)
		return (NULL);
	return (out1);
}

// #include <stdio.h>
// int	main(void)
// {
// 	char const	s[] = "hello!";
// 	char		c = ' ';
// 	char		**out = ft_split(s, c);
// 	size_t		i = 0;
// 	if (out)
// 	{
// 		while (out[i] != NULL)
// 		{
// 			printf("%s\n", out[i]);
// 			free(out[i]);
// 			i++;
// 		}
// 		free(out);
// 		return (0);
// 	}
// 	else
// 		printf("Allocation failed.\n");
// 	return (0);
// }
