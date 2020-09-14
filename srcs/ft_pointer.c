/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericard <ericard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 16:56:09 by ericard           #+#    #+#             */
/*   Updated: 2020/09/14 14:33:54 by ericard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int     pointer_null(t_flags flags, char *print)
{
    if (flags.minus == 1)
        ft_putstr(print, 5);
    if (flags.width > 5)
        ft_print_space(flags.width - 5);
    if (flags.minus == 0)
        ft_putstr(print, 5);
    return (flags.width > 5 ? flags.width : 5);
}

int     ft_pointer(t_flags flags, va_list va)
{
    char                *print;
    int                 ret;
    unsigned long int   nbr;

    nbr = va_arg(va, unsigned long int);
    if (!nbr)
        return (pointer_null(flags, ft_strdup("(nil)")));
    print = ft_itoa_base(16, nbr, 'a');
    ret = ft_strlen(print) + 2;
    if (flags.minus == 1)
    {       
        ft_putstr("0x", 2);
        ft_putstr(print, ret - 2);
    }
    if (flags.width > ret)
        ft_print_space(flags.width - ret);
    if (flags.minus == 0)
    {
        ft_putstr("0x", 2);
        ft_putstr(print, ret - 2);
    }
    return (flags.width > ret ? flags.width : ret);
}