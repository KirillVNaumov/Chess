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

char	*new_file()
{
	FILE	*file;
	char	*str;
	DIR		*dir;
	struct dirent	*sd;
	int		n;

	n = -1;
	dir = opendir("logs");
	while ((sd = readdir(dir)))
		++n;
	closedir(dir);
	str = ft_itoa(n);
	str = ft_update(str, ft_strjoin("logs/", str));
	file = fopen(str, "wb");
	ft_printf("%s\n", str);
	fclose(file);
	return (str);
}

int		main(int argc, char **argv)
{
	t_chess		chess;
	char		*str;
	int			fd;

	str = argv[0];
	if (argc == 1)
	{
		ft_bzero(&chess, sizeof(t_chess *));
		chess.to_move = 1;
		chess.type_of_board = 1;
		create_board(&chess);
		str = new_file();
		fd = open(str, O_RDWR);
		game(&chess, fd);
		close(fd);
	}
	else
		ft_printf("Usage: ./chess\n");
	return (0);
}
