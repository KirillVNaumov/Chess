/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_board.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 09:57:16 by exam              #+#    #+#             */
/*   Updated: 2018/12/04 16:34:01 by knaumov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "chess.h"

char	**create_board(int size, char **map)
{
	char		**board;
	int			i;
	int			j;

	i = 0;
	board = (char **)malloc(sizeof(char *) * (size + 1));
	while (i < size)
	{
		board[i] = (char *)malloc(sizeof(char) * (size + 1));
		++i;
	}
	board[i] = NULL;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			board[i][j] = map[i + 1][j];
			if (board[i][j] != 'B' && board[i][j] != 'R' && board[i][j] != 'Q' && board[i][j] != 'K' && board[i][j] != 'P')
				board[i][j] = '.';
			++j;
		}
		++i;
	}
	return (board);
}
