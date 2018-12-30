/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_type_mod_d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seshevch <seshevch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/30 14:19:47 by seshevch          #+#    #+#             */
/*   Updated: 2018/12/30 16:56:24 by seshevch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		ft_mod_d_hh(va_list argstr, t_printf *elem)
{
	signed char			i;
	char				*str;

	i = (signed char)va_arg(argstr, signed int);
	str = ft_itoa_base_d(i, 10);
	i < 0 ? i = '-' : 0;
	elem->precision == 0 && str[0] == '0' ? str[0] = '\0' : 0;
	if (elem->precision != -1 && elem->precision > ft_strlen(str))
		ft_mod_precision(&str, elem, 1);
	if (elem->width != -1 && elem->width > ft_strlen(str))
	{
		if ((elem->flg_min != '-' && elem->flg_nul != '0') ||
			(elem->flg_min != '-' && elem->flg_nul == '0' &&
			elem->precision != -1))
			i = (short)ft_flg_d(&str, (int)i, ' ', elem);
		else if (elem->flg_min != '-' && elem->precision == -1 &&
				elem->flg_nul == '0')
			i = (short)ft_flg_d(&str, (int)i, '0', elem);
		i = (short)ft_flg_d(&str, (int)i, -1, elem);
		elem->flg_min == '-' ? ft_flg_d(&str, i, ' ', elem) : 0;
	}
	else
		ft_flg_d(&str, i, -1, elem);
	free(str);
}

void		ft_mod_d_ll(va_list argstr, t_printf *elem)
{
	long long int		i;
	char				*str;

	i = va_arg(argstr, long long int);
	str = ft_itoa_base_d(i, 10);
	i < 0 ? i = '-' : 0;
	elem->precision == 0 && str[0] == '0' ? str[0] = '\0' : 0;
	if (elem->precision != -1 && elem->precision > ft_strlen(str))
		ft_mod_precision(&str, elem, 1);
	if (elem->width != -1 && elem->width > ft_strlen(str))
	{
		if ((elem->flg_min != '-' && elem->flg_nul != '0') ||
			(elem->flg_min != '-' && elem->flg_nul == '0' &&
			elem->precision != -1))
			i = (short)ft_flg_d(&str, (int)i, ' ', elem);
		else if (elem->flg_min != '-' && elem->precision == -1 &&
				elem->flg_nul == '0')
			i = (short)ft_flg_d(&str, (int)i, '0', elem);
		i = (short)ft_flg_d(&str, (int)i, -1, elem);
		elem->flg_min == '-' ? ft_flg_d(&str, i, ' ', elem) : 0;
	}
	else
		ft_flg_d(&str, i, -1, elem);
	free(str);
}

void		ft_mod_d_l(va_list argstr, t_printf *elem)
{
	long int			i;
	char				*str;

	i = va_arg(argstr, long int);
	str = ft_itoa_base_d(i, 10);
	i < 0 ? i = '-' : 0;
	elem->precision == 0 && str[0] == '0' ? str[0] = '\0' : 0;
	if (elem->precision != -1 && elem->precision > ft_strlen(str))
		ft_mod_precision(&str, elem, 1);
	if (elem->width != -1 && elem->width > ft_strlen(str))
	{
		if ((elem->flg_min != '-' && elem->flg_nul != '0') ||
			(elem->flg_min != '-' && elem->flg_nul == '0' &&
			elem->precision != -1))
			i = (short)ft_flg_d(&str, (int)i, ' ', elem);
		else if (elem->flg_min != '-' && elem->precision == -1 &&
				elem->flg_nul == '0')
			i = (short)ft_flg_d(&str, (int)i, '0', elem);
		i = (short)ft_flg_d(&str, (int)i, -1, elem);
		elem->flg_min == '-' ? ft_flg_d(&str, i, ' ', elem) : 0;
	}
	else
		ft_flg_d(&str, i, -1, elem);
	free(str);
}

void		ft_mod_d_h(va_list argstr, t_printf *elem)
{
	short int			i;
	char				*str;

	i = (short int)va_arg(argstr, int);
	str = ft_itoa_base_d(i, 10);
	i < 0 ? i = '-' : 0;
	elem->precision == 0 && str[0] == '0' ? str[0] = '\0' : 0;
	if (elem->precision != -1 && elem->precision > ft_strlen(str))
		ft_mod_precision(&str, elem, 1);
	if (elem->width != -1 && elem->width > ft_strlen(str))
	{
		if ((elem->flg_min != '-' && elem->flg_nul != '0') ||
			(elem->flg_min != '-' && elem->flg_nul == '0' &&
			elem->precision != -1))
			i = (short)ft_flg_d(&str, (int)i, ' ', elem);
		else if (elem->flg_min != '-' && elem->precision == -1 &&
				elem->flg_nul == '0')
			i = (short)ft_flg_d(&str, (int)i, '0', elem);
		i = (short)ft_flg_d(&str, (int)i, -1, elem);
		elem->flg_min == '-' ? ft_flg_d(&str, i, ' ', elem) : 0;
	}
	else
		ft_flg_d(&str, i, -1, elem);
	free(str);
}

void		ft_type_d(va_list argstr, t_printf *elem)
{
	int					i;
	char				*str;

	i = va_arg(argstr, int);
	str = ft_itoa_base_d(i, 10);
	i < 0 ? i = '-' : 0;
	elem->precision == 0 && str[0] == '0' ? str[0] = '\0' : 0;
	if (elem->precision != -1 && elem->precision > ft_strlen(str))
		ft_mod_precision(&str, elem, 1);
	if (elem->width != -1 && elem->width > ft_strlen(str))
	{
		if ((elem->flg_min != '-' && elem->flg_nul != '0') ||
			(elem->flg_min != '-' && elem->flg_nul == '0' &&
			elem->precision != -1))
			i = (short)ft_flg_d(&str, (int)i, ' ', elem);
		else if (elem->flg_min != '-' && elem->precision == -1 &&
				elem->flg_nul == '0')
			i = (short)ft_flg_d(&str, (int)i, '0', elem);
		i = (short)ft_flg_d(&str, (int)i, -1, elem);
		elem->flg_min == '-' ? ft_flg_d(&str, i, ' ', elem) : 0;
	}
	else
		ft_flg_d(&str, i, -1, elem);
	free(str);
}
