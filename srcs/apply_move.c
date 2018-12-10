#include "chess.h"

void        apply_move(t_chess *chess, t_move *move)
{
	if (move->kingside_castle == 1)
		apply_kingside_castle(chess);
	if (move->queenside_castle == 1)
		apply_queenside_castle(chess);
	if (move->queenside_castle || move->kingside_castle)
		return ;
	chess->board[move->from.y][move->from.x] = '.';
	if (move->piece < 'a' || move->piece > 'h')
		chess->board[move->dest.y][move->dest.x] = move->piece + define_move(chess);
	else
		chess->board[move->dest.y][move->dest.x] = 'P' + define_move(chess);
	if (move->promotion != '-')
		chess->board[move->dest.y][move->dest.x] = move->promotion + define_move(chess);
	if (chess->board[7][0] == '.' && chess->to_move % 2 == 1)
		chess->rook_a1_move = 1;
	if (chess->board[7][7] == '.' && chess->to_move % 2 == 1)
		chess->rook_h1_move = 1;
	if (chess->board[7][7] == '.' && chess->to_move % 2 == 0)
		chess->rook_a8_move = 1;
	if (chess->board[7][0] == '.' && chess->to_move % 2 == 0)
		chess->rook_h8_move = 1;
	if (chess->board[7][4] == '.' && chess->to_move % 2 == 1)
		chess->white_king_move = 1;
	if (chess->board[7][3] == '.' && chess->to_move % 2 == 0)
		chess->black_king_move = 1;
}