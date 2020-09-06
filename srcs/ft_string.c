/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericard <ericard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 16:55:34 by ericard           #+#    #+#             */
/*   Updated: 2020/09/06 20:43:53 by ericard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int     ft_s(t_flags flags, va_list va)
{
    int     ret;
    char    *str;

    str = ft_strdup(va_arg(va, char *));
    ret = ft_strlen(str);
    if (flags.dot == 1 && flags.prec < ret)
        ret = flags.prec;
    if (flags.minus == 1)
        ft_putstr(str, ret);
    if (flags.width > ret)
        ft_print_space(flags.width - ret);
    if (flags.minus == 0)
        ft_putstr(str, ret);
    return ((flags.width > ret) ? flags.width : ret);
}

int     ft_char(t_flags flags, va_list va)
{
    int     ret;

    ret = 1;
    if (flags.minus == 1)
        ft_putchar(va_arg(va, int));
    if (flags.width > ret)
        ft_print_space(flags.width - ret);
    if (flags.minus == 0)
        ft_putchar(va_arg(va, int));
    return ((flags.width > ret) ? flags.width : ret);
}

int     ft_strings(t_flags flags, char c, va_list va)
{
    int     ret;

    ret = 0;
    if (c == 's')
        ret = ft_s(flags, va);
    if (c == 'c')
        ret = ft_char(flags, va);
    if (c == '%')
    {
        ft_putchar('%');
        ret = 1;
    }
    return (ret);
}