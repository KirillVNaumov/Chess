#include "chess.h"

int     define_move(t_chess *chess)
{
    if (chess->to_move % 2 == 1)
		return (0);
    return (32);
}

void    set_info(t_chess *chess)
{
    int i;

    chess->info.rook_a1_move = 0;
    chess->info.rook_a8_move = 0;
    chess->info.rook_h1_move = 0;
    chess->info.rook_h8_move = 0;
    chess->info.black_king_move = 0;
    chess->info.white_king_move = 0;
    chess->number_of_moves = 0;
    i = 0;
    while (i < 8)
        chess->info.white_pawns[i++] = 0; 
    i = 0;
    while (i < 8)
        chess->info.black_pawns[i++] = 0; 
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
                chess->info.white_king_pos.x = j;
                chess->info.white_king_pos.y = i;
            }
            if (chess->board[i][j] == 'k')
            {
                chess->info.black_king_pos.x = j;
                chess->info.black_king_pos.y = i;    
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
    move->en_passant = 0;
    move->piece = '-';
    move->specification = '-';
    move->promotion = '-';
}

void	game(t_chess *chess, int file)
{
	char    *line;
    t_move  move;

	draw_board(*chess);
    ft_bzero(&move, sizeof(t_move *));
    set_info(chess);
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
            ++chess->to_move;
            ++chess->number_of_moves;
            write_to_a_file(file, line, chess);
    	    draw_board(*chess);
        }
	}
}