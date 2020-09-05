/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericard <ericard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 13:59:26 by ericard           #+#    #+#             */
/*   Updated: 2020/09/05 15:52:06 by ericard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags     init_flags()
{
    t_flags     flags;

    flags.minus = 0;
    flags.zero = 0;
    flags.star = 0;
    flags.dot = 0;
    flags.prec = 0;
    flags.width = 0;
    return(flags);
}

void        ft_is_star(va_list va, t_flags *flags)
{
    flags->star = 1;
    flags->width = va_arg(va, int);
    if (flags->width < 0)
    {
        flags->minus = 1;
        flags->width *= -1;
    }
}

size_t      ft_is_dot(t_flags *flags, size_t i, const char *format, va_list va)
{
    flags->dot = 1;
    i++;
    if (format[i] == '*')
    {
        flags->prec = va_arg(va, int);
        i++;
    }
    else
    {
        while (ft_isdigit(format[i]))
        {
            flags->prec = (flags->prec *10) + (format[i] - 48);
            i++;
        }
    }
    return (i);
}

int         ft_flags(t_flags *flags, size_t i, const char *format, va_list va)
{
    while (ft_isdigit(format[i]) || flag_list(format[i]))
    {
        if (format[i] == '0' && flags->minus == 0 && flags->width == 0)
            flags->zero = 1;
        if (format[i] == '.')
            i = ft_is_dot(flags, i, format, va);
        if (format[i] == '-')
        {
            flags->minus = 1;
            flags->zero = 0;
        }
        if (format[i] == '*')
            ft_is_star(va, flags);
        if (ft_isdigit(format[i]))
            flags->width = (flags->width * 10) + (format[i] - 48);
        if (type_list(format[i]))
            break;
        i++;
    }
    return(i);
}