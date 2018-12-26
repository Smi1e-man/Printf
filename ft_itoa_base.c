/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seshevch <seshevch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 15:22:12 by seshevch          #+#    #+#             */
/*   Updated: 2018/12/26 16:23:41 by seshevch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_itoa_base(unsigned long long val, int base)
{
	char					*str;
	unsigned int			i;
	unsigned long long		v1;

	i = 0;
	v1 = val;
	while (v1 != 0)
	{
		v1 /= base;
		i++;
	}
	str = ft_strnew(i);
	while (i-- != 0)
	{
		if ((val % base) > 9)
			v1 = (val % base) - 10 + 'a';
		else
			v1 = (val % base) + '0';
		str[i] = v1;
		val /= base;
	}
	return (str);
}