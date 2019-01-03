/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seshevch <seshevch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 13:59:22 by seshevch          #+#    #+#             */
/*   Updated: 2019/01/03 17:26:51 by seshevch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PRINTF_H
# define __PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>

/*
**	modul number
*/

# define MDL(a) ((a < 0) ? a * (-1) : a)

/*
**  global param
*/
int	g_out;
/*
**  printf functions
*/
int				ft_printf(const char *restrict str, ...);
int				ft_print_str(const char *restrict str, int count);
void			ft_put_n_char(char c, int n);
/*
**  lib functions
*/
void			ft_putstr(char const *s);
size_t			ft_strlen(const char *s);
void			*ft_memset(void *b, int c, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strnew(size_t size);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strdup(const char *s1);
char			*ft_itoa_base(unsigned long long val, int base);
char			*ft_itoa_base_d(long long val, int base);
void			ft_toupper(char **s);
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

	union		
	{
		ssize_t	i;
		size_t	ui;
	}			type;

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
void			ft_sv_w(const char *restrict str,
							int *count, t_printf *elem, va_list argstr);
void			ft_p(const char *restrict s,
						int *cnt, t_printf *el, va_list as);
void			ft_save_size(const char *restrict str,
							int *count, t_printf *elem);
/*
**  types
*/
void			ft_type_c(va_list argstr, t_printf *elem);
void			ft_type_s(va_list argstr, t_printf *elem);
void			ft_type_p(va_list argstr, t_printf *elem);
void			ft_type_mod_d(va_list argstr, t_printf *elem);
void			ft_type_d(va_list argstr, t_printf *elem);
void			ft_type_mult(va_list argstr, t_printf *elem, char type);
void			ft_type_o(va_list argstr, t_printf *elem);
void			ft_type_u(va_list argstr, t_printf *elem);
void			ft_type_x(va_list argstr, t_printf *elem, char type);
void			ft_type_non(char c, t_printf *elem);
/*
**	mods
*/
void			ft_mod_precision(char **str, t_printf *elem, int check);
void			ft_mod_hsh(char **str, char *s, char type);
int				ft_flg_d(char **str, int i, char prnt, t_printf *elem);
void			ft_path(char **str, t_printf *elem, char prnt, char *sml);
void			ft_mod_width(char **str, t_printf *elem, char type);

#endif
