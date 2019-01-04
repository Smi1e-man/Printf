/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seshevch <seshevch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 13:53:31 by seshevch          #+#    #+#             */
/*   Updated: 2019/01/04 17:12:54 by seshevch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_type_mod_d(va_list argstr, t_printf *elem)
{
	if (elem->size == 1)
		elem->type.i = (signed char)va_arg(argstr, signed int);
	else if (elem->size == 2)
		elem->type.i = va_arg(argstr, long long int);
	else if (elem->size == 'l')
		elem->type.i = va_arg(argstr, long int);
	else if (elem->size == 'h')
		elem->type.i = (short int)va_arg(argstr, int);
	else
		elem->type.i = va_arg(argstr, int);
	ft_type_d(argstr, elem);
}

void	ft_type_mult(va_list argstr, t_printf *elem, char type)
{
	if (type == 'U')
		elem->type.ui = va_arg(argstr, unsigned long);
	else if (elem->size == 1)
		elem->type.ui = (unsigned char)va_arg(argstr, unsigned int);
	else if (elem->size == 2)
		elem->type.ui = va_arg(argstr, unsigned long long);
	else if (elem->size == 'l')
		elem->type.ui = va_arg(argstr, unsigned long);
	else if (elem->size == 'h')
		elem->type.ui = (unsigned short)va_arg(argstr, unsigned int);
	else
		elem->type.ui = va_arg(argstr, unsigned int);
	if (type == 'u' || type == 'U')
		ft_type_u(argstr, elem);
	else if (type == 'o')
		ft_type_o(argstr, elem);
	else if (type == 'x' || type == 'X')
		ft_type_x(argstr, elem, type);
}

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
	else if (str[cnt] == 'd' || str[cnt] == 'i')
		ft_type_mod_d(arg, el);
	else if (str[cnt] == 'o' || str[cnt] == 'x' || str[cnt] == 'X' ||
			str[cnt] == 'u' || str[cnt] == 'U')
		ft_type_mult(arg, el, str[cnt]);
	else if (str[cnt] == 'f' || str[cnt] == 'F')
		ft_type_f(arg, el);
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
		else if (str[count] == '%' && str[count + 1] == '0' &&
				str[count + 2] == '\0')
		{
			return (-1);
		}
		else if (str[count] == '%' && str[count + 1] != '\0')
			return (count + 1);
		else if (str[count] != '%')
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
