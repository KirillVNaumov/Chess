#include "chess.h"

int		check_pawn_if_hit(char **board, int i, int j, char king)
{
    if (check_bishop_if_hit(board, i, j, king) || check_rook_if_hit(board, i, j, king))
        return (1);
    return (0);
}