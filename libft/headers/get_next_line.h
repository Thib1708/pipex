/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 12:11:19 by tgiraudo          #+#    #+#             */
/*   Updated: 2022/11/25 21:36:24 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 256
# endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

int	get_next_line(int fd, char **line);
char	*ft_read_buf(char *save, int fd);
char	*ft_line(char *save);
char	*ft_next_line(char *save);
char	*ft_free(char *save, char *buffer);
int		new_line(const char *s);

#endif
