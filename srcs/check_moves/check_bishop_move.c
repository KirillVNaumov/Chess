/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bishop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 10:12:20 by exam              #+#    #+#             */
/*   Updated: 2018/12/04 16:33:22 by knaumov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "chess.h"

int     check_bishop_move(t_chess *chess, t_move *move, int i, int j)
{
	int		start_i;
	int		start_j;

	start_i = i;
	start_j = j;
	if (move->dest.x > j && move->dest.y > i)
		while (i >= 0 && j >= 0)
		{
			if (move->dest.y == i && move->dest.x == j)
				return (1);
			if (chess->board[i][j] != '.' && (i != start_i || j != start_j))
				break ;
			++i;
			++j;
		}
	i = start_i;
	if (move->dest.x > j && move->dest.y < i)
		while (chess->board[i] && j >= 0)
		{
			if (move->dest.y == i && move->dest.x == j)
				return (1);
			if (chess->board[i][j] != '.' && (i != start_i || j != start_j))
				break ;
			--i;
			++j;
		}
	j = start_j;
	if (move->dest.x < j && move->dest.y > i)
		while (i >= 0 && chess->board[i][j])
		{
			if (move->dest.y == i && move->dest.x == j)
				return (1);
			if (chess->board[i][j] != '.' && (i != start_i || j != start_j))
				break ;
			++i;
			--j;
		}
	j = start_j;
	if (move->dest.x < j && move->dest.y < i)
		while (chess->board[i] && chess->board[i][j])
		{
			if (move->dest.y == i && move->dest.x == j)
				return (1);
			if (chess->board[i][j] != '.' && (i != start_i || j != start_j))
				break ;
			--j;
			--i;
		}
	return (-1);
}