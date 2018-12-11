/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bishop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 10:12:20 by exam              #+#    #+#             */
/*   Updated: 2018/11/06 10:29:35 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "chess.h"

int		check_bishop_if_hit(char **board, int i, int j, char king)
{
	int		start_i;
	int		start_j;

	start_i = i;
	start_j = j;
	while (i >= 0 && j >= 0)
	{
		if (board[i][j] == king)
			return (1);
		if (board[i][j] != '.' && (i != start_i || j != start_j))
			break ;
		--i;
		--j;
	}
	i = start_i;
	j = start_j;
	while (i >= 0 && board[i][j])
	{
		if (board[i][j] == king)
			return (1);
		if (board[i][j] != '.' && (i != start_i || j != start_j))
			break ;
		--i;
		++j;
	}
	i = start_i;
	j = start_j;
	while (board[i] && j >= 0)
	{
		if (board[i][j] == king)
			return (1);
		if (board[i][j] != '.' && (i != start_i || j != start_j))
			break ;
		--j;
		++i;
	}
	i = start_i;
	j = start_j;
	while (board[i] && board[i][j])
	{
		if (board[i][j] == king)
			return (1);
		if (board[i][j] != '.' && (i != start_i || j != start_j))
			break ;
		++j;
		++i;
	}
	return (0);
}
