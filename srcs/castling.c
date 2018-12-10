# include "chess.h"

void	apply_queenside_castle(t_chess *chess)
{
	if (chess->to_move % 2 == 1)
	{
		chess->board[7][2] = 'K';
		chess->board[7][3] = 'R';
		chess->board[7][0] = '.';
		chess->board[7][4] = '.';
	}
	else
	{
		chess->board[7][5] = 'k';
		chess->board[7][4] = 'r';
		chess->board[7][7] = '.';
		chess->board[7][3] = '.';
	}
}

void	apply_kingside_castle(t_chess *chess)
{
	if (chess->to_move % 2 == 1)
	{
		chess->board[7][6] = 'K';
		chess->board[7][5] = 'R';
		chess->board[7][7] = '.';
		chess->board[7][4] = '.';
	}
	else
	{
		chess->board[7][1] = 'k';
		chess->board[7][2] = 'r';
		chess->board[7][0] = '.';
		chess->board[7][3] = '.';	
	}
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