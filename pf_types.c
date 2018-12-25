/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_types.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seshevch <seshevch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 15:53:20 by seshevch          #+#    #+#             */
/*   Updated: 2018/12/25 17:42:39 by seshevch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		ft_type_c(va_list argstr, t_printf *elem)
{
	char	c;

	if (elem->width == -1)
		elem->width = va_arg(argstr, int);
	c = va_arg(argstr, int);
	if (elem->width < 0)
	{
		elem->width *= -1;
		elem->flg_min = '-';
	}
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
	char	*s;
	char	*s1;
	int		i;

	if (elem->width == -1)
		elem->width = va_arg(argstr, int);
	if (elem->precision == -1)
		elem->precision = va_arg(argstr, int);
	if (elem->width < 0)
	{
		elem->width *= -1;
		elem->flg_min = '-';
	}
	if (elem->precision < 0)
		elem->precision *= -1;
	s = va_arg(argstr, char *);
	i = ft_strlen(s);
	if (elem->precision < i)
	{
		s1 = ft_strsub(s, 0, elem->precision);
		s = s1;
		free(s1);
		i = ft_strlen(s);
	}
	if (elem->width > i)
	{
		if (elem->flg_min != '-' && elem->flg_nul != '0')
			ft_put_n_char(' ', elem->width - i);
		else if (elem->flg_min != '-' && elem->flg_nul == '0')
			ft_put_n_char('0', elem->width - i);
		ft_putstr(s);
		if (elem->flg_min == '-')
			ft_put_n_char(' ', elem->width - i);
	}
	else
		ft_putstr(s);
}