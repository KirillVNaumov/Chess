# include "chess.h"

int     parsing_input(char *line, t_move *move)
{
    ft_bzero(move, sizeof(t_move *));
    if (!ft_strcmp(line, "O-O"))
		move->kingside_castle = 1;
	if (!ft_strcmp(line, "O-O-O"))
		move->queenside_castle = 1;
}