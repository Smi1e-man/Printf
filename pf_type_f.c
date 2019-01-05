/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_type_f.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seshevch <seshevch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 16:36:59 by seshevch          #+#    #+#             */
/*   Updated: 2019/01/05 15:23:14 by seshevch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char		*ft_okr(long double val, long long i, char *s1)
{
	int		len;

	val /= 0.1;
	i = val;
	len = ft_strlen(s1) - 1;
	if (i >= 5)
	{
		if (s1[len] != '9')
			s1[len] += 1;
		else
		{
			while (s1[len] == '9')
			{
				s1[len] = '0';
				if (s1[len - 1] != '9' && s1[len - 1] != '.')
					s1[len - 1] += 1;
				if (s1[len - 1] == '.')
					s1[len - 2] != '9' ? s1[len - 2] += 1 : len--;
				len--;
			}
		}
	}
	return (s1);
}

void		ft_type_f_prcsn(long double val, char **str, t_printf *elem, long i)
{
	char				*s1;
	char				*s2;

	str[0] = ft_itoa_base_d(i, 10);
	val -= (long)val;
	elem->precision == -1 ? elem->precision = 6 : 0;
	if (elem->precision > 0)
	{
		s1 = ft_strjoin(str[0], ".");
		free(str[0]);
		while (elem->precision-- != 0)
		{
			val /= 0.1;
			i = val;
			str[0] = ft_itoa_base_d(i, 10);
			s2 = ft_strjoin(s1, str[0]);
			free(str[0]);
			free(s1);
			s1 = s2;
			val -= i;
		}
		str[0] = ft_okr(val, i, s1);
	}
	else if (elem->precision == 0)
		str[0] = ft_okr(val, i, str[0]);
}

void		ft_type_f(va_list argstr, t_printf *elem)
{
	char				*str;
	long double			val;
	long				i;

	val = elem->size == 'L' ? va_arg(argstr, long double) :
							va_arg(argstr, double);
	i = val;
	ft_type_f_prcsn(MDL(val), &str, elem, i);
	elem->type.val = (double)val;
	elem->type.t_bits.sign ? elem->type.i = '-' : 0;
	if (elem->width != -1 && elem->width > ft_strlen(str))
	{
		if ((elem->flg_min != '-' && elem->flg_nul != '0') ||
			(elem->flg_min != '-' && elem->flg_nul == '0' &&
			elem->precision != -1))
			elem->type.i = (short)ft_flg_d(&str, (int)elem->type.i, ' ', elem);
		else if (elem->flg_min != '-' && elem->precision == -1 &&
				elem->flg_nul == '0')
			elem->type.i = (short)ft_flg_d(&str, (int)elem->type.i, '0', elem);
		elem->type.i = (short)ft_flg_d(&str, (int)elem->type.i, -1, elem);
		elem->flg_min == '-' ? ft_flg_d(&str, elem->type.i, ' ', elem) : 0;
	}
	else
		ft_flg_d(&str, elem->type.i, -1, elem);
	free(str);
}
