/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 17:05:51 by rrasezin          #+#    #+#             */
/*   Updated: 2022/11/05 17:14:50 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

static char	*new_line(char	*line)
{
	char	*new;
	int		i;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] && line[i] == '\n')
		i++;
	new = ft_calloc((i + 1), sizeof(char));
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		new[i] = line[i];
		i++;
	}
	if (line[i] && line[i] == '\n')
		new[i++] = '\n';
	if (*new == '\0')
	{
		free (new);
		return (NULL);
	}
	return (new);
}

static char	*save(char *buffer)
{
	char	*rest;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free (buffer);
		return (NULL);
	}
	if (buffer[i] && buffer[i] == '\n')
		i++;
	rest = ft_calloc(ft_strlen(buffer) - i + 1, sizeof(char));
	while (buffer[i] && buffer[i] != '\0')
		rest[j++] = buffer[i++];
	free (buffer);
	return (rest);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*buffer;
	int			read_size;

	read_size = 1;
	if (fd == -1 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!line)
		line = ft_calloc(1, 1);
	buffer = ft_calloc (BUFFER_SIZE + 1, sizeof(char));
	while (!(ft_strchr(buffer, '\n')) && read_size != 0)
	{
		read_size = read(fd, buffer, BUFFER_SIZE);
		if (read_size <= 0)
			break ;
		buffer[read_size] = '\0';
		line = ft_strjoin(line, buffer);
	}
	free (buffer);
	buffer = new_line(line);
	line = save(line);
	return (buffer);
}
