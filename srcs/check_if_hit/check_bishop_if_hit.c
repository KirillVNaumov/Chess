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

int		check_bishop_if_hit(char **board, t_point tracker, t_point king)
{
	t_point		temp;

	temp = tracker;
	while (temp.y >= 0 && temp.x >= 0)
	{
		if (temp.y == king.y && temp.x == king.x)
			return (1);
		if (board[temp.y][temp.x] != '.' && (temp.y != tracker.y || temp.x != tracker.x))
			break ;
		--temp.y;
		--temp.x;
	}
	temp = tracker;
	while (temp.y >= 0 && board[temp.y][temp.x])
	{
		if (temp.y == king.y && temp.x == king.x)
			return (1);
		if (board[temp.y][temp.x] != '.' && (temp.y != tracker.y || temp.x != tracker.x))
			break ;
		--temp.y;
		++temp.x;
	}
	temp = tracker;
	while (board[temp.y] && temp.x >= 0)
	{
		if (temp.y == king.y && temp.x == king.x)
			return (1);
		if (board[temp.y][temp.x] != '.' && (temp.y != tracker.y || temp.x != tracker.x))
			break ;
		--temp.x;
		++temp.y;
	}
	temp = tracker;
	while (board[temp.y] && board[temp.y][temp.x])
	{
		if (temp.y == king.y && temp.x == king.x)
			return (1);
		if (board[temp.y][temp.x] != '.' && (temp.y != tracker.y || temp.x != tracker.x))
			break ;
		++temp.x;
		++temp.y;
	}
	return (0);
}
