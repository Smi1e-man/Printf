/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_save_strct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seshevch <seshevch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 12:29:53 by seshevch          #+#    #+#             */
/*   Updated: 2018/12/25 14:25:31 by seshevch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"


void        ft_save_flag(const char * restrict str, int *count, t_printf *elem)
{
    while (str[count[0]] == '#' || str[count[0]] == '0' || str[count[0]] == '-' ||
            str[count[0]] == '+' || str[count[0]] == ' ')
    {
        if (str[count[0]] == '#')
            elem->flg_hsh = '#';
        else if (str[count[0]] == '0')
            elem->flg_nul = '0';
        else if (str[count[0]] == '-')
            elem->flg_min = '-';
        else if (str[count[0]] == '+')
            elem->flg_sum = '+';
        else if (str[count[0]] == ' ')
            elem->flg_spc = ' ';
        count[0]++;
    }
    // printf("%c\n", elem->flg_hsh);
    // printf("%c\n", elem->flg_min);
    // printf("%c\n", elem->flg_sum);
    // printf("%c\n", elem->flg_spc);
    // printf("%c\n", elem->flg_nul);
}

void        ft_save_width(const char * restrict str, int *count, t_printf *elem)
{
    int     numb;

    numb = 0;
    while (str[count[0]] >= '0' && str[count[0]] <= '9')
    {
        numb *= 10;
        numb = numb + (str[count[0]] - '0');
        count[0]++;
    }
    elem->width = numb;
    printf("%d\n", numb);
}

void        ft_save_precision(const char * restrict str, int *count, t_printf *elem)
{
    if (str[count[0]] == '.')
    {
        
    }
}