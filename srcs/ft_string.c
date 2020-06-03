/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericard <ericard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 16:55:34 by ericard           #+#    #+#             */
/*   Updated: 2020/06/03 19:22:16 by ericard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int     ft_s(t_flags flags, va_list va)
{
    int     ret;
    char    *print;

    ret = 0;
    if (flags.zero == 1)
        flags.star = 1;
    print = ft_strdup(va_arg(va, char *));
    ret = ft_strlen(print);
    if (flags.width > ret)
    {
        flags.width -= ret;
        if (flags.minus != 1)
        {
            while (flags.width--)
                ft_putchar(' ');
        }
    }
    ft_putstr(print);
    return (ret);
}

int     ft_char(t_flags flags, va_list va)
{
    int     ret;

    ret = 0;
    if (flags.star == 1)
        flags.width = va_arg(va, int);
    if (flags.zero == 1)
        flags.star = 1;
    ret = 1;
    if (flags.width > ret)
    {
        flags.width -= ret;
        if (flags.minus != 1)
        {
            while (flags.width--)
                ft_putchar(' ');
        }
    }
    ft_putchar(va_arg(va, int));
    return (ret);
}

int     ft_strings(t_flags flags, const char *format, size_t i, va_list va)
{
    int     ret;

    ret = 0;
    if (format[i] == 's')
        ret = ft_s(flags, va);
    if (format[i] == 'c')
        ret = ft_char(flags, va);
    if (format[i] == '%')
    {
        ft_putchar('%');
        ret = 1;
    }
    return (ret);
}