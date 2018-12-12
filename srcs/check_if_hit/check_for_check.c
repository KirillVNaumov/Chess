/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_for_mate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 10:04:29 by exam              #+#    #+#             */
/*   Updated: 2018/11/06 10:15:16 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "chess.h"

int				check_for_check(char **board, int add, t_point king)
{
	t_point		tracker;
	int			check;

	tracker.y = -1;
	check = 0;
	while (++tracker.y < 8)
	{
		tracker.x = 0;
		while (++tracker.x < 8)
		{
			if (board[tracker.y][tracker.x] == 'B' + add)
				check += check_bishop_if_hit(board, tracker, king);
			if (board[tracker.y][tracker.x] == 'R' + add)
				check += check_rook_if_hit(board, tracker, king);
			if (board[tracker.y][tracker.x] == 'Q' + add)
				check += check_queen_if_hit(board, tracker, king);
			if (board[tracker.y][tracker.x] == 'P' + add)
				check += check_pawn_if_hit(tracker, king);
			if (check != 0)
				return (-1);
		}
	}
	return (1);
}
