/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlenna <jlenna@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 14:22:39 by jlenna            #+#    #+#             */
/*   Updated: 2022/06/28 17:48:28 by jlenna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int			a;	

	a = 0;
	if (src == dest || n == 0)
		return (dest);
	if (src < dest)
	{
		a = (int)n - 1;
		while (a >= 0)
		{
			*(char *)(dest + a) = *(char *)(src + a);
			a--;
		}
	}
	else
	{
		while (a < (int)n)
		{
			*(char *)(dest + a) = *(char *)(src + a);
			a++;
		}
	}
	return (dest);
}
