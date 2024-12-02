/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouissy <mrouissy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 10:44:34 by mrouissy          #+#    #+#             */
/*   Updated: 2024/12/02 14:52:09 by mrouissy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*free_and_return(char **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
	return (NULL);
}

static char	*ft_new_line(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i])
	{
		if (str[i] == '\n')
			return (&str[i]);
		i++;
	}
	return (NULL);
}

static char	*ft_read_line(int fd, char *buffer)
{
	char	*temp_buffer;
	ssize_t	bytes_read;

	temp_buffer = malloc(BUFFER_SIZE + 1);
	if (!temp_buffer)
		return (NULL);
	while (!buffer || !ft_new_line(buffer))
	{
		bytes_read = read(fd, temp_buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free_and_return(&temp_buffer);
			free_and_return(&buffer);
			return (NULL);
		}
		if (bytes_read == 0)
			break ;
		temp_buffer[bytes_read] = '\0';
		buffer = ft_strjoin(buffer, temp_buffer);
		if (!buffer)
			return (free_and_return(&temp_buffer), NULL);
	}
	free(temp_buffer);
	return (buffer);
}

char	*gget_line(char **buffer, char *new)
{
	char	*temp;
	char	*new_buffer;

	temp = ft_strdup(*buffer);
	if (!temp)
		return (free_and_return(buffer));
	temp[new - *buffer + 1] = '\0';
	new_buffer = ft_strdup(new + 1);
	if (!new_buffer)
	{
		free(temp);
		return (free_and_return(buffer));
	}
	free(*buffer);
	*buffer = new_buffer;
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*buffer[1024];
	char		*line;
	char		*new_line_pos;

	buffer[fd] = ft_read_line(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	new_line_pos = ft_new_line(buffer[fd]);
	if (new_line_pos)
		line = gget_line(&*buffer, new_line_pos);
	else
	{
		line = ft_strdup(buffer[fd]);
		free_and_return(&buffer[fd]);
	}
	if (!line || line[0] == '\0')
		return (free_and_return(&line));
	return (line);
}
// #include <fcntl.h>
// #include <stdio.h>
// int	main()
// {
// 	int		fd;
// 	int		fd2;
// 	char	*line;
// 	char	*line2;

// 	fd = open("test.txt", O_RDONLY);
// 	fd2 = open("test2.txt", O_RDONLY);
// 	printf("F1-->line 1:%s\n",get_next_line(fd));
// 	printf("F2-->line 1:%s\n\n",get_next_line(fd2));
// 	printf("F1-->line 2:%s\n",get_next_line(fd));
// 	printf("F2-->line 2:%s\n\n",get_next_line(fd2));
// 	printf("F1-->line 3:%s\n",get_next_line(fd));
// 	printf("F2-->line 3:%s\n\n",get_next_line(fd2));
// 	return (0);
// }
