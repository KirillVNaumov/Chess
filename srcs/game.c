#include "chess.h"

void	game(t_chess *chess)
{
	char    *line;
    t_move  *move;

	draw_board(*chess);
	while (get_next_line(0, &line))
	{
        move = NULL;
        if (!ft_strcmp(line, "exit"))
            return ;
		else if (parsing_input(line, move) == 0)
			ft_printf("\n%s: Input Error", line);
        else if (check_if_valid(chess, move) == 0)
			ft_printf("\n%s: Move is not valid exist", line);
        else
        {
            apply_move(chess, move);
    	    draw_board(*chess);
        }
	}
}