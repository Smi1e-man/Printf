/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_mods.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seshevch <seshevch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 18:51:05 by seshevch          #+#    #+#             */
/*   Updated: 2018/12/30 16:32:10 by seshevch         ###   ########.fr       */
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

void		ft_mod_hsh(char **str, char *s, char type)
{
	char	*s2;

	if (type == 'X')
		s2 = ft_strjoin("0X", str[0]);
	else if (type == 'x')
		s2 = ft_strjoin("0x", str[0]);
	else
		s2 = ft_strjoin(s, str[0]);
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
		ft_mod_hsh(&str[0], "0", type);
	ft_putstr(str[0]);
	if (elem->flg_min == '-')
		ft_put_n_char(' ', elem->width - ft_strlen(str[0]));
}

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
