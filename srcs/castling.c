# include "chess.h"

char	**apply_queenside_castle(t_chess *chess, char **arr)
{
	if (chess->to_move % 2 == 1)
	{
		arr[7][2] = 'K';
		arr[7][3] = 'R';
		arr[7][0] = '.';
		arr[7][4] = '.';
	}
	else
	{
		arr[7][5] = 'k';
		arr[7][4] = 'r';
		arr[7][7] = '.';
		arr[7][3] = '.';
	}
    return (arr);
}

char	**apply_kingside_castle(t_chess *chess, char **arr)
{
	if (chess->to_move % 2 == 1)
	{
		arr[7][6] = 'K';
		arr[7][5] = 'R';
		arr[7][7] = '.';
		arr[7][4] = '.';
	}
	else
	{
		arr[7][1] = 'k';
		arr[7][2] = 'r';
		arr[7][0] = '.';
		arr[7][3] = '.';	
	}
    return (arr);
}

int     check_queenside_castle(t_chess *chess)
{
    if ((chess->info.rook_a1_move == 1 && chess->to_move % 2 == 1) || \
        (chess->info.rook_a8_move == 1 && chess->to_move % 2 == 0))    
        return (-1);
    if (chess->to_move % 2 == 1)
        if (chess->board[7][1] != '.' || chess->board[7][2] != '.' || \
            chess->board[7][3] != '.')
            return (-1);
    if (chess->to_move % 2 == 0)
        if (chess->board[7][4] != '.' || chess->board[7][5] != '.' || \
            chess->board[7][6] != '.')
            return (-1);
    if ((chess->to_move % 2 == 0 && chess->info.black_king_move == 1) || \
        (chess->to_move % 2 == 1 && chess->info.white_king_move == 1))
        return (-1);
    return (1);
}

int     check_kingside_castle(t_chess *chess)
{
    if ((chess->info.rook_h1_move == 1 && chess->to_move % 2 == 1) || \
        (chess->info.rook_h8_move == 1 && chess->to_move % 2 == 0))    
        return (-1);
    if (chess->to_move % 2 == 1)
        if (chess->board[7][5] != '.' || chess->board[7][6] != '.')
            return (-1);
    if (chess->to_move % 2 == 0)
        if (chess->board[7][1] != '.' || chess->board[7][2] != '.')
            return (-1);
    if ((chess->to_move % 2 == 0 && chess->info.black_king_move == 1) || \
        (chess->to_move % 2 == 1 && chess->info.white_king_move == 1))
        return (-1);
    return (1);
}