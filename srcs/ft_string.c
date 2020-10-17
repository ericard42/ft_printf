/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericard <ericard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 23:08:34 by ericard           #+#    #+#             */
/*   Updated: 2020/10/17 18:23:40 by ericard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_s(t_flags flags, va_list va)
{
	int		ret;
	char	*str;

	str = ft_strdup(va_arg(va, char *));
	ret = ft_strlen(str);
	if (flags.dot == 1 && flags.prec < ret && flags.prec >= 0)
		ret = flags.prec;
	if (flags.minus == 1)
		ft_putstr(str, ret);
	if (flags.width > ret)
		ft_print_space(flags.width - ret);
	if (flags.minus == 0)
		ft_putstr(str, ret);
	return ((flags.width > ret) ? flags.width : ret);
}

int		ft_char(t_flags flags, char c)
{
	if (flags.minus == 1)
		ft_putchar(c);
	if (flags.width > 1)
		ft_print_space(flags.width - 1);
	if (flags.minus == 0)
		ft_putchar(c);
	return ((flags.width > 1) ? flags.width : 1);
}

int		ft_percent(t_flags flags)
{
	if (flags.minus == 1)
		ft_putchar('%');
	if (flags.width > 1)
	{
		if (flags.zero == 1)
			ft_print_zero(flags.width - 1);
		else
			ft_print_space(flags.width - 1);
	}
	if (flags.minus == 0)
		ft_putchar('%');
	return ((flags.width > 1) ? flags.width : 1);
}

int		ft_strings(t_flags flags, char c, va_list va)
{
	int		ret;

	ret = 0;
	if (c == 's')
		ret = ft_s(flags, va);
	if (c == 'c')
		ret = ft_char(flags, va_arg(va, int));
	if (c == '%')
		ret = ft_percent(flags);
	return (ret);
}
