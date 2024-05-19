/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 11:40:52 by wdegraf           #+#    #+#             */
/*   Updated: 2023/11/08 15:03:11 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/// @brief allocates memory. The calloc() function contiguously allocates enough
/// space for count objects that are size bytes of memory each and returns a 
/// pointer to the allocated memory.  The allocated memory is filled 
/// with bytes of value zero.
/// @param count are to allocate objects
/// @param size of the count objects
/// @return functions return a pointer to allocated memory. If there is an error
/// they return a NULL pointer and set errno to ENOMEM.
void	*ft_calloc(size_t count, size_t size)
{
	size_t		i;
	void		*a;

	i = count * size;
	if (i == 0 || count == 0)
	{
		a = malloc(0);
		if (a == NULL)
			return (NULL);
		else
			return (a);
	}
	a = malloc(i);
	if (a == NULL)
		return (NULL);
	ft_memset(a, 0, i);
	return (a);
}

// #include <stdio.h>
// int	main(void)
// {
// 	size_t	count = 5;
// 	size_t	size = sizeof(count);
// 	size_t	i;
// 	void	*out = ft_calloc(count, size);
// 	int *print = (int *)out;
// 	i = 0;
// 	while (i < count)
// 	{
// 		printf ("%d\n", print[i]);
// 		i++;
// 	}
// 	free(out);
// 	return (0);
// }