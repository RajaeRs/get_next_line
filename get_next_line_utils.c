/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 17:06:17 by rrasezin          #+#    #+#             */
/*   Updated: 2022/11/04 18:27:10 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *src)
{
	int	i;

	i = 0;
	while (src[i] != 0)
	{
		i++;
	}
	return (i);
}

int	check_new_line(char *buffer)
{
	while (buffer)
	{
		if (*buffer == '\n')
			return (1);
		buffer++;
	}
	return (0);
}

char	*ft_strjoin(char *first, char *last)
{
	int		size;
	char	*result;
	int		i;
	int		j;

	i = 0;
	j = 0;
	size = ft_strlen(first) + ft_strlen(last) + 1;
	result = malloc(size);
	while (first)
		result[i++] = first[j++];
	j = 0;
	while (last)
		result[i++] = last[j++];
	i++;
	result[i] = '\0';
	free (first);
	return (result);
}

char	*result_return(char	*reading)
{
	char	*result;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (reading[j] != '\n' && reading[j])
		result[i++] = reading[j++];
		
}
// void	*ft_calloc(size_t count, size_t size)
// {
// 	void	*result;
// 	size_t	t;

// 	t = count * size;
// 	result = malloc(t);
// 	if (!result)
// 		return (NULL);
// 	while (t + 1)
// 	{
// 		(char)result[t] = "\0";
// 		t--;
// 	}
// 	return (result);
// }
