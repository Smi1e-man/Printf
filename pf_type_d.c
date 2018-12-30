/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_type_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seshevch <seshevch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 16:25:58 by seshevch          #+#    #+#             */
/*   Updated: 2018/12/30 16:03:53 by seshevch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		ft_path(char **str, t_printf *elem, char prnt, char *sml)
{
	if (prnt == '0')
	{
		elem->width -= 1;
		ft_mod_precision(&str[0], elem, 2);
	}
	ft_mod_hsh(&str[0], sml, '1');
}

int			ft_flg_d(char **str, int i, char prnt, t_printf *elem)
{
	if (i == '-')
	{
		ft_path(&str[0], elem, prnt, "-");
		i = 2;
	}
	else if (elem->flg_sum == '+' && str[0][0] != '-')
	{
		ft_path(&str[0], elem, prnt, "+");
		elem->flg_sum = -1;
	}
	else if (elem->flg_spc == ' ')
	{
		ft_mod_hsh(&str[0], " ", '1');
		elem->flg_spc = -1;
	}
	else if (prnt == '0')
		ft_mod_precision(&str[0], elem, 2);
	if (prnt != -1 && prnt != '0')
		ft_put_n_char(prnt, elem->width - ft_strlen(str[0]));
	else if (prnt == -1)
		ft_putstr(str[0]);
	return (i);
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

void		ft_type_mods_d(va_list argstr, t_printf *elem)
{
	if (elem->size == 1)
		ft_mod_d_hh(argstr, elem);
	else if (elem->size == 2)
		ft_mod_d_ll(argstr, elem);
	else if (elem->size == 'l')
		ft_mod_d_l(argstr, elem);
	else if (elem->size == 'h')
		ft_mod_d_h(argstr, elem);
	else
		ft_type_d(argstr, elem);
}
