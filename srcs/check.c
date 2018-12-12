# include "chess.h"

int     check(t_chess *chess, t_move *move, char *line)
{
    int         add;
    char        **arr;

    t_move *temp1;
    // t_chess *temp;
    // char    *temp2;
    temp1 = move;
    // temp2 = line;
    // temp = chess;

    ++chess->to_move;
    add = define_move(chess);
    ++chess->to_move;
    arr = change_map(chess, move);

    int i;

    i = -1;
    while (++i < 8)
        ft_printf("%s\n", arr[i]);

    if ((chess->to_move % 2 == 1 && \
        check_for_check(arr, add, find_kings(arr, 'K')) == -1) || \
        (chess->to_move % 2 == 0 && \
        check_for_check(arr, add, find_kings(arr, 'k')) == -1))
    {
        ft_printf("%s: Invalid: You are under check\n", line);
        return (-1);
    }
    return (1);
}