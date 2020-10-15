/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericard <ericard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 12:55:01 by ericard           #+#    #+#             */
/*   Updated: 2020/10/15 23:13:24 by ericard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct		s_flags
{
	int		prec;
	int		width;
	int		minus;
	int		zero;
	int		dot;
	int		star;
}					t_flags;

int					ft_printf(const char *format, ...);
void				ft_putstr(char *str, int max);
void				ft_putchar(char c);
int					ft_flags(t_flags *fl, int i, const char *f, va_list va);
int					ft_type(t_flags flags, char c, va_list va);
int					ft_strings(t_flags flags, char c, va_list va);
size_t				ft_strlen(const char *str);
char				*ft_strdup(const char *s);
t_flags				init_flags(void);
int					ft_isdigit(int c);
int					flag_list(int c);
int					type_list(int c);
void				ft_print_space(int min);
void				ft_print_zero(int min);
int					ft_decimal(t_flags flags, va_list va);
char				*ft_itoa(int n);
void				*ft_memset(void *s, int c, size_t n);
char				*ft_itoa_base(int base, unsigned long int nbr, char c);
int					ft_pointer(t_flags flags, va_list va);
int					ft_hexa(t_flags flags, va_list va, char c);
int					ft_unsigned(t_flags flags, va_list va);
char				*ft_itoa_u(unsigned int nb);

#endif
