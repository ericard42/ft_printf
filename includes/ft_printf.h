/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericard <ericard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 12:55:01 by ericard           #+#    #+#             */
/*   Updated: 2020/06/02 11:37:07 by ericard          ###   ########.fr       */
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


t_flags     init_flags()
{
    t_flags     flags;
    flags.dot = 0;
    flags.minus = 0;
    flags.star = 0;
    flags.type = 0;
    flags.width = 0;
    flags.zero = 0;
    return(flags);
}

int     ft_printf(const char *format, ...);
void    ft_putstr(char *str);
void    ft_putchar(char c);
int		ft_atoi(const char *str);

#endif
