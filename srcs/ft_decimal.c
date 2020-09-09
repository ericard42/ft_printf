/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decimal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericard <ericard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 19:49:43 by ericard           #+#    #+#             */
/*   Updated: 2020/09/09 21:34:20 by ericard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int     dec_positive(t_flags flags, int dec)
{
    char    *nbr;
    int     ret;

    nbr = ft_itoa(dec);
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
        else if (flags.prec > ret)
            ft_print_space(flags.width - flags.prec);
        else
            ft_print_space(flags.width - ret);
    }
    if (flags.minus == 0)
    {
        if (flags.prec > ret)
            ft_print_zero(flags.prec - ret);
        ft_putstr(nbr, ret);
    }
    return (ret);
}

int     dec_negative(t_flags flags, int dec)
{
    char    *nbr;
    int     ret;

    nbr = ft_itoa(dec);
    ret = ft_strlen(nbr);
    if (nbr[0] == '-' && flags.prec > ret)
        flags.prec++;
    if (flags.minus == 1)
    {
        if (nbr[0] == '-')
        {
            ft_putchar('-');
            nbr++;
        }
        if (flags.prec > ret)
            ft_print_zero(flags.prec - ret);
        ft_putstr(nbr, ret);
    }
    if (flags.width > ret)
    {
        if (flags.zero == 1 && (flags.dot == 0 || flags.prec < 0))
        {
            if (nbr[0] == '-')
            {
                ft_putchar('-');
                nbr++;
            }
            ft_print_zero(flags.width - ret);
        }
        else if (flags.prec > ret)
            ft_print_space(flags.width - flags.prec);
        else
            ft_print_space(flags.width - ret);
    }
    if (flags.minus == 0)
    {
        if (nbr[0] == '-')
        {
            ft_putchar('-');
            nbr++;
        }
        if (flags.prec > ret)
            ft_print_zero(flags.prec - ret);
        ft_putstr(nbr, ret);
    }
    return ((flags.prec > ret) ? flags.prec : ret);
}

int     dec_zero(t_flags flags, int dec)
{
    char    *nbr;
    int     ret;

    nbr = ft_itoa(dec);
    ret = ft_strlen(nbr);
    if (flags.dot == 1 && flags.prec == 0)
        ret = 0;
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
        else if (flags.prec > ret)
            ft_print_space(flags.width - flags.prec);
        else
            ft_print_space(flags.width - ret);
    }
    if (flags.minus == 0)
    {
        if (flags.prec > ret)
            ft_print_zero(flags.prec - ret);
        ft_putstr(nbr, ret);
    }
    return (ret);
}

int     ft_decimal(t_flags flags, va_list va)
{
    int     ret;
    int     dec;

    dec = va_arg(va, int);
    if (dec < 0)
        ret = dec_negative(flags, dec);
    if (dec > 0)
       ret = dec_positive(flags, dec);
    if (dec == 0)
        ret = dec_zero(flags, dec);
    ret = (flags.prec > ret) ? flags.prec : ret;
    return ((flags.width > ret) ? flags.width : ret);
}