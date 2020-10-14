/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericard <ericard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 12:06:17 by ericard           #+#    #+#             */
/*   Updated: 2020/10/14 18:17:59 by ericard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int     ft_hexa(t_flags flags, va_list va, char c)
{
    char                *print;
    int                 ret;
    unsigned long int   nbr;

    nbr = va_arg(va, unsigned long int);
    print = ft_itoa_base(16, nbr, c - 23);
    ret = ft_strlen(print);
    if (flags.minus == 1)
    {
        if (flags.prec > ret)
            ft_print_zero(flags.prec - ret);
        ft_putstr(print, ret);
    }
    if (flags.width > ret)
    {
        if (flags.zero == 1 && flags.dot == 0)
            ft_print_zero(flags.width - ret);
        else if (flags.prec > ret)
            ft_print_space(flags.width - flags.prec);
        else
            ft_print_space(flags.width - ret);
    }
    if (flags.minus == 0)
    {
        if (flags.prec > ret)
            ft_print_zero(flags.prec - ret);
        ft_putstr(print, ret);
    }
    if (flags.prec > flags.width)
        flags.width = flags.prec;
    return (flags.width > ret ? flags.width : ret);
}