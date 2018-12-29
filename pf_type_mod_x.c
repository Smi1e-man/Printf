/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_type_mod_x.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seshevch <seshevch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 12:42:10 by seshevch          #+#    #+#             */
/*   Updated: 2018/12/29 18:16:26 by seshevch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		ft_mod_x_hh(va_list argstr, t_printf *elem, char type)
{
	unsigned char	i;
	char			*str;

	i = (unsigned char)va_arg(argstr, unsigned int);
	str = ft_itoa_base(i, 16);
	type == 'X' ? ft_toupper(&str) : 0;
	elem->precision == 0 && str[0] == '0' ? str[0] = '\0' : 0;
	if (elem->precision != -1 && elem->precision > ft_strlen(str))
		ft_mod_precision(&str, elem, 1);
	if (elem->flg_hsh == '#' && elem->precision != 0 &&
		elem->width == -1 && str[1] != '\0')
		ft_mod_hsh(&str, "0", type);
	if (elem->width != -1 && elem->width > ft_strlen(str))
		ft_mod_width(&str, elem, type);
	else
		ft_putstr(str);
	free(str);
}

void		ft_mod_x_ll(va_list argstr, t_printf *elem, char type)
{
	unsigned long long		i;
	char					*str;

	i = va_arg(argstr, unsigned long long);
	str = ft_itoa_base(i, 16);
	type == 'X' ? ft_toupper(&str) : 0;
	elem->precision == 0 && str[0] == '0' ? str[0] = '\0' : 0;
	if (elem->precision != -1 && elem->precision > ft_strlen(str))
		ft_mod_precision(&str, elem, 1);
	if (elem->flg_hsh == '#' && elem->precision != 0 &&
		elem->width == -1 && str[1] != '\0')
		ft_mod_hsh(&str, "0", type);
	if (elem->width != -1 && elem->width > ft_strlen(str))
		ft_mod_width(&str, elem, type);
	else
		ft_putstr(str);
	free(str);
}

void		ft_mod_x_l(va_list argstr, t_printf *elem, char type)
{
	unsigned long	i;
	char			*str;

	i = va_arg(argstr, unsigned long);
	str = ft_itoa_base(i, 16);
	type == 'X' ? ft_toupper(&str) : 0;
	elem->precision == 0 && str[0] == '0' ? str[0] = '\0' : 0;
	if (elem->precision != -1 && elem->precision > ft_strlen(str))
		ft_mod_precision(&str, elem, 1);
	if (elem->flg_hsh == '#' && elem->precision != 0 &&
		elem->width == -1 && str[1] != '\0')
		ft_mod_hsh(&str, "0", type);
	if (elem->width != -1 && elem->width > ft_strlen(str))
		ft_mod_width(&str, elem, type);
	else
		ft_putstr(str);
	free(str);
}

void		ft_mod_x_h(va_list argstr, t_printf *elem, char type)
{
	unsigned short	i;
	char			*str;

	i = (unsigned short)va_arg(argstr, unsigned int);
	str = ft_itoa_base(i, 16);
	type == 'X' ? ft_toupper(&str) : 0;
	elem->precision == 0 && str[0] == '0' ? str[0] = '\0' : 0;
	if (elem->precision != -1 && elem->precision > ft_strlen(str))
		ft_mod_precision(&str, elem, 1);
	if (elem->flg_hsh == '#' && elem->precision != 0 &&
		elem->width == -1 && str[1] != '\0')
		ft_mod_hsh(&str, "0", type);
	if (elem->width != -1 && elem->width > ft_strlen(str))
		ft_mod_width(&str, elem, type);
	else
		ft_putstr(str);
	free(str);
}

void		ft_type_x(va_list argstr, t_printf *elem, char type)
{
	unsigned int	i;
	char			*str;

	i = va_arg(argstr, unsigned int);
	str = ft_itoa_base(i, 16);
	type == 'X' ? ft_toupper(&str) : 0;
	elem->precision == 0 && str[0] == '0' ? str[0] = '\0' : 0;
	if (elem->precision != -1 && elem->precision > ft_strlen(str))
		ft_mod_precision(&str, elem, 1);
	if (elem->flg_hsh == '#' && elem->precision != 0 &&
		elem->width == -1 && str[1] != '\0')
		ft_mod_hsh(&str, "0", type);
	if (elem->width != -1 && elem->width > ft_strlen(str))
		ft_mod_width(&str, elem, type);
	else
		ft_putstr(str);
	free(str);
}
