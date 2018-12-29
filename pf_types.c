/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_types.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seshevch <seshevch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 15:53:20 by seshevch          #+#    #+#             */
/*   Updated: 2018/12/29 14:49:25 by seshevch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		ft_type_c(va_list argstr, t_printf *elem)
{
	char	c;

	c = va_arg(argstr, int);
	if (elem->width > 1)
	{
		if (elem->flg_min != '-' && elem->flg_nul != '0')
			ft_put_n_char(' ', elem->width - 1);
		else if (elem->flg_min != '-' && elem->flg_nul == '0')
			ft_put_n_char('0', elem->width - 1);
		ft_put_n_char(c, 1);
		if (elem->flg_min == '-')
			ft_put_n_char(' ', elem->width - 1);
	}
	else
		ft_put_n_char(c, 1);
}

void		ft_type_s(va_list argstr, t_printf *elem)
{
	char	*str;
	char	*s1;

	str = va_arg(argstr, char *);
	if (str == NULL)
		str = "(null)";
	if (elem->precision != -1 && elem->precision < ft_strlen(str))
	{
		s1 = ft_strsub(str, 0, elem->precision);
		str = s1;
		free(s1);
	}
	if (elem->width != -1 && elem->width > ft_strlen(str))
	{
		if (elem->flg_min != '-' && elem->flg_nul != '0')
			ft_put_n_char(' ', elem->width - ft_strlen(str));
		else if (elem->flg_min != '-' && elem->flg_nul == '0')
			ft_put_n_char('0', elem->width - ft_strlen(str));
		ft_putstr(str);
		if (elem->flg_min == '-')
			ft_put_n_char(' ', elem->width - ft_strlen(str));
	}
	else
		ft_putstr(str);
}

void		ft_type_p_width(char **str, t_printf *elem)
{
	elem->precision == -1 && elem->flg_nul == '0' ? ft_putstr("0x") : 0;
	if ((elem->flg_min != '-' && elem->flg_nul != '0') ||
		(elem->flg_min != '-' && elem->flg_nul == '0' &&
		elem->precision != -1))
		ft_put_n_char(' ', elem->width - ft_strlen(str[0]) - 2);
	else if (elem->flg_min != '-' && elem->precision == -1 &&
			elem->flg_nul == '0')
		ft_put_n_char('0', elem->width - ft_strlen(str[0]) - 2);
	if ((elem->precision != -1 && elem->flg_nul != '0') ||
		(elem->precision != -1 && elem->flg_nul == '0') ||
		(elem->precision == -1 && elem->flg_nul != '0'))
		ft_putstr("0x");
	ft_putstr(str[0]);
	if (elem->flg_min == '-')
		ft_put_n_char(' ', elem->width - ft_strlen(str[0]) - 2);
}

void		ft_type_p(va_list argstr, t_printf *elem)
{
	unsigned long long	i;
	char				*str;

	i = va_arg(argstr, unsigned long long);
	str = ft_itoa_base(i, 16);
	if (elem->precision != -1 && elem->precision > ft_strlen(str))
		ft_mod_precision(&str, elem, 1);
	if (elem->width != -1 && elem->width > ft_strlen(str))
		ft_type_p_width(&str, elem);
	else
	{
		ft_putstr("0x");
		ft_putstr(str);
	}
	free(str);
}

void		ft_type_non(char c, t_printf *elem)
{
	if (elem->width > 1)
	{
		if (elem->flg_min != '-' && elem->flg_nul != '0')
			ft_put_n_char(' ', elem->width - 1);
		else if (elem->flg_min != '-' && elem->flg_nul == '0')
			ft_put_n_char('0', elem->width - 1);
		ft_put_n_char(c, 1);
		if (elem->flg_min == '-')
			ft_put_n_char(' ', elem->width - 1);
	}
	else
		ft_put_n_char(c, 1);
}
