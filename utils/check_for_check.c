/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_for_mate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 10:04:29 by exam              #+#    #+#             */
/*   Updated: 2018/12/04 16:33:33 by knaumov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "chess.h"

int			check_for_check(t_chess *chess)
{
	int		i;
	int		j;
	int		add;
	int		check;

	i = 0;
	check = 0;
	if (chess->to_move == 1)
		add = 0;
	else
		add = 32;
	while (chess->board[i])
	{
		j = 0;
		while (chess->board[i][j])
		{
			if (chess->board[i][j] == 'B' + add)
				check += check_bishop(chess->board, i, j, 'k' - add);
			if (chess->board[i][j] == 'R' + add)
				check += check_rook(chess->board, i, j, 'k' - add);
			if (chess->board[i][j] == 'Q' + add)
			{
				check += check_bishop(chess->board, i, j, 'k' - add);
				check += check_rook(chess->board, i, j, 'k' - add);
			}
			if (chess->board[i][j] == 'P' + add && i > 0)
				check += check_pawn(chess->board, i, j, 'k' - add);
			if (check != 0)
				return (1);
			++j;
		}
		++i;
	}
	return (-1);
}
