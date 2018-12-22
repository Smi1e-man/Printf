/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seshevch <seshevch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 21:08:31 by seshevch          #+#    #+#             */
/*   Updated: 2018/12/22 15:29:04 by seshevch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_print_str(const char * restrict str, int count)
{
	while (str[count] != '\0')
	{
		if (str[count] == '%' && str[count + 1] == '%')
		{
			ft_put_n_char('%', 1);
			count++;
		}
		else if (str[count] == '%')
			return (count++);
		else
			ft_put_n_char(str[count], 1);
		count++;
	}
	return (-1);
}
