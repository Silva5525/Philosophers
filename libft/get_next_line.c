/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:16:56 by wdegraf           #+#    #+#             */
/*   Updated: 2024/02/20 19:47:18 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/// @brief seperates the content of the file struct into a line
/// and saves the rest of the content. The line is returned and the
/// rest of the content is saved in the file struct.
/// @param file struct to handle.
/// @return the line read from the file struct.
static char	*seperate_line(t_struct *file)
{
	char	*line;
	char	*hold;
	int		i;

	i = 0;
	while (file->content[i] != '\n' && file->content[i] != '\0')
		i++;
	if (file->content[i] == '\n')
		i++;
	if (i == 0)
		return (NULL);
	line = (char *)malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	line[i] = '\0';
	ft_memcpy2(line, file->content, i);
	hold = ft_strdup2(file->content + i);
	if (!hold)
	{
		free(line);
		return (NULL);
	}
	free(file->content);
	file->content = hold;
	return (line);
}

/// @brief reads from a file descriptor and stores the content
/// in the file struct. The function returns 0 if an error
/// occurred and 1 if everything went fine. It reads only
/// BUFFER_SIZE bytes at a time.
/// @param fd the file descriptor to read from.
/// @param file the struct to save the content in.
/// @return 1 if everything went fine and 0 if an error occurred.
static int	ft_read(int fd, t_struct *file)
{
	int		ret;
	char	buf[BUFFER_SIZE + 1];
	char	*hold;

	while (!ft_strchr2(file->content, '\n') && !file->swich)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret < 0)
			return (0);
		file->swich = ret != BUFFER_SIZE;
		buf[ret] = '\0';
		hold = ft_strjoin2(file->content, buf);
		if (!hold)
			return (0);
		if (file->content)
			free(file->content);
		file->content = hold;
	}
	return (1);
}

/// @brief frees the content of the file struct and sets the
/// file descriptor to -1 if to_be is 0. If to_be is 1 the 
/// file descriptor is set to fd.
/// @param fd the file descriptor to set and read from.
/// @param to_be the expression to decide what to do.
/// @param file the struct to handle.
/// @return NULL as return value for get_next_line.
char	*handle_file(int fd, int to_be, t_struct *file)
{
	if (!to_be)
	{
		free(file->content);
		file->content = NULL;
		file->swich = 0;
		file->fd = -1;
	}
	else
		file->fd = fd;
	return (NULL);
}

/// @brief reads a line from a file descriptor and returns it
/// as a string. The function returns NULL if there is nothing
/// else to read or an error occurred.
/// @param fd the file descriptor to read from.
/// @return the string read from the file descriptor or NULL.
char	*get_next_line(int fd)
{
	static t_struct	file[1024];
	char			*out;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1024)
		return (NULL);
	if (file[fd].fd)
		handle_file(fd, 1, &file[fd]);
	if (!file[fd].swich && !ft_read(fd, &file[fd]))
		return (handle_file(fd, 0, &file[fd]));
	if (file[fd].swich && file[fd].content[0] == '\0')
		return (handle_file(fd, 0, &file[fd]));
	out = seperate_line(&file[fd]);
	if (!out)
		return (handle_file(fd, 0, &file[fd]));
	return (out);
}
