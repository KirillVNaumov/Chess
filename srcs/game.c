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

t_point     find_kings(char **board, char king)
{
    int     i;
    int     j;
    t_point pos;

    i = -1;
    pos.x = 0;
    pos.y = 0;
    while (board[++i])
    {
        j = -1;
        while (board[i][++j])
        {
            if (board[i][j] == king)
            {
                pos.x = j;
                pos.y = i;
                return (pos);
            }
        }
    }
    return (pos);
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
    move->specification_number = '-';
    move->specification_letter = '-';
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
        chess->info.white_king_pos = find_kings(chess->board, 'K');
        chess->info.black_king_pos = find_kings(chess->board, 'k');
        set_move(&move);
        if (!ft_strcmp(line, "exit"))
            return ;
		else if (parsing_input(line, &move, chess) == -1)
			ft_printf("%s: Invalid: Input Error\n", line);
        else if (check_if_valid(chess, &move) == -1)
			ft_printf("%s: Invalid: Move does not exist\n", line);
        else if (check(chess, &move, line) != -1)
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