/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seshevch <seshevch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 17:31:57 by seshevch          #+#    #+#             */
/*   Updated: 2018/12/25 17:41:36 by seshevch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		main(void)
{
	printf("%d\n", printf("hello\n%07s\nworld\n", NULL));
	printf("----------------------\n");
	printf("%d\n", ft_printf("hello\n%*.*s\nworld\n", 10, 4, "brave"));
	// system("leaks a.out");
	return (0);
}
