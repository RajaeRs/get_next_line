/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 17:05:51 by rrasezin          #+#    #+#             */
/*   Updated: 2022/11/04 18:22:23 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*reading;
	int			read_size;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!reading)
		reading = malloc(1 * sizeof(char));
	while (check_new_line(buffer) != 1)
	{
		read_size = read(fd, buffer, BUFFER_SIZE);
		reading = ft_strjoin(reading, buffer);
	}
	buffer = 
}
