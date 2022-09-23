/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlenna <jlenna@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 16:57:19 by jlenna            #+#    #+#             */
/*   Updated: 2022/06/28 18:17:26 by jlenna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_end(char *str)
{
	int	a;

	a = 0;
	if (!str)
		return (0);
	while (str[a] != 0)
	{
		if (str[a] == '\n')
			return ((char *)str + a);
		a++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int			i;
	int			j;
	char		*s;

	i = -1;
	j = 0;
	if (!s1)
	{
		s1 = malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	if (!s2)
		return (NULL);
	s = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!s)
		return (NULL);
	if (s1)
		while (s1[++i])
			s[i] = s1[i];
	while (s2[j])
		s[i++] = s2[j++];
	s[i] = '\0';
	free(s1);
	return (s);
}
