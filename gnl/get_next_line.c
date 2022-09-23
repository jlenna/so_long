/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlenna <jlenna@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 16:04:15 by jlenna            #+#    #+#             */
/*   Updated: 2022/06/28 18:16:15 by jlenna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_cut(char *rem)
{
	int		i;
	int		a;
	char	*newrem;

	i = 0;
	a = 0;
	while (rem[i] != '\n' && rem[i] != '\0')
		i++;
	if (rem[i] == '\0')
	{
		free(rem);
		return (NULL);
	}
	newrem = malloc((ft_strlen(rem) - i + 1) * sizeof(char));
	if (!newrem)
		return (NULL);
	i++;
	while (rem[i])
		newrem[a++] = rem[i++];
	newrem[a] = '\0';
	free(rem);
	return (newrem);
}

char	*ft_get_line(char *rem)
{
	int		i;
	int		a;
	char	*s;

	i = 0;
	a = 0;
	if (!rem[i])
		return (NULL);
	while (rem[i] != '\n' && rem[i])
		i++;
	s = malloc(sizeof(char) * (i + 2));
	if (!s)
		return (NULL);
	while (rem[a] != '\n' && rem[a])
	{
		s[a] = rem[a];
		a++;
	}
	if (rem[a] == '\n')
	{
		s[a] = rem[a];
		a++;
	}
	s[a] = '\0';
	return (s);
}

char	*ft_read(int fd, char *str, char *r)
{
	int	s;

	s = 1;
	while (s != 0 && !ft_end(r))
	{
		s = read(fd, str, BUFFER_SIZE);
		if (s == -1)
		{
			free (str);
			return (NULL);
		}
		str[s] = '\0';
		r = ft_strjoin(r, str);
	}
	free(str);
	return (r);
}

char	*get_next_line(int fd)
{
	char		*str;
	static char	*rem;
	char		*s;

	if ((fd < 0) || (BUFFER_SIZE < 0))
		return (NULL);
	str = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!str)
		return (NULL);
	rem = ft_read(fd, str, rem);
	if (!rem)
		return (NULL);
	s = ft_get_line(rem);
	rem = ft_cut(rem);
	return (s);
}
