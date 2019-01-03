/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_type_mods.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seshevch <seshevch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/30 16:28:47 by seshevch          #+#    #+#             */
/*   Updated: 2019/01/03 17:16:01 by seshevch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		ft_type_mod_d(va_list argstr, t_printf *elem)
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

void		ft_type_mult(va_list argstr, t_printf *elem, char type)
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
