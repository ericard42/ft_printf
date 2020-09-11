/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericard <ericard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 16:56:09 by ericard           #+#    #+#             */
/*   Updated: 2020/09/11 23:47:54 by ericard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int     ft_pointer(t_flags flags, va_list va)
{
    char    *print;
    int     ret;

    if (flags.dot)
        flags.dot = 1;
    print = ft_itoa_base(16, va_arg(va, unsigned long int), 'a');
    ret = ft_strlen(print) + 2;
    ft_putstr("0x", 2);
    ft_putstr(print, ret - 2);
    return (ret);
}