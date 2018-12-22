/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seshevch <seshevch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 13:53:31 by seshevch          #+#    #+#             */
/*   Updated: 2018/12/22 16:10:36 by seshevch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int         ft_check(const char * restrict str, va_list argstr, int count)
{
    char    c;

    if (str[count] == 'c')
    {
        c = va_arg(argstr, int);
        ft_put_n_char(c, 1);
        count++;
    }
    return (count);
}

int         ft_printf(const char * restrict str, ...)
{
    va_list     argstr;
    int         count;

    count = 0;
    va_start(argstr, str);
    while ((count = ft_print_str(str, count)) != -1)
    {
        count = ft_check(str, argstr, count);
        count++;
    }
    va_end(argstr);
    return (1);
}

int         main(void)
{
    printf("hello\n%c\nworld\n", 'S');
    printf("----------------------\n");
    ft_printf("qweq\n");
}