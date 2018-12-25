/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seshevch <seshevch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 20:10:34 by seshevch          #+#    #+#             */
/*   Updated: 2018/12/25 17:25:51 by seshevch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_strnew(size_t size)
{
	size_t	i;
	char	*s1;

	s1 = (char *)malloc(sizeof(char) * (size + 1));
	if (s1)
	{
		i = 0;
		while (i <= size)
		{
			s1[i] = '\0';
			i++;
		}
	}
	else
		return (NULL);
	return (s1);
}
