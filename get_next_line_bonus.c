/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tassadin <tassadin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 01:47:26 by tassadin          #+#    #+#             */
/*   Updated: 2024/04/14 18:29:46 by tassadin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_read_add(int fd, char *save)
{
	char	*buff;
	int		nb;

	buff = malloc(sizeof(char) * ((size_t)BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	while (!ft_strchr(save, '\n'))
	{
		nb = read(fd, buff, BUFFER_SIZE);
		if (nb == -1)
			return (free(buff), free(save), NULL);
		if (nb == 0)
			break ;
		buff[nb] = '\0';
		save = ft_strjoin(save, buff);
	}
	free(buff);
	return (save);
}

char	*ft_next_line(char *save)
{
	int		i;
	char	*s;

	i = 0;
	if (!save[i])
		return (NULL);
	i = ft_strlen_new(save);
	if (save[i] == '\n')
		i++;
	s = (char *)malloc(sizeof(char) * (i + 1));
	if (!s)
		return (NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		s[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
	{
		s[i] = save[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	*ft_clean(char *save)
{
	int		i;
	int		c;
	char	*s;

	i = ft_strlen_new(save);
	if (!save[i] || !save[i + 1])
		return (free(save), NULL);
	s = (char *)malloc(sizeof(char) * (ft_strlen(save) - i));
	if (!s)
		return (NULL);
	i++;
	c = 0;
	while (save[i])
		s[c++] = save[i++];
	s[c] = '\0';
	free(save);
	return (s);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*save[FOPEN_MAX];

	if (fd < 0 || fd > FOPEN_MAX)
		return (NULL);
	save[fd] = ft_read_add(fd, save[fd]);
	if (!save[fd])
		return (NULL);
	line = ft_next_line(save[fd]);
	save[fd] = ft_clean(save[fd]);
	return (line);
}
