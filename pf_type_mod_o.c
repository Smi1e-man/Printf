/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_type_mod_o.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seshevch <seshevch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 12:56:14 by seshevch          #+#    #+#             */
/*   Updated: 2018/12/29 18:21:37 by seshevch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		ft_mod_o_hh(va_list argstr, t_printf *elem)
{
	unsigned char		i;
	char				*str;

	i = (unsigned char)va_arg(argstr, unsigned int);
	str = ft_itoa_base(i, 8);
	elem->precision == 0 && str[0] == '0' ? str[0] = '\0' : 0;
	elem->flg_hsh == '#' && str[0] != '0' ? ft_mod_hsh(&str, "0", '1') : 0;
	if (elem->precision != -1 && elem->precision > ft_strlen(str))
		ft_mod_precision(&str, elem, 1);
	if (elem->width != -1 && elem->width > ft_strlen(str))
	{
		if ((elem->flg_min != '-' && elem->flg_nul != '0') ||
			(elem->flg_min != '-' && elem->flg_nul == '0' &&
			elem->precision != -1))
			ft_put_n_char(' ', elem->width - ft_strlen(str));
		else if (elem->flg_min != '-' && elem->precision == -1 &&
				elem->flg_nul == '0')
			ft_put_n_char('0', elem->width - ft_strlen(str));
		ft_putstr(str);
		if (elem->flg_min == '-')
			ft_put_n_char(' ', elem->width - ft_strlen(str));
	}
	else
		ft_putstr(str);
	free(str);
}

void		ft_mod_o_ll(va_list argstr, t_printf *elem)
{
	unsigned long long		i;
	char					*str;

	i = va_arg(argstr, unsigned long long);
	str = ft_itoa_base(i, 8);
	elem->precision == 0 && str[0] == '0' ? str[0] = '\0' : 0;
	elem->flg_hsh == '#' && str[0] != '0' ? ft_mod_hsh(&str, "0", '1') : 0;
	if (elem->precision != -1 && elem->precision > ft_strlen(str))
		ft_mod_precision(&str, elem, 1);
	if (elem->width != -1 && elem->width > ft_strlen(str))
	{
		if ((elem->flg_min != '-' && elem->flg_nul != '0') ||
			(elem->flg_min != '-' && elem->flg_nul == '0' &&
			elem->precision != -1))
			ft_put_n_char(' ', elem->width - ft_strlen(str));
		else if (elem->flg_min != '-' && elem->precision == -1 &&
				elem->flg_nul == '0')
			ft_put_n_char('0', elem->width - ft_strlen(str));
		ft_putstr(str);
		if (elem->flg_min == '-')
			ft_put_n_char(' ', elem->width - ft_strlen(str));
	}
	else
		ft_putstr(str);
	free(str);
}

void		ft_mod_o_l(va_list argstr, t_printf *elem)
{
	unsigned long		i;
	char				*str;

	i = va_arg(argstr, unsigned long);
	str = ft_itoa_base(i, 8);
	elem->precision == 0 && str[0] == '0' ? str[0] = '\0' : 0;
	elem->flg_hsh == '#' && str[0] != '0' ? ft_mod_hsh(&str, "0", '1') : 0;
	if (elem->precision != -1 && elem->precision > ft_strlen(str))
		ft_mod_precision(&str, elem, 1);
	if (elem->width != -1 && elem->width > ft_strlen(str))
	{
		if ((elem->flg_min != '-' && elem->flg_nul != '0') ||
			(elem->flg_min != '-' && elem->flg_nul == '0' &&
			elem->precision != -1))
			ft_put_n_char(' ', elem->width - ft_strlen(str));
		else if (elem->flg_min != '-' && elem->precision == -1 &&
				elem->flg_nul == '0')
			ft_put_n_char('0', elem->width - ft_strlen(str));
		ft_putstr(str);
		if (elem->flg_min == '-')
			ft_put_n_char(' ', elem->width - ft_strlen(str));
	}
	else
		ft_putstr(str);
	free(str);
}

void		ft_mod_o_h(va_list argstr, t_printf *elem)
{
	unsigned short		i;
	char				*str;

	i = (unsigned short)va_arg(argstr, unsigned int);
	str = ft_itoa_base(i, 8);
	elem->precision == 0 && str[0] == '0' ? str[0] = '\0' : 0;
	elem->flg_hsh == '#' && str[0] != '0' ? ft_mod_hsh(&str, "0", '1') : 0;
	if (elem->precision != -1 && elem->precision > ft_strlen(str))
		ft_mod_precision(&str, elem, 1);
	if (elem->width != -1 && elem->width > ft_strlen(str))
	{
		if ((elem->flg_min != '-' && elem->flg_nul != '0') ||
			(elem->flg_min != '-' && elem->flg_nul == '0' &&
			elem->precision != -1))
			ft_put_n_char(' ', elem->width - ft_strlen(str));
		else if (elem->flg_min != '-' && elem->precision == -1 &&
				elem->flg_nul == '0')
			ft_put_n_char('0', elem->width - ft_strlen(str));
		ft_putstr(str);
		if (elem->flg_min == '-')
			ft_put_n_char(' ', elem->width - ft_strlen(str));
	}
	else
		ft_putstr(str);
	free(str);
}

void		ft_type_o(va_list argstr, t_printf *elem)
{
	unsigned int		i;
	char				*str;

	i = va_arg(argstr, unsigned long long);
	str = ft_itoa_base(i, 8);
	elem->precision == 0 && str[0] == '0' ? str[0] = '\0' : 0;
	elem->flg_hsh == '#' && str[0] != '0' ? ft_mod_hsh(&str, "0", '1') : 0;
	if (elem->precision != -1 && elem->precision > ft_strlen(str))
		ft_mod_precision(&str, elem, 1);
	if (elem->width != -1 && elem->width > ft_strlen(str))
	{
		if ((elem->flg_min != '-' && elem->flg_nul != '0') ||
			(elem->flg_min != '-' && elem->flg_nul == '0' &&
			elem->precision != -1))
			ft_put_n_char(' ', elem->width - ft_strlen(str));
		else if (elem->flg_min != '-' && elem->precision == -1 &&
				elem->flg_nul == '0')
			ft_put_n_char('0', elem->width - ft_strlen(str));
		ft_putstr(str);
		if (elem->flg_min == '-')
			ft_put_n_char(' ', elem->width - ft_strlen(str));
	}
	else
		ft_putstr(str);
	free(str);
}
