# include "chess.h"

int     check_en_passant(t_chess *chess, t_move *move)
{
    if (move->piece >= 'a' && move->piece <= 'h' && \
        move->dest.y == 2 && move->if_takes == 1)
        if ((chess->to_move % 2 == 1 && chess->info.black_pawns[7 - move->dest.x] == 1) || \
            (chess->to_move % 2 == 0 && chess->info.white_pawns[7 - move->dest.x] == 1))
        {
            move->en_passant = 1;
            move->from.y = 3;
            move->from.x = move->piece - 'a';
            if (chess->to_move % 2 == 0)
                move->from.x = 7 - move->from.x;
            return (1);
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
    int         i;
    int         j;
    int         count;
    int         add;
    t_point     specification;

    i = -1;
    count = 0;
    add = define_move(chess);
    if (move->specification_number != '-')
        specification.y = move->specification_number - '1';
    if (move->specification_letter != '-')
        specification.x = move->specification_letter - 'a';
    if (chess->to_move % 2 == 1)
        specification.y = 7 - specification.y;
    if (chess->to_move % 2 == 0)
        specification.x = 7 - specification.x;
    while (chess->board[++i])
    {
        if (move->specification_number != '-' && \
            i != specification.y)
            continue ;
        j = -1;
        while (chess->board[i][++j])
        {
            if (move->specification_letter != '-' && \
                j != specification.x)
                continue ;
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
        if (move->specification_letter == '-' && move->specification_number == '-')
            return (-1);
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