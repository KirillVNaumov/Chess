# include "chess.h"

void    reverse_board(t_chess *chess)
{
    char    **new_board;
    int     i;
    int     j;
    int     i2;
    int     j2;

	new_board = (char **)malloc(sizeof(char *) * 9);
	i = -1;
	while (++i < 8)
    {
        new_board[i]= (char *)malloc(sizeof(char) * 9);
        j = -1;
        while (++j < 8)
            new_board[i][j] = '.';
        new_board[i][j] = '\0';
    }
    new_board[i] = NULL;
    i = 7;
    i2 = 0;
    while (i != -1)
    {
        j = 7;
        j2 = 0;
        while (j != -1)
        {
            new_board[i2][j2] = chess->board[i][j];
            --j;
            ++j2;
        }
        --i;
        ++i2;
    }
    chess->board = new_board;
}

void    draw_board(t_chess chess)
{
    int     i;
    int     j;

    header();
    i = -1;
    while (chess.board[++i])
    {
        j = -1;
        if (chess.to_move % 2 == 1)
            ft_printf("%s%d ", CWHITE, 8 - i);
        else
            ft_printf("%s%d ", CWHITE, i + 1);
        while (chess.board[i][++j])
        {
            if (chess.board[i][j] >= 65 && chess.board[i][j] <= 90)
                ft_printf("%s", CRED);
            else if (chess.board[i][j] >= 97 && chess.board[i][j] <= 122)
                ft_printf("%s", CBLUE);
            else
                ft_printf("%s.", CWHITE);
            if (chess.board[i][j] == 'P' || chess.board[i][j] == 'p')
                ft_printf("p");
            else if (chess.board[i][j] >= 65 && chess.board[i][j] <= 90)
                ft_printf("%c", chess.board[i][j]);
            else if (chess.board[i][j] >= 97 && chess.board[i][j] <= 122)
                ft_printf("%c", chess.board[i][j] - 32);
            // ft_printf("%c", chess.board[i][j]);
        }
        ft_printf("\n");
    }
    if (chess.to_move % 2 == 1)
        ft_printf("%s  abcdefgh\n\n", CWHITE);
    else
        ft_printf("%s  hgfedcba\n\n", CWHITE);
}