/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seshevch <seshevch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 17:31:57 by seshevch          #+#    #+#             */
/*   Updated: 2018/12/26 19:30:28 by seshevch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		main(void)
{
	char *str;

	str = "12345678";
	printf("%d\n", printf("hello\n%010o\nworld\n", 15));
	printf("----------------------\n");
	printf("%d\n", ft_printf("hello\n%010o\nworld\n", 15));
	// system("leaks a.out");
	return (0);
}
