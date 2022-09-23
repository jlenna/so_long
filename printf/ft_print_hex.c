/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlenna <jlenna@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 18:13:54 by jlenna            #+#    #+#             */
/*   Updated: 2022/06/28 15:51:29 by jlenna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_hex(unsigned long long int n, const char f)
{
	if (n >= 16)
		ft_hex(n / 16, f);
	n = n % 16;
	if (n <= 9)
		ft_print_char(n + '0');
	else
	{
		if (f == 'x')
			ft_print_char(n - 10 + 'a');
		if (f == 'X')
			ft_print_char(n - 10 + 'A');
	}
}

int	ft_count1(unsigned long long n, int len)
{
	if (n == 0)
	{
		len = len + 1;
		return (len);
	}
	while (n != 0)
	{
		n = n / 16;
		len++;
	}
	return (len);
}

int	ft_print_hex(unsigned int n, const char f)
{
	int	len;

	len = 0;
	len = ft_count1(n, len);
	ft_hex(n, f);
	return (len);
}

int	ft_print_pointer(unsigned long long n)
{
	int	len;

	len = 2;
	write(1, "0x", 2);
	len = ft_count1(n, len);
	ft_hex(n, 'x');
	return (len);
}
