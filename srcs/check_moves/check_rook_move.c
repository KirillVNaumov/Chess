/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 10:12:37 by exam              #+#    #+#             */
/*   Updated: 2018/12/04 16:33:52 by knaumov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "chess.h"

int		check_rook_move(t_chess *chess, t_move *move, int i, int j)
{
	int		start_i;
	int		start_j;

	start_i = i;
	start_j = j;
	if (move->dest.x == j && move->dest.y > i)
		while (chess->board[i])
		{
			if (move->dest.y == i)
				return (1);
			if (chess->board[i][j] != '.' && (i != start_i || j != start_j))
				break ;
			++i;
		}
	i = start_i;
	if (move->dest.x == j && move->dest.y < i)
		while (i != -1)
		{
			if (move->dest.y == i)
				return (1);
			if (chess->board[i][j] != '.' && (i != start_i || j != start_j))
				break ;
			--i;
		}
	j = start_j;
	if (move->dest.x > j && move->dest.y == i)
		while (chess->board[i][j])
		{
			if (move->dest.x == j)
				return (1);
			if (chess->board[i][j] != '.' && (i != start_i || j != start_j))
				break ;
			++j;
		}
	j = start_j;
	if (move->dest.x < j && move->dest.y == i)
		while (j != -1)
		{
			if (move->dest.x == j)
				return (1);
			if (chess->board[i][j] != '.' && (i != start_i || j != start_j))
				break ;
			--j;
		}
	return (-1);
}
