# include "chess.h"

int     check_takes(t_chess *chess, t_move *move)
{
    if (move->if_takes == 1)
        if (chess->board[move->dest.y][move->dest.x] == '.')
            return (-1);
    if (move->if_takes == 0)
        if (chess->board[move->dest.y][move->dest.x] != '.')
            return (-1);
    return (1);
}

int     check_if_valid(t_chess *chess, t_move *move)
{

    if (check_takes(chess, move) == -1)
        return (-1);
    return (1);
}