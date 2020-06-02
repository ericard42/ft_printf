/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericard <ericard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 12:55:01 by ericard           #+#    #+#             */
/*   Updated: 2020/06/03 01:13:50 by ericard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct    s_flags
{
    int     type;
    int     width;
    int     minus;
    int     zero;
    int     dot;
    int     star;
}           t_flags;

int     ft_printf(const char *format, ...);
void    ft_putstr(char *str);
void    ft_putchar(char c);
int		ft_atoi(const char *str);
t_flags ft_flags(va_list va, size_t i, const char *format);
void    type(const char *format, int ret, size_t i, t_flags flags);

#endif
