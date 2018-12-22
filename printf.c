/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seshevch <seshevch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 13:53:31 by seshevch          #+#    #+#             */
/*   Updated: 2018/12/22 17:33:09 by seshevch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int         ft_save_flag(const char * restrict str, int count, t_printf *elem)
{
    while (str[count] == '#' || str[count] == '0' || str[count] == '-' ||
            str[count] == '+' || str[count] == ' ')
    {
        if (str[count] == '#')
            elem->flg_hsh = '#';
        else if (str[count] == '0')
            elem->flg_nul = '0';
        else if (str[count] == '-')
            elem->flg_min = '-';
        else if (str[count] == '+')
            elem->flg_sum = '+';
        else if (str[count] == ' ')
            elem->flg_spc = ' ';
        count++;
    }
    // printf("%c\n", elem->flg_hsh);
    return (count);
}

// int         ft_save_width(const char * restrict str, int *count, t_printf *elem)
// {
//     int     numb;

//     numb = 0;
//     while (str[*count] >= '0' && str[*count] <= '9')
//     {
//         numb *= 10;
//         numb = numb + (str[*count] - '0');
//         *count++;
//     }
//     elem->width = numb;
//     return (*count);
// }

int         ft_check(const char * restrict str, va_list argstr, int count, t_printf *elem)
{
    char    c;

    count = ft_save_flag(str, count, elem);
    // count = ft_save_width(str, &count, elem);
    // count = ft_save_precision(str, &count, elem);
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
    t_printf    *elem;
    int         count;

    count = 0;
    va_start(argstr, str);
    while ((count = ft_print_str(str, count)) != -1)
    {
        count = ft_check(str, argstr, count, elem);
        count++;
    }
    va_end(argstr);
    return (1);
}