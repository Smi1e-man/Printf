/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seshevch <seshevch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 17:31:57 by seshevch          #+#    #+#             */
/*   Updated: 2018/12/26 15:15:57 by seshevch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		main(void)
{
	printf("%d\n", printf("hello\n%c\nworld\n", '\0'));
	printf("----------------------\n");
	printf("%d\n", ft_printf("hello\n%c\nworld\n", '\0'));
	// system("leaks a.out");
	return (0);
}
