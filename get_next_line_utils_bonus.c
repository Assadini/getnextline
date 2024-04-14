/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tassadin <tassadin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 01:50:16 by tassadin          #+#    #+#             */
/*   Updated: 2024/04/14 18:32:55 by tassadin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen_new(char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	return (i);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*t;
	int		i;

	i = 0;
	t = malloc(ft_strlen(src) + 1);
	if (!t)
		return (NULL);
	while (src[i])
	{
		t[i] = src[i];
		i++;
	}
	t[i] = '\0';
	return (t);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new_s;
	int		i;
	int		c;

	i = 0;
	c = 0;
	if (!s1)
		s1 = ft_strdup("");
	new_s = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!new_s)
		return (free(s1), NULL);
	while (s1[i])
		new_s[c++] = s1[i++];
	i = 0;
	while (s2[i])
		new_s[c++] = s2[i++];
	new_s[c] = '\0';
	return (free(s1), new_s);
}

char	*ft_strchr(char *s, int find)
{
	while (s && *s)
	{
		if (*s == (char)find)
			return (s);
		s++;
	}
	return (NULL);
}
