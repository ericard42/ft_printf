/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericard <ericard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 13:59:26 by ericard           #+#    #+#             */
/*   Updated: 2020/09/04 00:36:21 by ericard          ###   ########.fr       */
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

t_flags ft_flags(size_t *i, const char *format, va_list va)
{
    t_flags flags;

    flags = init_flags();
    if(format[*i] == '-')
    {
        flags.minus = 1;
        (*i)++;
    }
    if(format[*i] == '0')
    {
        flags.zero = 1;
        (*i)++;
        if(format[*i] == '-')
        {
            flags.minus = 1;
            flags.zero = 0;
            (*i)++;
        }
    }
    while(format[*i] >= '0' && format[*i] <= '9')
    {
        flags.width = 10 * flags.width + (format[*i] - 48);
	    (*i)++;
    }
    if(format[*i] == '*')
    {
        flags.star = 1;
        flags.width = va_arg(va, int);
        (*i)++;
    }
    if(format[*i] == '.')
    {
        flags.dot = 1;
        (*i)++;
        while(format[*i] >= '0' && format[*i] <= '9')
        {
            flags.prec = 10 * flags.prec + (format[*i] - 48);
            (*i)++;
        }
    }
    return(flags);
}