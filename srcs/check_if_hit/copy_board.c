# include "chess.h"

char    **copy_board(char **board)
{
    char    **arr;
    int     i;
    int     j;

    i = -1;
    arr = (char **)malloc(sizeof(char *) * 9);
    while (board[++i])
    {
        j = -1;
        arr[i] = (char *)malloc(sizeof(char) * 9);
        while (board[i][++j])
            arr[i][j] = board[i][j];
        arr[i][j] = '\0';
    }
    board[i] = NULL;
    return (arr);
}