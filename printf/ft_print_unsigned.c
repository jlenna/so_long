/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlenna <jlenna@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 17:10:02 by jlenna            #+#    #+#             */
/*   Updated: 2022/01/07 15:47:26 by jlenna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_unsigned(unsigned int n)
{
	int		len;

	len = 0;
	if (n > 9)
		len += ft_print_unsigned(n / 10);
	len += ft_print_char(n % 10 + '0');
	return (len);
}
