/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 17:06:51 by rrasezin          #+#    #+#             */
/*   Updated: 2022/11/04 18:20:32 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <string.h>
# include <unistd.h>

BUFFER_SIZE = 10;

char	*get_next_line(int fd);
int		check_new_line(char *buffer);
size_t	ft_strlen(const char *src);
char	*ft_strjoin(char *first, char *last);

#endif
