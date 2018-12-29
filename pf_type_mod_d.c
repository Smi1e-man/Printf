/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_type_mod_d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seshevch <seshevch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 16:25:58 by seshevch          #+#    #+#             */
/*   Updated: 2018/12/29 20:05:51 by seshevch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		ft_flg(char **str, int *i, char prnt, t_printf *elem)
{
	if (i[0] < 0)
	{
		// printf("lol\n");
		if (prnt == '0')
		{
			elem->width -= 1;
			ft_mod_precision(&str[0], elem, 2);
		}
		ft_mod_hsh(&str[0], "-", '1');
		i[0] = 1; 
	}
	else if (elem->flg_sum == '+' && str[0][0] != '-')
	{
		if (prnt == '0')
		{
			elem->width -= 1;
			ft_mod_precision(&str[0], elem, 2);
		}
		ft_mod_hsh(&str[0], "+", '1');
		elem->flg_sum = -1;
	}
	else if (elem->flg_spc == ' ')
	{
		ft_mod_hsh(&str[0], " ", '1');
		elem->flg_spc = -1;
	}
	else if (prnt == '0')
	{
		ft_mod_precision(&str[0], elem, 2);
	}	
	if (prnt != -1 && prnt != '0')
	{
		ft_put_n_char(prnt, elem->width - ft_strlen(str[0]));
	}
	else if (prnt == -1)
	{
		// printf("%s\n", str[0]);
		ft_putstr(str[0]);
	}
}

void		ft_type_d(va_list argstr, t_printf *elem)
{
	int					i;
	char				*str;

	i = va_arg(argstr, int);
	// printf("%d\n", i);
	str = ft_itoa_base_d(i, 10);
	// printf("%s\n", str);
	elem->precision == 0 && str[0] == '0' ? str[0] = '\0' : 0;
	if (elem->precision != -1 && elem->precision > ft_strlen(str))
		ft_mod_precision(&str, elem, 1);
	if (elem->width != -1 && elem->width > ft_strlen(str))
	{
		if ((elem->flg_min != '-' && elem->flg_nul != '0') ||
			(elem->flg_min != '-' && elem->flg_nul == '0' &&
			elem->precision != -1))
			{
				// printf("lol\n");
				ft_flg(&str, &i, ' ', elem);
			}
		else if (elem->flg_min != '-' && elem->precision == -1 &&
				elem->flg_nul == '0')
		{
			// printf("lol\n");
			ft_flg(&str, &i, '0', elem);
		}
		// printf("lol\n");
		ft_flg(&str, &i, -1, elem);
		if (elem->flg_min == '-')
			ft_flg(&str, &i, ' ', elem);
	}
	else if (elem->flg_spc == ' ' && elem->width <= ft_strlen(str))
	{
		// printf("lol\n");
		ft_mod_hsh(&str, " ", '1');
		ft_putstr(str);
	}
	else
	{
		// printf("lol\n");
		ft_flg(&str, &i, -1, elem);
	}
	free(str);
}