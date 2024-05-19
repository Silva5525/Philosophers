/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:17:46 by wdegraf           #+#    #+#             */
/*   Updated: 2024/05/10 15:56:09 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

# include <string.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

/// @brief s_struct is a struct to save the content of a file
/// @param fd the file descriptor
/// @param content the content of the file 
/// @param swich is a swich to check if the file is empty
typedef struct s_struct
{
	int				fd;
	char			*content;
	int				swich;
}					t_struct;

char	*get_next_line(int fd);
size_t	ft_strlen(const char *str);
char	*ft_strjoin2(char const *s1, char const *s2);
char	*ft_strdup2(const char *str);
char	*ft_strchr2(const char *str, int c);
void	*ft_memcpy2(void *dst, const void *src, size_t len);

// char	*ft_strjoin(char const *s1, char const *s2);
// char	*ft_strdup(const char *str);
// char	*ft_strchr(const char *str, int c);
// void	*ft_memcpy(void *dst, const void *src, size_t len);

#endif
