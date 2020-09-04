/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericard <ericard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 12:55:01 by ericard           #+#    #+#             */
/*   Updated: 2020/09/04 14:15:08 by ericard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct    s_flags
{
    int     prec;
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
int     ft_flags(t_flags *flags, size_t i, const char *format, va_list va);
int     ft_type(const char *format, size_t *i, va_list va);
int     ft_strings(const char *format, size_t i, va_list va);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *s);
t_flags init_flags();
int		ft_isdigit(int c);
int     flag_list(int c);
int     type_list(int c);

#endif
