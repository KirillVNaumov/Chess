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

void	check_for_mate(char **board)
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
			if (board[i][j] == 'B')
				check += check_bishop(board, i, j);
			if (board[i][j] == 'R')
				check += check_rook(board, i, j);
			if (board[i][j] == 'Q')
			{
				check += check_bishop(board, i, j);
				check += check_rook(board, i, j);
			}
			if (board[i][j] == 'P' && i > 0)
				check += check_pawn(board, i, j);
			if (check != 0)
			{
				ft_putstr("Success\n");
				return ;
			}
			++j;
		}
		++i;
	}
	ft_putstr("Fail\n");
}
