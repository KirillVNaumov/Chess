#include "chess.h"

void	queenside_castle(t_chess *chess)
{
	t_chess *temp;

	temp = chess;

}

void	kingside_castle(t_chess *chess)
{
	t_chess *temp;

	temp = chess;
	
}

void        apply_move(t_chess *chess, t_move *move)
{
	if (move->kingside_castle == 1)
		kingside_castle(chess);
	if (move->queenside_castle == 1)
		queenside_castle(chess);
	if (move->queenside_castle || move->kingside_castle)
		return ;
	chess->board[move->from.y][move->from.x] = '.';
	if (move->piece < 'a' || move->piece > 'h')
		chess->board[move->dest.y][move->dest.x] = move->piece + define_move(chess);
	else
		chess->board[move->dest.y][move->dest.x] = 'P' + define_move(chess);
}