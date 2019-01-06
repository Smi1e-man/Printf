/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_type_f.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seshevch <seshevch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 16:36:59 by seshevch          #+#    #+#             */
/*   Updated: 2019/01/06 19:58:21 by seshevch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char		*ft_round(long double val, long long i, char *s1)
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
		str[0] = ft_round(val, i, s1);
	}
	else if (elem->precision == 0)
		str[0] = ft_round(val, i, str[0]);
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
	if (elem->flg_nul != '0' || elem->flg_min == '-' ||
		elem->width <= (int)ft_strlen(str) ||
		(elem->width > (int)ft_strlen(str) && elem->precision != -1))
		ft_mod_sign(&str, elem, '+');
	if (elem->width != -1 && elem->width > ft_strlen(str))
		ft_mod_width_d(&str, elem);
	else if (elem->flg_spc == ' ' && elem->type.i >= 0 && elem->flg_sum != '+')
		ft_mod_hsh(&str, " ", '1');
	ft_putstr(str);
	free(str);
}
