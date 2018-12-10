# include "chess.h"

int     check_en_passant(t_chess *chess, t_move *move)
{
    if (move->piece >= 'a' && move->piece <= 'h')
    {
        
    }
    return (-1);
}

int     check_takes(t_chess *chess, t_move *move)
{
    if (move->if_takes == 1)
    {
        if (define_move(chess) != 0 && \
            chess->board[move->dest.y][move->dest.x] >= 65 && \
            chess->board[move->dest.y][move->dest.x] <= 90)
            return (1);
        else if (define_move(chess) == 0 && \
            chess->board[move->dest.y][move->dest.x] >= 97 && \
            chess->board[move->dest.y][move->dest.x] <= 122)
            return (1);
        else
            return (-1);
    }
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
            if (move->piece == 'R' && chess->board[i][j] == move->piece + add)
            {
                if (check_rook_move(chess, move, i, j) == 1)
                {
                    ++count;
                    move->from.x = j;
                    move->from.y = i;
                }
            }
            if (move->piece == 'B' && chess->board[i][j] == move->piece + add)
            {
                if (check_bishop_move(chess, move, i, j) == 1)
                {
                    ++count;
                    move->from.x = j;
                    move->from.y = i;
                }
            }
            if (move->piece == 'Q' && chess->board[i][j] == move->piece + add)
            {
                if (check_queen_move(chess, move, i, j) == 1)
                {
                    ++count;
                    move->from.x = j;
                    move->from.y = i;
                }
            }
            if (move->piece == 'K' && chess->board[i][j] == move->piece + add)
            {
                if (check_king_move(move, i, j) == 1)
                {
                    ++count;
                    move->from.x = j;
                    move->from.y = i;
                }
            }
            if (move->piece == 'N' && chess->board[i][j] == move->piece + add)
            {
                if (check_knight_move(move, i, j) == 1)
                {
                    ++count;
                    move->from.x = j;
                    move->from.y = i;
                }
            }
            if (move->piece >= 'a' && move->piece <= 'h' && chess->board[i][j] == 'P' + add)
            {
                if (check_pawn_move(move, i, j) == 1)
                {
                    ++count;
                    move->from.x = j;
                    move->from.y = i;
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
    if (move->kingside_castle == 1)
    {
        if (check_kingside_castle(chess) == -1)
            return (-1);
        return (1);
    }
    if (move->queenside_castle == 1)
    {
        if (check_queenside_castle(chess) == -1)
            return (-1);
        return (1);
    }
    if (check_en_passant(chess, move) == 1)
        return (1);
    if (check_takes(chess, move) == -1)
        return (-1);
    if (check_for_move(chess, move) == -1)
        return (-1);
    return (1);
}