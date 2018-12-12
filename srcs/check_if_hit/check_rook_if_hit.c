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

#include "chess.h"

int		check_rook_if_hit(char **board, t_point tracker, t_point king)
{
	t_point		temp;

	temp = tracker;
	while (temp.y >= 0)
	{
		if (temp.y == king.y && temp.x == king.x)
			return (1);
		if (board[temp.y][temp.x] != '.' && (temp.y != tracker.y || temp.x != tracker.x))
			break ;
		--temp.y;
	}
	temp = tracker;
	while (board[temp.y])
	{
		if (temp.y == king.y && temp.x == king.x)
			return (1);
		if (board[temp.y][temp.x] != '.' && (temp.y != tracker.y || temp.x != tracker.x))
			break ;
		++temp.y;
	}
	temp = tracker;
	while (temp.x >= 0)
	{
		if (temp.y == king.y && temp.x == king.x)
			return (1);
		if (board[temp.y][temp.x] != '.' && (temp.y != tracker.y || temp.x != tracker.x))
			break ;
		--temp.x;
	}
	temp = tracker;
	while (board[temp.y][temp.x])
	{
		if (temp.y == king.y && temp.x == king.x)
			return (1);
		if (board[temp.y][temp.x] != '.' && (temp.y != tracker.y || temp.x != tracker.x))
			break ;
		++temp.x;
	}
	return (0);
}
