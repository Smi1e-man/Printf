/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_type_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seshevch <seshevch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 18:51:05 by seshevch          #+#    #+#             */
/*   Updated: 2018/12/28 19:49:40 by seshevch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		ft_mod_precision(char **str, t_printf *elem, int check)
{
	char	*s1;
	char	*s2;

	if (check == 1)
	{
		s2 = ft_memset(ft_strnew(elem->precision - ft_strlen(str[0])),
						'0', elem->precision - ft_strlen(str[0]));
		s1 = ft_strjoin(s2, str[0]);
		free(s2);
		free(str[0]);
		str[0] = s1;
		free(s1);
	}
	else
	{
		if (elem->flg_hsh == '#' && elem->precision != 0)
			s2 = ft_memset(ft_strnew(elem->width - ft_strlen(str[0]) - 2),
							'0', elem->width - ft_strlen(str[0]) - 2);
		else
			s2 = ft_memset(ft_strnew(elem->width - ft_strlen(str[0])),
							'0', elem->width - ft_strlen(str[0]));
		s1 = ft_strjoin(s2, str[0]);
		free(str[0]);
		str[0] = s1;
		free(s2);
	}
}

void		ft_mod_hsh(char **str, t_printf *elem, char type)
{
	char	*s2;

	if (type == 'X')
		s2 = ft_strjoin("0X", str[0]);
	else
		s2 = ft_strjoin("0x", str[0]);
	free(str[0]);
	str[0] = s2;
}

void		ft_mod_width(char **str, t_printf *elem, char type)
{
	if ((elem->flg_min != '-' && elem->flg_nul != '0') ||
		(elem->flg_min != '-' && elem->flg_nul == '0' &&
		elem->precision != -1))
	{
		elem->flg_hsh == '#' ? elem->width -= 2 : 0;
		ft_put_n_char(' ', elem->width - ft_strlen(str[0]));
	}
	else if (elem->flg_min != '-' && elem->precision == -1 &&
			elem->flg_nul == '0')
		ft_mod_precision(&str[0], elem, 2);
	if (elem->flg_hsh == '#' && elem->precision != 0)
		ft_mod_hsh(&str[0], elem, type);
	ft_putstr(str[0]);
	if (elem->flg_min == '-')
		ft_put_n_char(' ', elem->width - ft_strlen(str[0]));
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
		ft_mod_hsh(&str, elem, type);
	if (elem->width != -1 && elem->width > ft_strlen(str))
		ft_mod_width(&str, elem, type);
	else
		ft_putstr(str);
	free(str);
}