/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_types.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seshevch <seshevch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 15:53:20 by seshevch          #+#    #+#             */
/*   Updated: 2018/12/26 19:34:24 by seshevch         ###   ########.fr       */
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
	char	*s;
	char	*s1;

	s = va_arg(argstr, char *);
	if (s == NULL)
		s = ft_strdup("(null)");
	if (elem->precision != -1 && elem->precision < ft_strlen(s))
	{
		s1 = ft_strsub(s, 0, elem->precision);
		s = s1;
		free(s1);
	}
	if (elem->width != -1 && elem->width > ft_strlen(s))
	{
		if (elem->flg_min != '-' && elem->flg_nul != '0')
			ft_put_n_char(' ', elem->width - ft_strlen(s));
		else if (elem->flg_min != '-' && elem->flg_nul == '0')
			ft_put_n_char('0', elem->width - ft_strlen(s));
		ft_putstr(s);
		if (elem->flg_min == '-')
			ft_put_n_char(' ', elem->width - ft_strlen(s));
	}
	else
		ft_putstr(s);
}

void		ft_type_p(va_list argstr, t_printf *el)
{
	unsigned long long	i;
	char				*str;
	char				*s1;

	i = va_arg(argstr, unsigned long long);
	str = ft_itoa_base(i, 16);
	if (elem->precision != -1 && elem->precision > ft_strlen(str))
	{
		s1 = ft_strjoin(ft_memset(ft_strnew(elem->precision - ft_strlen(str)),
						'0', elem->precision - ft_strlen(str)), str);
		str = s1;
		free(s1);
	}
	if (elem->width != -1 && elem->width > ft_strlen(str))
	{
		if ((elem->precision == -1 && elem->flg_nul == '0'))
			ft_putstr("0x");
		if ((elem->flg_min != '-' && elem->flg_nul != '0') ||
			(elem->flg_min != '-' && elem->flg_nul == '0' && elem->precision != -1))
			ft_put_n_char(' ', elem->width - ft_strlen(str) - 2);
		else if (elem->flg_min != '-' && elem->precision == -1 && elem->flg_nul == '0')
			ft_put_n_char('0', elem->width - ft_strlen(str) - 2);
		if ((elem->precision != -1 && elem->flg_nul != '0') ||
			(elem->precision != -1 && elem->flg_nul == '0') ||
			(elem->precision == -1 && elem->flg_nul != '0'))
			ft_putstr("0x");
		ft_putstr(str);
		if (elem->flg_min == '-')
			ft_put_n_char(' ', elem->width - ft_strlen(str) - 2);
	}
	else
	{
		ft_putstr("0x");
		ft_putstr(str);
	}
}

void		ft_type_o(va_list argstr, t_printf *elem)
{
	unsigned long long	i;
	char				*str;
	char				*s1;

	i = va_arg(argstr, unsigned long long);
	str = ft_itoa_base(i, 8);
	if (elem->precision != -1 && elem->precision > ft_strlen(str))
	{
		s1 = ft_strjoin(ft_memset(ft_strnew(elem->precision - ft_strlen(str)),
						'0', elem->precision - ft_strlen(str)), str);
		str = s1;
		free(s1);
	}
	if (elem->width != -1 && elem->width > ft_strlen(str))
	{
		if ((elem->flg_min != '-' && elem->flg_nul != '0') ||
			(elem->flg_min != '-' && elem->flg_nul == '0' && elem->precision != -1))
			ft_put_n_char(' ', elem->width - ft_strlen(str));
		else if (elem->flg_min != '-' && elem->precision == -1 && elem->flg_nul == '0')
			ft_put_n_char('0', elem->width - ft_strlen(str));
		ft_putstr(str);
		if (elem->flg_min == '-')
			ft_put_n_char(' ', elem->width - ft_strlen(str));
	}
	else
		ft_putstr(str);
}
