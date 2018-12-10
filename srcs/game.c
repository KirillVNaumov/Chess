#include "chess.h"

int     define_move(t_chess *chess)
{
    if (chess->to_move % 2 == 1)
		return (0);
    return (32);
}

void    set_for_castling(t_chess *chess)
{
    chess->rook_a1_move = 0;
    chess->rook_a8_move = 0;
    chess->rook_h1_move = 0;
    chess->rook_h8_move = 0;
    chess->black_king_move = 0;
    chess->white_king_move = 0;
}

void    find_kings(t_chess *chess)
{
    int     i;
    int     j;

    i = -1;
    while (chess->board[++i])
    {
        j = -1;
        while (chess->board[i][++j])
        {
            if (chess->board[i][j] == 'K')
            {
                chess->white_king_pos.x = j;
                chess->white_king_pos.y = i;
            }
            if (chess->board[i][j] == 'k')
            {
                chess->black_king_pos.x = j;
                chess->black_king_pos.y = i;    
            }
        }
    }
}

void    set_move(t_move *move)
{
    move->if_check = 0;
    move->if_mate = 0;
    move->if_takes = 0;
    move->kingside_castle = 0;
    move->queenside_castle = 0;
    move->dest.x = 0;
    move->dest.y = 0;
    move->from.x = 0;
    move->from.y = 0;
    move->piece = '-';
    move->specification = '-';
    move->promotion = '-';
}

void	game(t_chess *chess)
{
	char    *line;
    t_move  move;

	draw_board(*chess);
    ft_bzero(&move, sizeof(t_move *));
    set_for_castling(chess);
	while (get_next_line(0, &line))
	{
        find_kings(chess);
        set_move(&move);
        if (!ft_strcmp(line, "exit"))
            return ;
		else if (parsing_input(line, &move, chess) == -1)
			ft_printf("%s: Input Error\n", line);
        else if (check_if_valid(chess, &move) == -1)
			ft_printf("%s: Move is not valid\n", line);
        else
        {
            apply_move(chess, &move);
            reverse_board(chess);
            chess->to_move++;
    	    draw_board(*chess);
        }
	}
}