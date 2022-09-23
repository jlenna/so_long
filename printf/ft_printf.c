/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlenna <jlenna@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 18:01:46 by jlenna            #+#    #+#             */
/*   Updated: 2022/01/07 15:40:24 by jlenna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_flag(va_list args, const char f)
{
	int	len;

	len = 0;
	if (f == 'c')
		len = ft_print_char(va_arg(args, int));
	else if (f == 's')
		len = ft_print_str(va_arg(args, char *));
	else if (f == 'p')
		len = ft_print_pointer(va_arg(args, unsigned long long));
	else if (f == 'd' || f == 'i')
		len = ft_printnbr(va_arg(args, int));
	else if (f == 'u')
		len = ft_print_unsigned(va_arg(args, unsigned int));
	else if (f == 'x' || f == 'X')
		len = ft_print_hex(va_arg(args, unsigned int), f);
	else if (f == '%')
	{
		write(1, "%", 1);
		len = 1;
	}
	return (len);
}

int	ft_printf(const char *s, ...)
{
	int		len;
	va_list	args;
	int		i;

	va_start(args, s);
	i = 0;
	len = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			len = len + ft_flag(args, s[i + 1]);
			i = i + 2;
		}
		else
		{
			len = len + ft_print_char(s[i]);
			i++;
		}
	}
	va_end(args);
	return (len);
}
