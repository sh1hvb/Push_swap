/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchihab <mchihab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 17:51:41 by mchihab           #+#    #+#             */
/*   Updated: 2024/02/07 17:51:42 by mchihab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	find_new_line(char **buffer, char **line)
{
	char	*newline_ptr;
	int		index;
	char	*temp_buffer;

	newline_ptr = *buffer;
	index = 0;
	while (newline_ptr[index] != '\n')
	{
		if (!newline_ptr[index])
			return (0);
		index++;
	}
	temp_buffer = &newline_ptr[index];
	*temp_buffer = '\0';
	*line = *buffer;
	*buffer = ft_strdup(temp_buffer + 1);
	return (1);
}

static void	append_to_buffer(char **destination, char *source)
{
	char	*temp;

	temp = *destination;
	if (!temp)
		*destination = ft_strdup(source);
	else
	{
		*destination = ft_strjoin(temp, source);
		free(temp);
		temp = NULL;
	}
}

static int	exit_gnl(char **line)
{
	*line = NULL;
	return (0);
}

int	get_next_line(const int fd, char **line)
{
	static char	*buffer[1024];
	char		heap[BUFF_SIZE + 1];
	int			ret;

	if (!line || fd < 0 || fd >= 1024 || read(fd, buffer[fd], 0) < 0)
		return (-1);
	ret = read(fd, heap, BUFF_SIZE);
	while (ret > 0)
	{
		heap[ret] = '\0';
		append_to_buffer(&buffer[fd], heap);
		if (find_new_line(&buffer[fd], line))
			return (1);
		ret = read(fd, heap, BUFF_SIZE);
	}
	if (!buffer[fd] || buffer[fd][0] == '\0')
		return (exit_gnl(line));
	if (buffer[fd])
		if (find_new_line(&(buffer[fd]), line))
			return (1);
	*line = ft_strdup(buffer[fd]);
	free(buffer[fd]);
	buffer[fd] = NULL;
	return (1);
}
