/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlenna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 18:33:20 by jlenna            #+#    #+#             */
/*   Updated: 2022/01/06 18:13:36 by jlenna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_print_str(char *s)
{
	int	len;

	if (s == NULL)
		len = ft_putstr("(null)");
	else
		len = ft_putstr(s);
	return (len);
}

int	ft_printnbr(int n)
{
	int		len;
	char	*nb;

	nb = ft_itoa(n);
	len = ft_print_str(nb);
	free(nb);
	return (len);
}
