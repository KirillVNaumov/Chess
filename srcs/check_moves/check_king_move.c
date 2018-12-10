# include "chess.h"

int     check_king_move(t_move *move, int i, int j)
{
	if ((move->dest.y == i && move->dest.x == j - 1) || \
        (move->dest.y == i && move->dest.x == j + 1) || \
        (move->dest.y == i + 1 && move->dest.x == j - 1) || \
        (move->dest.y == i + 1 && move->dest.x == j) || \
        (move->dest.y == i + 1 && move->dest.x == j + 1) || \
        (move->dest.y == i - 1 && move->dest.x == j - 1) || \
        (move->dest.y == i - 1 && move->dest.x == j) || \
        (move->dest.y == i - 1 && move->dest.x == j + 1))
        return (1);
	return (-1);
}