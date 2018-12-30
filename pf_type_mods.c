/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_type_mods.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seshevch <seshevch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/30 16:28:47 by seshevch          #+#    #+#             */
/*   Updated: 2018/12/30 16:54:15 by seshevch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		ft_type_mods_x(va_list argstr, t_printf *elem, char type)
{
	if (elem->size == 1)
		ft_mod_x_hh(argstr, elem, type);
	else if (elem->size == 2)
		ft_mod_x_ll(argstr, elem, type);
	else if (elem->size == 'l')
		ft_mod_x_l(argstr, elem, type);
	else if (elem->size == 'h')
		ft_mod_x_h(argstr, elem, type);
	else
		ft_type_x(argstr, elem, type);
}

void		ft_type_mods_o(va_list argstr, t_printf *elem)
{
	if (elem->size == 1)
		ft_mod_o_hh(argstr, elem);
	else if (elem->size == 2)
		ft_mod_o_ll(argstr, elem);
	else if (elem->size == 'l')
		ft_mod_o_l(argstr, elem);
	else if (elem->size == 'h')
		ft_mod_o_h(argstr, elem);
	else
		ft_type_o(argstr, elem);
}

void		ft_type_mods_d(va_list argstr, t_printf *elem)
{
	if (elem->size == 1)
		ft_mod_d_hh(argstr, elem);
	else if (elem->size == 2)
		ft_mod_d_ll(argstr, elem);
	else if (elem->size == 'l')
		ft_mod_d_l(argstr, elem);
	else if (elem->size == 'h')
		ft_mod_d_h(argstr, elem);
	else
		ft_type_d(argstr, elem);
}

void		ft_type_mods_u(va_list argstr, t_printf *elem)
{
	if (elem->size == 1)
		ft_mod_u_hh(argstr, elem);
	else if (elem->size == 2)
		ft_mod_u_ll(argstr, elem);
	else if (elem->size == 'l')
		ft_mod_u_l(argstr, elem);
	else if (elem->size == 'h')
		ft_mod_u_h(argstr, elem);
	else
		ft_type_u(argstr, elem);
}
