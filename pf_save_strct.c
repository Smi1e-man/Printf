/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_save_strct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seshevch <seshevch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 12:29:53 by seshevch          #+#    #+#             */
/*   Updated: 2018/12/28 18:21:15 by seshevch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_save_flag(const char *restrict str, int *count, t_printf *elem)
{
	while (str[count[0]] == '#' || str[count[0]] == '0' ||
		str[count[0]] == '-' || str[count[0]] == '+' || str[count[0]] == ' ')
	{
		if (str[count[0]] == '#')
			elem->flg_hsh = '#';
		else if (str[count[0]] == '0')
			elem->flg_nul = '0';
		else if (str[count[0]] == '-')
			elem->flg_min = '-';
		else if (str[count[0]] == '+')
			elem->flg_sum = '+';
		else if (str[count[0]] == ' ')
			elem->flg_spc = ' ';
		count[0]++;
	}
}

void	ft_save_width(const char *restrict str, int *count, t_printf *elem, va_list argstr)
{
	int		numb;

	if (str[count[0]] == '*')
	{
		elem->width = va_arg(argstr, int);
		if (elem->width < 0)
		{
			elem->width *= -1;
			elem->flg_min = '-';
		}
		count[0]++;
	}
	else if (str[count[0]] >= '0' && str[count[0]] <= '9')
	{
		numb = 0;
		while (str[count[0]] >= '0' && str[count[0]] <= '9')
		{
			numb *= 10;
			numb = numb + (str[count[0]] - '0');
			count[0]++;
		}
		elem->width = numb;
	}
}

void	ft_save_precision(const char *restrict str, int *count, t_printf *elem, va_list argstr)
{
	int		numb;

	if (str[count[0]] == '.')
	{
		count[0]++;
		if (str[count[0]] == '*')
		{
			elem->precision = va_arg(argstr, int);
			if (elem->precision < 0)
			{
				elem->precision *= -1;
				elem->flg_min = '-';
			}
			count[0]++;
		}
		else
		{
			numb = 0;
			while (str[count[0]] >= '0' && str[count[0]] <= '9')
			{
				numb *= 10;
				numb = numb + (str[count[0]] - '0');
				count[0]++;
			}
			elem->precision = numb;
		}
	}
}

void	ft_save_size(const char *restrict str, int *count, t_printf *elem)
{
	if (str[count[0]] == 'h' || str[count[0]] == 'l' || str[count[0]] == 'L')
	{
		if (str[count[0]] == 'h' && str[count[0] + 1] == 'h')
		{
			elem->size = 1;
			count[0]++;
		}
		else if (str[count[0]] == 'l' && str[count[0] + 1] == 'l')
		{
			elem->size = 2;
			count[0]++;
		}
		else if (str[count[0]] == 'h')
			elem->size = 'h';
		else if (str[count[0]] == 'l')
			elem->size = 'l';
		else if (str[count[0]] == 'L')
			elem->size = 'L';
		count[0]++;
	}
}
