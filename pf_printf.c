/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seshevch <seshevch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 13:53:31 by seshevch          #+#    #+#             */
/*   Updated: 2018/12/25 14:00:31 by seshevch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int         ft_check(const char * restrict str, va_list argstr, int count, t_printf *elem)
{
    char    c;

    ft_save_flag(str, &count, elem);
    // printf("%d\n", count);
    ft_save_width(str, &count, elem);
    // count = ft_save_precision(str, &count, elem);
    if (str[count] == 'c')
    {
        c = va_arg(argstr, int);
        ft_put_n_char(c, 1);
    }
    return (count);
}

int         ft_printf(const char * restrict str, ...)
{
    va_list     argstr;
    t_printf    *elem;
    int         count;

    count = 0;
    va_start(argstr, str);
    elem = (t_printf*)malloc(sizeof(t_printf));
    while ((count = ft_print_str(str, count)) != -1)
    {
        count = ft_check(str, argstr, count, elem);
        *elem = (t_printf){0,0,0,0,0,0,0,0};
        count++;
    }
    free(elem);
    va_end(argstr);
    return (1);
}

