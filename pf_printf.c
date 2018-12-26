/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seshevch <seshevch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 13:53:31 by seshevch          #+#    #+#             */
/*   Updated: 2018/12/26 15:14:54 by seshevch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_check(const char *restrict str, va_list arg, int cnt, t_printf *el)
{
	ft_save_flag(str, &cnt, el);
	ft_save_width(str, &cnt, el, arg);
	ft_save_precision(str, &cnt, el, arg);
	ft_save_size(str, &cnt, el);
	if (str[cnt] == 'c')
		ft_type_c(arg, el);
	if (str[cnt] == 's')
		ft_type_s(arg, el);
	return (cnt);
}

int		ft_print_str(const char *restrict str, int count)
{
	while (str[count] != '\0')
	{
		if (str[count] == '%' && str[count + 1] == '%')
		{
			ft_put_n_char('%', 1);
			count++;
		}
		else if (str[count] == '%')
			return (count + 1);
		else
			ft_put_n_char(str[count], 1);
		count++;
	}
	return (-1);
}

int		ft_printf(const char *restrict str, ...)
{
	va_list		argstr;
	t_printf	*elem;
	int			count;

	g_out = 0;
	count = 0;
	va_start(argstr, str);
	elem = (t_printf*)malloc(sizeof(t_printf));
	while ((count = ft_print_str(str, count)) != -1)
	{
		*elem = (t_printf){0, 0, 0, 0, 0, -1, -1, 0};
		count = ft_check(str, argstr, count, elem);
		count++;
	}
	free(elem);
	va_end(argstr);
	return (g_out);
}
