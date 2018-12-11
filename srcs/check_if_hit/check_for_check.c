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

void	check_for_check(char **board, int add, char king)
{
	int		i;
	int		j;
	int		check;

	i = 0;
	check = 0;
	while (board[i])
	{
		j = 0;
		while (board[i][j])
		{
			if (board[i][j] == 'B' + add)
				check += check_bishop_if_hit(board, i, j, king);
			if (board[i][j] == 'R' + add)
				check += check_rook_if_hit(board, i, j, king);
			if (board[i][j] == 'Q' + add)
				check += check_queen_if_hit(board, i, j, king);
			if (board[i][j] == 'P' + add && i > 0)
				check += check_pawn_if_hit(board, i, j, king);
			if (check != 0)
				return (1);
			++j;
		}
		++i;
	}
	return (0);
}
