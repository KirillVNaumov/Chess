#include "chess.h"

void		update_pawn_moves(t_chess *chess)
{
	if (chess->info.white_pawns[0] == 1)
		chess->info.white_pawns[0] = 2;
	if (chess->info.white_pawns[1] == 1)
		chess->info.white_pawns[1] = 2;
	if (chess->info.white_pawns[2] == 1)
		chess->info.white_pawns[2] = 2;
	if (chess->info.white_pawns[3] == 1)
		chess->info.white_pawns[3] = 2;
	if (chess->info.white_pawns[4] == 1)
		chess->info.white_pawns[4] = 2;
	if (chess->info.white_pawns[5] == 1)
		chess->info.white_pawns[5] = 2;
	if (chess->info.white_pawns[6] == 1)
		chess->info.white_pawns[6] = 2;
	if (chess->info.white_pawns[7] == 1)
		chess->info.white_pawns[7] = 2;
	if (chess->info.black_pawns[7] == 1)
		chess->info.black_pawns[7] = 2;
	if (chess->info.black_pawns[6] == 1)
		chess->info.black_pawns[6] = 2;
	if (chess->info.black_pawns[5] == 1)
		chess->info.black_pawns[5] = 2;
	if (chess->info.black_pawns[4] == 1)
		chess->info.black_pawns[4] = 2;
	if (chess->info.black_pawns[3] == 1)
		chess->info.black_pawns[3] = 2;
	if (chess->info.black_pawns[2] == 1)
		chess->info.black_pawns[2] = 2;
	if (chess->info.black_pawns[1] == 1)
		chess->info.black_pawns[1] = 2;
	if (chess->info.black_pawns[0] == 1)
		chess->info.black_pawns[0] = 2;
}

void		set_pawns_moves(t_chess *chess, t_move *move)
{
	if (move->dest.y == 4 && chess->to_move % 2 == 1)
	{
		if (chess->board[6][0] == 'P' && chess->info.white_pawns[0] == 0 && move->piece == 'a')
			chess->info.white_pawns[0] = 1;
		if (chess->board[6][1] == 'P' && chess->info.white_pawns[1] == 0 && move->piece == 'b')
			chess->info.white_pawns[1] = 1;
		if (chess->board[6][2] == 'P' && chess->info.white_pawns[2] == 0 && move->piece == 'c')
			chess->info.white_pawns[2] = 1;
		if (chess->board[6][3] == 'P' && chess->info.white_pawns[3] == 0 && move->piece == 'd')
			chess->info.white_pawns[3] = 1;
		if (chess->board[6][4] == 'P' && chess->info.white_pawns[4] == 0 && move->piece == 'e')
			chess->info.white_pawns[4] = 1;
		if (chess->board[6][5] == 'P' && chess->info.white_pawns[5] == 0 && move->piece == 'f')
			chess->info.white_pawns[5] = 1;
		if (chess->board[6][6] == 'P' && chess->info.white_pawns[6] == 0 && move->piece == 'g')
			chess->info.white_pawns[6] = 1;
		if (chess->board[6][7] == 'P' && chess->info.white_pawns[7] == 0 && move->piece == 'h')
			chess->info.white_pawns[7] = 1;
	}
	if (move->dest.y == 4 && chess->to_move % 2 == 0)
	{
		if (chess->board[6][7] == 'p' && chess->info.black_pawns[7] == 0 && move->piece == 'a')
			chess->info.black_pawns[7] = 1;
		if (chess->board[6][6] == 'p' && chess->info.black_pawns[6] == 0 && move->piece == 'b')
			chess->info.black_pawns[6] = 1;
		if (chess->board[6][5] == 'p' && chess->info.black_pawns[5] == 0 && move->piece == 'c')
			chess->info.black_pawns[5] = 1;
		if (chess->board[6][4] == 'p' && chess->info.black_pawns[4] == 0 && move->piece == 'd')
			chess->info.black_pawns[4] = 1;
		if (chess->board[6][3] == 'p' && chess->info.black_pawns[3] == 0 && move->piece == 'e')
			chess->info.black_pawns[3] = 1;
		if (chess->board[6][2] == 'p' && chess->info.black_pawns[2] == 0 && move->piece == 'f')
			chess->info.black_pawns[2] = 1;
		if (chess->board[6][1] == 'p' && chess->info.black_pawns[1] == 0 && move->piece == 'g')
			chess->info.black_pawns[1] = 1;
		if (chess->board[6][0] == 'p' && chess->info.black_pawns[0] == 0 && move->piece == 'h')
			chess->info.black_pawns[0] = 1;
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

void		apply_en_passant(t_chess *chess, t_move *move)
{
	chess->board[move->from.y][move->from.x] = '.';
	chess->board[move->dest.y + 1][move->dest.x] = '.';
	chess->board[move->dest.y][move->dest.x] = 'P' + define_move(chess);
}

void        apply_move(t_chess *chess, t_move *move)
{
	if (move->kingside_castle == 1)
		apply_kingside_castle(chess);
	if (move->queenside_castle == 1)
		apply_queenside_castle(chess);
	if (move->en_passant == 1)
		apply_en_passant(chess, move);
	if (move->queenside_castle || move->kingside_castle || move->en_passant)
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
	// ft_printf("chess->info.white_pawns[0] = %d\n", chess->info.white_pawns[0]);
	// ft_printf("chess->info.white_pawns[1] = %d\n", chess->info.white_pawns[1]);
	// ft_printf("chess->info.white_pawns[2] = %d\n", chess->info.white_pawns[2]);
	// ft_printf("chess->info.white_pawns[3] = %d\n", chess->info.white_pawns[3]);
	// ft_printf("chess->info.white_pawns[4] = %d\n", chess->info.white_pawns[4]);
	// ft_printf("chess->info.white_pawns[5] = %d\n", chess->info.white_pawns[5]);
	// ft_printf("chess->info.white_pawns[6] = %d\n", chess->info.white_pawns[6]);
	// ft_printf("chess->info.white_pawns[7] = %d\n", chess->info.white_pawns[7]);
	// ft_printf("chess->info.black_pawns[7] = %d\n", chess->info.black_pawns[7]);
	// ft_printf("chess->info.black_pawns[6] = %d\n", chess->info.black_pawns[6]);
	// ft_printf("chess->info.black_pawns[5] = %d\n", chess->info.black_pawns[5]);
	// ft_printf("chess->info.black_pawns[4] = %d\n", chess->info.black_pawns[4]);
	// ft_printf("chess->info.black_pawns[3] = %d\n", chess->info.black_pawns[3]);
	// ft_printf("chess->info.black_pawns[2] = %d\n", chess->info.black_pawns[2]);
	// ft_printf("chess->info.black_pawns[1] = %d\n", chess->info.black_pawns[1]);
	// ft_printf("chess->info.black_pawns[0] = %d\n", chess->info.black_pawns[0]);
}