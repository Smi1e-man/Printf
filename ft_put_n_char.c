/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_n_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seshevch <seshevch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 21:08:31 by seshevch          #+#    #+#             */
/*   Updated: 2019/01/06 18:26:06 by seshevch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_put_n_char(char c, int n)
{
	char	*s1;
	char	*s2;

	s1 = ft_strnew(n);
	s2 = ft_memset(s1, c, n);
	write(1, s2, n);
	free(s2);
	g_out += n;
}
