/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seshevch <seshevch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 13:59:22 by seshevch          #+#    #+#             */
/*   Updated: 2019/01/19 19:38:05 by seshevch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PRINTF_H
# define __PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

/*
** color types
*/

# define EOC "\033[0m"

# define RED "\033[1;31m"
# define GRE "\033[32m"
# define BLU "\033[34m"
# define YEL "\033[1;33m"
# define VIO "\033[35m"
# define BLA "\033[30m"
# define WHI "\033[1;37m"

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
char			*ft_strdup(const char *s1);
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

	int			sign;

	union
	{
		ssize_t	i;
		size_t	ui;
		double	val;

		struct	s_bits
		{
			unsigned int	mantissa : 32;
			unsigned int	exponent : 31;
			unsigned int	sign : 1;

		}		t_bits;

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
void			ft_type_mod_d(va_list argstr, t_printf *elem, char type);
void			ft_type_mult(va_list argstr, t_printf *elem, char type);
void			ft_type_c(va_list argstr, t_printf *elem);
void			ft_type_s(va_list argstr, t_printf *elem);
void			ft_type_p(va_list argstr, t_printf *elem);
void			ft_type_d(t_printf *elem);
void			ft_type_o(t_printf *elem);
void			ft_type_u(t_printf *elem);
void			ft_type_x(t_printf *elem, char type);
void			ft_type_f(va_list argstr, t_printf *elem);
void			ft_type_non(char c, t_printf *elem);
/*
**	mods
*/
void			ft_mod_mem_join(char **str, int numb, char smv, int check);
void			ft_mod_hsh(char **str, char *s, char type);
int				ft_flg_d(char **str, int i, char prnt, t_printf *elem);
void			ft_path(char **str, t_printf *elem, char prnt, char *sml);
void			ft_mod_width_x(char **str, t_printf *elem, char type, char chr);
void			ft_mod_width_d(char **str, t_printf *elem);
void			ft_mod_sign(char **str, t_printf *elem, char type);

#endif
