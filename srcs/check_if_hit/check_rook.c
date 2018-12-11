/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 10:12:37 by exam              #+#    #+#             */
/*   Updated: 2018/11/06 10:24:12 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_mate.h"

int		check_rook(char **board, int i, int j)
{
	int		start_i;
	int		start_j;

	start_i = i;
	start_j = j;
	while (i >= 0)
	{
		if (board[i][j] == 'K')
			return (1);
		if (board[i][j] != '.' && (i != start_i || j != start_j))
			break ;
		--i;
	}
	i = start_i;
	j = start_j;
	while (board[i])
	{
		if (board[i][j] == 'K')
			return (1);
		if (board[i][j] != '.' && (i != start_i || j != start_j))
			break ;
		++i;
	}
	i = start_i;
	j = start_j;
	while (j >= 0)
	{
		if (board[i][j] == 'K')
			return (1);
		if (board[i][j] != '.' && (i != start_i || j != start_j))
			break ;
		--j;
	}
	i = start_i;
	j = start_j;
	while (board[i][j])
	{
		if (board[i][j] == 'K')
			return (1);
		if (board[i][j] != '.' && (i != start_i || j != start_j))
			break ;
		++j;
	}
	return (0);
}
