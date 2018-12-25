/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seshevch <seshevch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 17:49:01 by seshevch          #+#    #+#             */
/*   Updated: 2018/12/25 17:31:52 by seshevch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*s1;
	unsigned int	i;

	if (s)
	{
		s1 = (char *)ft_strnew(len);
		if (s1)
		{
			i = 0;
			while (i < len)
			{
				s1[i] = s[start];
				i++;
				start++;
			}
		}
		return (s1);
	}
	return ((char *)s);
}
