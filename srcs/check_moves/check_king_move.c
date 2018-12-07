# include "chess.h"

int     check_king_move(t_chess *chess, t_move *move, int i, int j)
{
	int		start_i;
	int		start_j;

	start_i = i;
	start_j = j;
	if (move->dest.y > i)
		while (i >= 0 && j >= 0)
		{
			if (move->dest.y == i && move->dest.x == j)
				return (1);
			if (chess->board[i][j] != '.' && (i != start_i || j != start_j))
				break ;
			++i;
			++j;
		}
	i = start_i;
	if (move->dest.y == i)
		while (chess->board[i] && j >= 0)
		{
			if (move->dest.y == i && move->dest.x == j)
				return (1);
			if (chess->board[i][j] != '.' && (i != start_i || j != start_j))
				break ;
			--i;
			++j;
		}
	j = start_j;
	if (move->dest.y < i)
		while (i >= 0 && chess->board[i][j])
		{
			if (move->dest.x == j && move->dest.x == j)
				return (1);
			if (chess->board[i][j] != '.' && (i != start_i || j != start_j))
				break ;
			++i;
			--j;
		}
	return (-1);
}