#include "chess.h"

int		check_queen_if_hit(char **board, t_point tracker, t_point king)
{
    if (check_bishop_if_hit(board, tracker, king) || \
        check_rook_if_hit(board, tracker, king))
        return (1);
    return (0);
}