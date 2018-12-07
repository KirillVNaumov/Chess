# include "chess.h"

int     check_queen_move(t_chess *chess, t_move *move, int i, int j)
{
    if (check_bishop_move(chess, move, i, j) == 1)
        return (1);
    if (check_rook_move(chess, move, i, j) == 1)
        return (1);
    return (-1);
}