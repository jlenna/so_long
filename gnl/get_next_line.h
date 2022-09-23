/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlenna <jlenna@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 16:03:09 by jlenna            #+#    #+#             */
/*   Updated: 2022/06/28 18:18:02 by jlenna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include "../so_long.h"

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_cut(char *rem);
char	*ft_read(int fd, char *str, char *r);
char	*ft_get_line(char *rem);
char	*ft_end(char *str);

#endif
