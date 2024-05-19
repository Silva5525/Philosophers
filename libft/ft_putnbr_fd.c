/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 23:49:50 by wdegraf           #+#    #+#             */
/*   Updated: 2023/11/15 16:23:29 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

/// @brief Outputs the integer ’n’ to the given file descriptor.
/// @param n The integer to output.
/// @param fd The file descriptor on which to write.
void	ft_putnbr_fd(int n, int fd)
{
	if (n == 0)
	{
		ft_putchar_fd('0', fd);
		return ;
	}
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	if (n / 10)
		ft_putnbr_fd(n / 10, fd);
	ft_putchar_fd(n % 10 + '0', fd);
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
// 	int c = 54;

// 	ft_putnbr_fd(c, file_descriptor);
// 	close(file_descriptor);
// 	return (0);
// }