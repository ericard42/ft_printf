/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericard <ericard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 22:58:51 by ericard           #+#    #+#             */
/*   Updated: 2020/10/22 15:26:27 by ericard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_hexa_print(t_flags flags, char *print, int ret)
{
	if (flags.prec > ret)
		ft_print_zero(flags.prec - ret);
	ft_putstr(print, ret);
}

int		ft_hexa(t_flags flags, va_list va, char c)
{
	char				*print;
	int					ret;
	unsigned long int	nbr;

	nbr = va_arg(va, unsigned long int);
	print = ft_itoa_base(16, nbr, c - 23);
	ret = ft_strlen(print);
	if (flags.minus == 1)
		ft_hexa_print(flags, print, ret);
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
		ft_hexa_print(flags, print, ret);
	if (flags.prec > flags.width)
		flags.width = flags.prec;
	free (print);
	return (flags.width > ret ? flags.width : ret);
}
