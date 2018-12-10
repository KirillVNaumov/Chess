#include "chess.h"

void		update_pawn_moves(t_chess *chess)
{
	if (chess->info.a2_move == 1)
		chess->info.a2_move = 2;
	if (chess->info.b2_move == 1)
		chess->info.b2_move = 2;
	if (chess->info.c2_move == 1)
		chess->info.c2_move = 2;
	if (chess->info.d2_move == 1)
		chess->info.d2_move = 2;
	if (chess->info.e2_move == 1)
		chess->info.e2_move = 2;
	if (chess->info.f2_move == 1)
		chess->info.f2_move = 2;
	if (chess->info.g2_move == 1)
		chess->info.g2_move = 2;
	if (chess->info.h2_move == 1)
		chess->info.h2_move = 2;
	if (chess->info.a7_move == 1)
		chess->info.a7_move = 2;
	if (chess->info.b7_move == 1)
		chess->info.b7_move = 2;
	if (chess->info.c7_move == 1)
		chess->info.c7_move = 2;
	if (chess->info.d7_move == 1)
		chess->info.d7_move = 2;
	if (chess->info.e7_move == 1)
		chess->info.e7_move = 2;
	if (chess->info.f7_move == 1)
		chess->info.f7_move = 2;
	if (chess->info.g7_move == 1)
		chess->info.g7_move = 2;
	if (chess->info.h7_move == 1)
		chess->info.h7_move = 2;
}

void		set_pawns_moves(t_chess *chess, t_move *move)
{
	if (move->dest.y == 4 && chess->to_move % 2 == 1)
	{
		if (chess->board[6][0] == 'P' && chess->info.a2_move == 0 && move->piece == 'a')
			chess->info.a2_move = 1;
		if (chess->board[6][1] == 'P' && chess->info.b2_move == 0 && move->piece == 'b')
			chess->info.b2_move = 1;
		if (chess->board[6][2] == 'P' && chess->info.c2_move == 0 && move->piece == 'c')
			chess->info.c2_move = 1;
		if (chess->board[6][3] == 'P' && chess->info.d2_move == 0 && move->piece == 'd')
			chess->info.d2_move = 1;
		if (chess->board[6][4] == 'P' && chess->info.e2_move == 0 && move->piece == 'e')
			chess->info.e2_move = 1;
		if (chess->board[6][5] == 'P' && chess->info.f2_move == 0 && move->piece == 'f')
			chess->info.f2_move = 1;
		if (chess->board[6][6] == 'P' && chess->info.g2_move == 0 && move->piece == 'g')
			chess->info.g2_move = 1;
		if (chess->board[6][7] == 'P' && chess->info.h2_move == 0 && move->piece == 'h')
			chess->info.h2_move = 1;
	}
	if (move->dest.y == 4 && chess->to_move % 2 == 0)
	{
		if (chess->board[6][7] == 'p' && chess->info.a7_move == 0 && move->piece == 'a')
			chess->info.a7_move = 1;
		if (chess->board[6][6] == 'p' && chess->info.b7_move == 0 && move->piece == 'b')
			chess->info.b7_move = 1;
		if (chess->board[6][5] == 'p' && chess->info.c7_move == 0 && move->piece == 'c')
			chess->info.c7_move = 1;
		if (chess->board[6][4] == 'p' && chess->info.d7_move == 0 && move->piece == 'd')
			chess->info.d7_move = 1;
		if (chess->board[6][3] == 'p' && chess->info.e7_move == 0 && move->piece == 'e')
			chess->info.e7_move = 1;
		if (chess->board[6][2] == 'p' && chess->info.f7_move == 0 && move->piece == 'f')
			chess->info.f7_move = 1;
		if (chess->board[6][1] == 'p' && chess->info.g7_move == 0 && move->piece == 'g')
			chess->info.g7_move = 1;
		if (chess->board[6][0] == 'p' && chess->info.h7_move == 0 && move->piece == 'h')
			chess->info.h7_move = 1;
	}
}

void		set_rook_moves(t_chess *chess)
{
	if (chess->board[7][0] == '.' && chess->to_move % 2 == 1)
		chess->info.rook_a1_move = 1;
	if (chess->board[7][7] == '.' && chess->to_move % 2 == 1)
		chess->info.rook_h1_move = 1;
	if (chess->board[7][7] == '.' && chess->to_move % 2 == 0)
		chess->info.rook_a8_move = 1;
	if (chess->board[7][0] == '.' && chess->to_move % 2 == 0)
		chess->info.rook_h8_move = 1;
	if (chess->board[7][4] == '.' && chess->to_move % 2 == 1)
		chess->info.white_king_move = 1;
	if (chess->board[7][3] == '.' && chess->to_move % 2 == 0)
		chess->info.black_king_move = 1;
}

void        apply_move(t_chess *chess, t_move *move)
{
	if (move->kingside_castle == 1)
		apply_kingside_castle(chess);
	if (move->queenside_castle == 1)
		apply_queenside_castle(chess);
	if (move->queenside_castle || move->kingside_castle)
		return ;
	update_pawn_moves(chess);
	set_pawns_moves(chess, move);
	chess->board[move->from.y][move->from.x] = '.';
	if (move->piece < 'a' || move->piece > 'h')
		chess->board[move->dest.y][move->dest.x] = move->piece + define_move(chess);
	else
		chess->board[move->dest.y][move->dest.x] = 'P' + define_move(chess);
	if (move->promotion != '-')
		chess->board[move->dest.y][move->dest.x] = move->promotion + define_move(chess);
	set_rook_moves(chess);
	// ft_printf("chess->info.a2_move = %d\n", chess->info.a2_move);
	// ft_printf("chess->info.b2_move = %d\n", chess->info.b2_move);
	// ft_printf("chess->info.c2_move = %d\n", chess->info.c2_move);
	// ft_printf("chess->info.d2_move = %d\n", chess->info.d2_move);
	// ft_printf("chess->info.e2_move = %d\n", chess->info.e2_move);
	// ft_printf("chess->info.f2_move = %d\n", chess->info.f2_move);
	// ft_printf("chess->info.g2_move = %d\n", chess->info.g2_move);
	// ft_printf("chess->info.h2_move = %d\n", chess->info.h2_move);
	// ft_printf("chess->info.a7_move = %d\n", chess->info.a7_move);
	// ft_printf("chess->info.b7_move = %d\n", chess->info.b7_move);
	// ft_printf("chess->info.c7_move = %d\n", chess->info.c7_move);
	// ft_printf("chess->info.d7_move = %d\n", chess->info.d7_move);
	// ft_printf("chess->info.e7_move = %d\n", chess->info.e7_move);
	// ft_printf("chess->info.f7_move = %d\n", chess->info.f7_move);
	// ft_printf("chess->info.g7_move = %d\n", chess->info.g7_move);
	// ft_printf("chess->info.h7_move = %d\n", chess->info.h7_move);
}