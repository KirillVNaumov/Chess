#include "chess.h"

void    regular_chess_board(t_chess *chess)
{
    int     i;

    i = -1;
    while (++i < 8)
    {
        chess->board[1][i] = 'p';
        chess->board[6][i] = 'P';
    }
    chess->board[0][0] = 'r';
    chess->board[0][7] = 'r';
    chess->board[7][0] = 'R';
    chess->board[7][7] = 'R';
    chess->board[0][1] = 'n';
    chess->board[0][6] = 'n';
    chess->board[7][1] = 'N';
    chess->board[7][6] = 'N';
    chess->board[0][2] = 'b';
    chess->board[0][5] = 'b';
    chess->board[7][2] = 'B';
    chess->board[7][5] = 'B';
    chess->board[0][3] = 'q';
    chess->board[0][4] = 'k';
    chess->board[7][3] = 'Q';
    chess->board[7][4] = 'K';
}

void    chess_360_board(t_chess *chess)
{
    int     i;

    i = 0;
    while (i < 8)
    {
        chess->board[1][i] = 'p';
        chess->board[6][i] = 'P';
    }
    chess->board[0][0] = 'r';
    chess->board[0][7] = 'r';
    chess->board[7][0] = 'R';
    chess->board[7][7] = 'R';
    chess->board[0][1] = 'n';
    chess->board[0][6] = 'n';
    chess->board[7][1] = 'N';
    chess->board[7][6] = 'N';
    chess->board[0][2] = 'b';
    chess->board[0][5] = 'b';
    chess->board[7][2] = 'B';
    chess->board[7][5] = 'B';
    chess->board[0][3] = 'k';
    chess->board[0][4] = 'q';
    chess->board[7][3] = 'K';
    chess->board[7][4] = 'Q';
}

void	create_board(t_chess *chess)
{
	int i;
    int j;

	chess->board = (char **)malloc(sizeof(char *) * 9);
	i = -1;
	while (++i < 8)
    {
        chess->board[i]= (char *)malloc(sizeof(char) * 9);
        j = -1;
        while (++j < 8)
            chess->board[i][j] = '.';
        chess->board[i][j] = '\0';
    }
    chess->board[i] = NULL;
    if (chess->type_of_board == 1)
		regular_chess_board(chess);
	if (chess->type_of_board == 2)
		chess_360_board(chess);
}