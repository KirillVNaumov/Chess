/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pawn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 10:10:43 by exam              #+#    #+#             */
/*   Updated: 2018/11/06 10:15:56 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "chess.h"

int		check_pawn_if_hit(t_point tracker, t_point king)
{
	if (tracker.x + 1 == king.x && tracker.y + 1 == king.y)
		return (1);
	if (tracker.x - 1 == king.x && tracker.y + 1 == king.y)
		return (1);
	return (0);
}
