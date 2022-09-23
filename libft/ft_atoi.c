/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlenna <jlenna@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 19:24:35 by jlenna            #+#    #+#             */
/*   Updated: 2022/06/28 17:48:04 by jlenna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_usl(char c)
{
	int	res;

	res = (c == '\t');
	res = (c == '\n') + res;
	res = (c == '\v') + res;
	res = (c == '\r') + res;
	res = (c == '\f') + res;
	res = (c == ' ') + res;
	return (res);
}

int	ft_atoi(const char	*str)
{
	int					i;
	int					n;
	unsigned long long	u;

	i = 0;
	n = 0;
	u = 0;
	while (ft_usl(str[i]))
		i++;
	if (str[i] == '-')
		n++;
	if ((str[i] == '+') || (str[i] == '-'))
		i++;
	while (ft_isdigit((int)str[i]) == 1)
	{
		u = (u * 10) + (str[i] - '0');
		i++;
		if ((u > 2147483647) && (n != 1))
			return (-1);
		if ((u > 2147483648) && (n == 1))
			return (0);
	}
	if (n == 1)
		u = -u;
	return ((int)u);
}
