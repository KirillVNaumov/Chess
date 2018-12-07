/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pawn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 10:10:43 by exam              #+#    #+#             */
/*   Updated: 2018/12/04 16:33:42 by knaumov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "chess.h"

int     check_pawn_move(t_move *move, int i, int j)
{
    if (move->if_takes == 1)
    {
        if ((move->dest.x == j + 1 && move->dest.y == i - 1) || \
            (move->dest.x == j - 1 && move->dest.y == i - 1))
            return (1);
        return (-1);
    }
    if (move->if_takes == 0)
    {
        if ((move->dest.x == j && move->dest.y == i - 1) || \
            (move->dest.x == j && move->dest.y == i - 2 && i == 6))
            return (1);
        return (-1);
    }
    return (-1);
}