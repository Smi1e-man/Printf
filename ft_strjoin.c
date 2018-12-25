/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seshevch <seshevch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 18:24:24 by seshevch          #+#    #+#             */
/*   Updated: 2018/12/25 17:23:15 by seshevch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;

	if (s1 && s2)
	{
		s3 = (char *)ft_strnew(ft_strlen(s1) + ft_strlen(s2));
		if (s3)
		{
			return (ft_strcat(ft_strcpy(s3, s1), s2));
		}
		return (s3);
	}
	return (NULL);
}
