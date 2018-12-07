# include "chess.h"

int     check_knight_move(t_move *move, int i, int j)
{
    if ((move->dest.y == i + 1 && move->dest.x == j + 2) || \
        (move->dest.y == i + 1 && move->dest.x == j - 2) || \
        (move->dest.y == i - 1 && move->dest.x == j + 2) || \
        (move->dest.y == i - 1 && move->dest.x == j - 2) || \
        (move->dest.y == i + 2 && move->dest.x == j + 1) || \
        (move->dest.y == i + 2 && move->dest.x == j - 1) || \
        (move->dest.y == i - 2 && move->dest.x == j + 1) || \
        (move->dest.y == i - 2 && move->dest.x == j - 1))
        return (1);
    return (-1);
}