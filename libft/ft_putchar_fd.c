/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 21:29:52 by wdegraf           #+#    #+#             */
/*   Updated: 2023/11/09 16:50:06 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

/// @brief Outputs the character ’c’ to the given file descriptor.
/// @param c The character to output.
/// @param fd The file descriptor on which to write
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

// #include <stdio.h>
// #include <fcntl.h>

// int	main(void)
// {
// 	int file_descriptor = open("test.txt", O_WRONLY 
// 	| O_CREAT, S_IRUSR | S_IWUSR);

// 	if (file_descriptor == -1)
// 	{
// 		perror("Failed");
// 		return (1);
// 	}
// 	char c = 'A';

// 	ft_putchar_fd(c, file_descriptor);
// 	close(file_descriptor);
// 	return (0);
// }