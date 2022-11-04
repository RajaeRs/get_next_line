/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 17:06:51 by rrasezin          #+#    #+#             */
/*   Updated: 2022/11/04 19:47:47 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

char	*get_next_line(int fd);
int		check_new_line(void *buffer);
int		ft_strlen(const char *src);
char	*ft_strjoin(char *first, char *last);
char	*result_return(char	*reading);
char	*save(char	*reading);

#endif

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 50

#endif