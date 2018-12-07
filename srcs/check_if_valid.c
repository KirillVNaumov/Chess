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

int     check_for_move(t_chess *chess, t_move *move)
{
    int     i;
    int     j;
    int     count;
    int     add;

    i = -1;
    count = 0;
    add = define_move(chess);
    while (chess->board[++i])
    {
        j = -1;
        while (chess->board[i][++j])
        {
            if (chess->board[i][j] == move->piece || chess->board[i][j] == move->piece + 32)
            {
                if (move->piece == 'R')
                {
                    if (check_rook_move(chess, move, i, j) == 1)
                        ++count;
                }
                if (move->piece == 'B')
                {
                    if (check_bishop_move(chess, move, i, j) == 1)
                        ++count;
                }
                if (move->piece == 'Q')
                {
                    if (check_queen_move(chess, move, i, j) == 1)
                        ++count;
                }
                if (move->piece == 'K')
                {
                    if (check_king_move(chess, move, i, j) == 1)
                        ++count;
                }
                if (move->piece == 'N')
                {
                    if (check_knight_move(chess, move, i, j) == 1)
                        ++count;
                }
                if (move->piece >= 'a' && move->piece <= 'h')
                {
                    if (check_pawn_move(chess, move, i, j) == 1)
                        ++count;
                }
            }
        }
    }
    if (count == 0)
        return (-1);
    if (count > 1)
    {
        if (move->specification == '-')
            return (-1);
        // check_for_specification(chess, move);
    }
    return (1);
}

int     check_if_valid(t_chess *chess, t_move *move)
{
    if (check_takes(chess, move) == -1)
        return (-1);
    if (check_for_move(chess, move) == -1)
        return (-1);
    return (1);
}