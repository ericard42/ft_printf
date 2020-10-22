/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decimal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericard <ericard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 22:08:12 by ericard           #+#    #+#             */
/*   Updated: 2020/10/22 15:37:44 by ericard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		dec_positive(t_flags flags, int ret, char *nbr)
{
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

void	print_neg(t_flags flags, int ret, char *nbr)
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

int		dec_negative(t_flags flags, int ret, char *nbr)
{
	if (nbr[0] == '-' && flags.prec > ret)
		flags.prec++;
	if (flags.minus == 1)
		print_neg(flags, ret, nbr);
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
		print_neg(flags, ret, nbr);
	return ((flags.prec > ret) ? flags.prec : ret);
}

int		dec_zero(t_flags flags, int ret, char *nbr)
{
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

int		ft_decimal(t_flags flags, va_list va)
{
	int		ret;
	int		dec;
	char	*nbr;

	dec = va_arg(va, int);
	nbr = ft_itoa(dec);
	ret = ft_strlen(nbr);
	if (dec < 0)
		ret = dec_negative(flags, ret, nbr);
	if (dec > 0)
		ret = dec_positive(flags, ret, nbr);
	if (dec == 0)
		ret = dec_zero(flags, ret, nbr);
	ret = (flags.prec > ret) ? flags.prec : ret;
	free (nbr);
	return ((flags.width > ret) ? flags.width : ret);
}
