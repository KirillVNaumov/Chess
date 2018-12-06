#include "chess.h"

void    set_move(t_move *move)
{
    move->if_check = 0;
    move->if_mate = 0;
    move->if_takes = 0;
    move->if_promote = 0;
    move->kingside_castle = 0;
    move->queenside_castle = 0;
    move->dest.x = 0;
    move->dest.y = 0;
    move->piece = '-';
}

void	game(t_chess *chess)
{
	char    *line;
    t_move  move;

	draw_board(*chess);
    ft_bzero(&move, sizeof(t_move *));
	while (get_next_line(0, &line))
	{
        set_move(&move);
        if (!ft_strcmp(line, "exit"))
            return ;
		else if (parsing_input(line, &move) == -1)
			ft_printf("%s: Input Error\n", line);
        else if (check_if_valid(chess, &move) == -1)
			ft_printf("%s: Move is not valid\n", line);
        else
        {
            apply_move(chess, &move);
    	    draw_board(*chess);
        }
	}
}