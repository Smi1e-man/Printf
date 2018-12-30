/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seshevch <seshevch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 13:53:31 by seshevch          #+#    #+#             */
/*   Updated: 2018/12/30 16:50:58 by seshevch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_check(const char *restrict str, va_list arg, int cnt, t_printf *el)
{
	ft_save_flag(str, &cnt, el);
	ft_sv_w(str, &cnt, el, arg);
	ft_p(str, &cnt, el, arg);
	ft_save_size(str, &cnt, el);
	if (str[cnt] == 'c')
		ft_type_c(arg, el);
	else if (str[cnt] == 's')
		ft_type_s(arg, el);
	else if (str[cnt] == 'p')
		ft_type_p(arg, el);
	else if (str[cnt] == 'o')
		ft_type_mods_o(arg, el);
	else if (str[cnt] == 'x' || str[cnt] == 'X')
		ft_type_mods_x(arg, el, str[cnt]);
	else if (str[cnt] == 'd' || str[cnt] == 'i')
		ft_type_mods_d(arg, el);
	else if (str[cnt] == 'u')
		ft_type_mods_u(arg, el);
	else if (str[cnt] == 'U')
		ft_mod_u_l(arg, el);
	else
		ft_type_non(str[cnt], el);
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
		*elem = (t_printf){-1, -1, -1, -1, -1, -1, -1, -1};
		count = ft_check(str, argstr, count, elem);
		count++;
	}
	free(elem);
	va_end(argstr);
	return (g_out);
}
