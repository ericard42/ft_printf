/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericard <ericard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 23:10:42 by ericard           #+#    #+#             */
/*   Updated: 2021/01/11 14:38:29 by ericard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	u_positive(t_flags flags, int ret, char *nbr)
{
	if (flags.minus == 1)
	{
		if (flags.prec > ret)
			ft_print_zero(flags.prec - ret);
		ft_putstr(nbr, ret);
	}
	if (flags.width > ret)
	{
		if (flags.zero == 1 && (flags.dot == 0 || flags.prec < 0))
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

static int	u_zero(t_flags flags, int ret, char *nbr)
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
		if (flags.zero == 1 && (flags.prec < 0 || flags.dot == 0))
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

int			ft_unsigned(t_flags flags, va_list va)
{
	int				ret;
	unsigned int	u;
	char			*nbr;

	u = va_arg(va, unsigned int);
	nbr = ft_itoa_u(u);
	ret = ft_strlen(nbr);
	if (u > 0)
		ret = u_positive(flags, ret, nbr);
	if (u == 0)
		ret = u_zero(flags, ret, nbr);
	ret = (flags.prec > ret) ? flags.prec : ret;
	free(nbr);
	return ((flags.width > ret) ? flags.width : ret);
}
