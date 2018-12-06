# include "chess.h"

void    draw_board(t_chess chess)
{
    int     i;
    int     j;

    header();
    i = -1;
    while (chess.board[++i])
    {
        j = -1;
            ft_printf("%s%d ", CWHITE, 8 - i);
        while (chess.board[i][++j])
        {
            if (chess.board[i][j] >=65 && chess.board[i][j] <= 90)
                ft_printf("%s", CRED);
            else if (chess.board[i][j] >=97 && chess.board[i][j] <= 122)
                ft_printf("%s", CBLUE);
            else
                ft_printf("%s.", CWHITE);
            if (chess.board[i][j] == 'P' || chess.board[i][j] == 'p')
                ft_printf("p");
            else if (chess.board[i][j] >=65 && chess.board[i][j] <= 90)
                ft_printf("%c", chess.board[i][j]);
            else if (chess.board[i][j] >=97 && chess.board[i][j] <= 122)
                ft_printf("%c", chess.board[i][j] - 32);
        }
        ft_printf("\n");
    }
    ft_printf("%s  abcdefgh\n", CWHITE);
}