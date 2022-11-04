/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 17:06:17 by rrasezin          #+#    #+#             */
/*   Updated: 2022/11/04 20:06:15 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	check_new_line(void *buffer)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)buffer;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
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
	while (first[i])
		result[i++] = first[j++];
	j = 0;
	while (last[j])
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
	while (reading[j] && reading[j] != '\n')
		j++;
	if (reading[j] == '\n')
		j++;
	result = malloc (j + 1);
	j = 0;
	while (reading[j] != '\n' && reading[j])
		result[i++] = reading[j++];
	if (reading[j] == '\n')
		result[j] = '\n';
	return (result);
}

char	*save(char	*reading)
{
	char	*result;
	int		i;
	int		j;
	int		size;

	i = 0;
	j = 0;
	size = ft_strlen(reading) + 1;
	while (reading[j] && reading[j] != '\n')
		j++;
	if (reading[j] == '\n')
		j++;
	result = malloc((size - j + 1) * sizeof(char));
	while (reading[j])
		result[i++] = reading[j++];
	if (reading[j] == '\0')
		result[i] = '\0';
	free(reading);
	return (result);
}
