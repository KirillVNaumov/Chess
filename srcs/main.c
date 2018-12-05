/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 09:45:32 by exam              #+#    #+#             */
/*   Updated: 2018/12/04 16:34:10 by knaumov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "chess.h"

int		main(int argc, char **argv)
{
	t_chess		chess;

	char *str;
	str = argv[0];

	if (argc == 1)
	{
		ft_bzero(&chess, sizeof(t_chess *));
		header();
	}
	else
		ft_printf("Usage: ./chess\n");
	return (0);
}
