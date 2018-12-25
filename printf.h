/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seshevch <seshevch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 13:59:22 by seshevch          #+#    #+#             */
/*   Updated: 2018/12/25 17:02:47 by seshevch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PRINTF_H
# define __PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>

/*
**  global param
*/
int	g_out;
/*
**  printf functions
*/
int				ft_printf(const char *restrict format, ...);
int				ft_print_str(const char *restrict str, int count);
void			ft_put_n_char(char c, int n);
/*
**  lib functions
*/
void			ft_putstr(char const *s);
size_t			ft_strlen(const char *s);
/*
**  struct
*/
typedef struct	s_list
{
	char		flg_hsh;
	char		flg_nul;
	char		flg_min;
	char		flg_sum;
	char		flg_spc;

	int			width;
	int			precision;
	int			size;
}				t_printf;
/*
**  function with struct
*/
int				ft_check(const char *restrict str, va_list argstr,
							int count, t_printf *elem);
/*
**  save in struct
*/
void			ft_save_flag(const char *restrict str,
							int *count, t_printf *elem);
void			ft_save_width(const char *restrict str,
							int *count, t_printf *elem);
void			ft_save_precision(const char *restrict str,
							int *count, t_printf *elem);
void			ft_save_size(const char *restrict str,
							int *count, t_printf *elem);
/*
**  types
*/
void			ft_type_c(va_list argstr, t_printf *elem);
void		ft_type_s(va_list argstr, t_printf *elem);

#endif
