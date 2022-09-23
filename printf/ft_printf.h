/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlenna <jlenna@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 19:25:37 by jlenna            #+#    #+#             */
/*   Updated: 2022/06/28 15:50:55 by jlenna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_print_char(char c);
int		ft_flag(va_list args, const char f);
int		ft_printf(const char *s, ...);
void	*ft_memset(void *dest, int c, size_t n);
void	*ft_calloc(size_t n, size_t size);
int		ft_len(int n);
char	*ft_itoa(int n);
void	ft_hex(unsigned long long int n, const char f);
int		ft_count1(unsigned long long n, int len);
int		ft_print_hex(unsigned int n, const char f);
int		ft_print_unsigned(unsigned int n);
int		ft_putstr(char *s);
int		ft_print_str(char *s);
int		ft_printnbr(int n);
int		ft_print_pointer(unsigned long long n);

#endif
