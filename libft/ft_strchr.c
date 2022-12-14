/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlenna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 17:44:27 by jlenna            #+#    #+#             */
/*   Updated: 2021/11/14 13:11:34 by jlenna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	if (c > 127)
		c = c % 128;
	while (*str != '\0')
	{
		if (*str == c)
			return ((char *)str);
		else
			str++;
	}
	if ((*str == '\0') && (c == '\0'))
		return ((char *)str);
	return (NULL);
}
