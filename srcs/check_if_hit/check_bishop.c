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

#include "check_mate.h"

int		check_bishop(char **board, int i, int j)
{
	int		start_i;
	int		start_j;

	start_i = i;
	start_j = j;
	while (i >= 0 && j >= 0)
	{
		if (board[i][j] == 'K')
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
		if (board[i][j] == 'K')
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
		if (board[i][j] == 'K')
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
		if (board[i][j] == 'K')
			return (1);
		if (board[i][j] != '.' && (i != start_i || j != start_j))
			break ;
		++j;
		++i;
	}
	return (0);
}
