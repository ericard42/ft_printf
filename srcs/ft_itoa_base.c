/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericard <ericard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 23:03:42 by ericard           #+#    #+#             */
/*   Updated: 2021/01/11 13:36:52 by ericard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	calculate_char(int mod, char c)
{
	char	ret;

	if (mod > 36)
		return (0);
	ret = '0';
	while (mod)
	{
		ret++;
		if (ret == ':')
			ret = c;
		mod--;
	}
	return (ret);
}

int		nbrlen(int base, unsigned long int nbr)
{
	int		len;

	len = 0;
	if (nbr >= 0 && nbr < 10)
		return (1);
	while (nbr)
	{
		nbr /= base;
		len++;
	}
	return (len);
}

char	*ft_itoa_base(int base, unsigned long int nbr, char c)
{
	int		len;
	char	*str;
	int		mod;

	len = nbrlen(base, nbr);
	if (!(str = malloc(sizeof(char) * (len))))
		return (NULL);
	str[len] = '\0';
	len--;
	if (nbr == 0)
		*str = '0';
	while (nbr)
	{
		mod = nbr % base;
		str[len] = calculate_char(mod, c);
		nbr /= base;
		len--;
	}
	return (str);
}
