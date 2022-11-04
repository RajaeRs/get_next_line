/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 17:05:51 by rrasezin          #+#    #+#             */
/*   Updated: 2022/11/04 20:16:04 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*reading;
	int			read_size;

	if (fd < 0)
		return (NULL);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!reading)
		reading = malloc(1 * sizeof(char));
	while (check_new_line(buffer) != 1)
	{
		read_size = read(fd, buffer, BUFFER_SIZE);
		if (read_size == -1)
		{
			free (buffer);
			free (reading);
			return (NULL);
		}
		if (read_size == 0)
			break ;
		reading = ft_strjoin(reading, buffer);
	}
	buffer = result_return(reading);
	reading = save(reading);
	return (buffer);
}

// #include <stdio.h>

// int	main()
// {
// 	int	fd;

// 	// char	*first;
// 	// char	*last;
// 	// char	*tmp;
// 	// int	i=0;
// 	// int j=0;

// 	// tmp = "hel\nlo";
// 	// last = malloc(6);
// 	// first = malloc(1);
// 	// while (tmp[i])
// 	// 	last[j++] = tmp[i++];
// 	// printf("%s\n", last);
// 	fd = open("test.txt", O_RDONLY);
// 	printf("%s", get_next_line(fd));

// 	// printf("%d\n", ft_strlen("hok"));
// 	// printf("%d\n", check_new_line("hok"));
// 	// first = ft_strjoin(first, last);
// 	// last = result_return(first);
// 	// first = save(first);
// 	// printf("%s", last);
// 	// printf("%s", first);

	
// }
