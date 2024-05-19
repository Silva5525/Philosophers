/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 23:53:19 by wdegraf           #+#    #+#             */
/*   Updated: 2023/11/09 16:52:05 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

/// @brief Outputs the string ’s’ to the given file descriptor
/// followed by a newline
/// @param s The string to output
/// @param fd The file descriptor on which to write
void	ft_putendl_fd(char *s, int fd)
{
	size_t	i;
	size_t	j;
	char	c;

	j = 0;
	i = 0;
	while (s[i] != '\0')
		i++;
	while (i != j)
	{
		c = s[j];
		write(fd, &c, 1);
		j++;
	}
	c = '\n';
	write(fd, &c, 1);
}

// #include <stdio.h>
// #include <fcntl.h>

// int	main(void)
// {
// 	int file_descriptor = open("test.txt", O_WRONLY 
// 	| O_CREAT, S_IRUSR | S_IWUSR);
// 	char	*c = "All my Ducks.";
// 	if (file_descriptor == -1)
// 	{
// 		perror("Failed");
// 		return (1);
// 	}
// 	ft_putendl_fd(c, file_descriptor);
// 	close(file_descriptor);
// 	return (0);
// }
