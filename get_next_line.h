/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tassadin <tassadin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 01:49:03 by tassadin          #+#    #+#             */
/*   Updated: 2024/03/03 01:49:08 by tassadin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
int		ft_strlen_new(char *s);
int		ft_strlen(char *s);
char	*ft_strdup(char *src);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *s, int find);

#endif
