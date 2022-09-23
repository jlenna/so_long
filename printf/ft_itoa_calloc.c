/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_calloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlenna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 19:18:24 by jlenna            #+#    #+#             */
/*   Updated: 2022/01/06 17:32:24 by jlenna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_memset(void *dest, int c, size_t n)
{
	unsigned char	*dest1;
	unsigned char	c1;

	c1 = (unsigned char)c;
	dest1 = (unsigned char *)dest;
	while (n != 0)
	{
		*dest1++ = c1;
		n--;
	}
	return (dest);
}

void	*ft_calloc(size_t n, size_t size)
{
	char	*a;
	size_t	k;

	k = n * size;
	a = malloc(k);
	if (!a)
		return (NULL);
	ft_memset(a, 0, k);
	return (a);
}

int	ft_len(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		i++;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		i;
	char	*s;
	long	n1;

	n1 = n;
	i = ft_len(n);
	s = (char *)ft_calloc(sizeof(char) * (i + 1), 1);
	if (!s)
		return (NULL);
	if (n1 == 0)
		s[0] = '0';
	if (n1 < 0)
	{
		s[0] = '-';
		n1 = n1 * (-1);
	}
	i--;
	while (n1)
	{
		s[i] = n1 % 10 + '0';
		n1 = n1 / 10;
		i--;
	}
	return (s);
}
