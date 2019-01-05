/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_types_two.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seshevch <seshevch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 16:47:06 by seshevch          #+#    #+#             */
/*   Updated: 2019/01/05 16:59:24 by seshevch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

// void		ft_type_d(va_list argstr, t_printf *elem)
// {
// 	char				*str;

// 	str = ft_itoa_base_d(elem->type.i, 10);
// 	elem->type.i < 0 ? elem->type.i = '-' : 0;
// 	elem->precision == 0 && str[0] == '0' ? str[0] = '\0' : 0;
// 	if (elem->precision != -1 && elem->precision > ft_strlen(str))
// 		ft_mod_precision(&str, elem, 1);
// 	if (elem->width != -1 && elem->width > ft_strlen(str))
// 	{
// 		// printf("%d\n", elem->precision);
// 		if ((elem->flg_min != '-' && elem->flg_nul != '0') ||
// 			(elem->flg_min != '-' && elem->flg_nul == '0' &&
// 			elem->precision != -1))
// 			elem->type.i = (short)ft_flg_d(&str, (int)elem->type.i, ' ', elem);
// 		else if (elem->flg_min != '-' && elem->precision == -1 &&
// 				elem->flg_nul == '0')
// 			{
// 				printf("lol\n");
// 				elem->type.i = (short)ft_flg_d(&str, (int)elem->type.i, '0', elem);
// 			}
// 		elem->type.i = (short)ft_flg_d(&str, (int)elem->type.i, -1, elem);
// 		elem->flg_min == '-' ? ft_flg_d(&str, elem->type.i, ' ', elem) : 0;
// 	}
// 	else
// 		// printf("%c\n", elem->type.i);
// 		// printf("%d\n", elem->width);
// 		ft_flg_d(&str, elem->type.i, -1, elem);
// 	free(str);
// }

void		ft_type_o(va_list argstr, t_printf *elem)
{
	char				*str;

	str = ft_itoa_base(elem->type.ui, 8);
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

void		ft_type_u(va_list argstr, t_printf *elem)
{
	char				*str;

	str = ft_itoa_base(elem->type.ui, 10);
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

void		ft_type_x(va_list argstr, t_printf *elem, char type)
{
	char			*str;

	str = ft_itoa_base(elem->type.ui, 16);
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

void		ft_type_d(va_list argstr, t_printf *elem)
{
	char	*str;

	str = ft_itoa_base_d(elem->type.i, 10);
	elem->type.i < 0 ? elem->type.i = '-' : 0;
	// elem->precision == 0 && str[0] == '0' ? str[0] = '\0' : 0;
	if (elem->precision != -1 && elem->precision > ft_strlen(str))
		ft_mod_precision(&str, elem, 1);
	else if (elem->precision == -1 && elem->flg_nul != '0')
	{
		if (elem->type.i < 0)
			ft_mod_hsh(&str, "-", '1');
		else if (elem->flg_sum == '+')
			ft_mod_hsh(&str, "+", '1');
	}
	if (elem->width > ft_strlen(str))
	{
		// if (elem->flg_min == '-')
		// 	str + ' '(width - len);// строка уже со знаком
		// else if (elem->flg_nul == '0')
		// 	'0'(width - len) + str; // строке нужно добавить знак
		// else
		// 	' '(width - len) + str;// строка уже со знаком
	}
	ft_putstr(str);
}