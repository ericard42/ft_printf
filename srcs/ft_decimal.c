/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decimal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericard <ericard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 19:49:43 by ericard           #+#    #+#             */
/*   Updated: 2020/09/06 22:48:14 by ericard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int     ft_decimal(t_flags flags, va_list va)
{
    char    *nbr;
    int     ret;

    nbr = ft_itoa(va_arg(va,int));
    ret = ft_strlen(nbr);
    if (flags.minus == 1)
    {
        if (flags.prec > ret)
            ft_print_zero(flags.prec - ret);
        ft_putstr(nbr, ret);
    }
    if (flags.width > ret)
    {
        if (flags.zero == 1 && flags.dot == 0)
            ft_print_zero(flags.width - ret);
        else
            ft_print_space(flags.width - ret);
    }
    if (flags.minus == 0)
    {
        if (flags.prec > ret)
            ft_print_zero(flags.prec - ret);
        ft_putstr(nbr, ret);
    }
    ret = (flags.prec > ret) ? flags.prec : ret;
    return ((flags.width > ret) ? flags.width : ret);
}