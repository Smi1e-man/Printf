/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seshevch <seshevch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 17:31:57 by seshevch          #+#    #+#             */
/*   Updated: 2018/12/25 17:04:37 by seshevch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		main(void)
{
	printf("%d\n", printf("hello\n%-10s\nworld\n", "brave"));
	printf("----------------------\n");
	printf("%d\n", ft_printf("hello\n%-10s\nworld\n", "brave"));
	// system("leaks a.out");
	return (0);
}
