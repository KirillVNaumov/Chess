/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_mate.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knaumov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 16:32:36 by knaumov           #+#    #+#             */
/*   Updated: 2018/12/04 16:34:36 by knaumov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHESS_H
# define CHESS_H

# include "../libft/libft.h"

# include <dirent.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define CLEAN "\e[1;1H\e[2J"
# define CRED  "\x1B[31m"
# define CBLUE  "\x1B[34m"
# define CPINK  "\x1B[35m"
# define CTURQ  "\x1B[36m"
# define CWHITE  "\x1B[39m"
# define CBLACK  "\x1B[30m"
# define CBBLUE "\x1B[46m"
# define CBYELLOW "\x1B[43m"
# define CBBLACK "\x1B[40m"
# define CBWHITE  "\x1B[47m"

# define RB "\e(0\x6a\e(B" // 188 Right Bottom corner
# define RT "\e(0\x6b\e(B" // 187 Right Top corner
# define LT "\e(0\x6c\e(B" // 201 Left Top cornet
# define LB "\e(0\x6d\e(B" // 200 Left Bottom corner
# define MC "\e(0\x6e\e(B" // 206 Midle Cross
# define HL "\e(0\x71\e(B" // 205 Horizontal Line
# define LC "\e(0\x74\e(B" // 204 Left Cross
# define RC "\e(0\x75\e(B" // 185 Right Cross
# define BC "\e(0\x76\e(B" // 202 Bottom Cross
# define TC "\e(0\x77\e(B" // 203 Top Cross
# define VL "\e(0\x78\e(B" // 186 Vertical Line

typedef struct          s_point
{
    int                 x;
    int                 y;
}                       t_point;

typedef struct          s_notation
{
    char                *move;
    struct s_notation   *next;
}                       t_notation;

typedef struct          s_matrices
{
    char                **board;
    struct s_matrices   *next;
}                       t_matrices;

typedef struct          s_info
{
    int                 white_pawns[8];
    int                 black_pawns[8];
    int                 rook_a8_move;
    int                 rook_h8_move;
    int                 rook_a1_move;
    int                 rook_h1_move;
    int                 black_king_move;
    int                 white_king_move;
    t_point             black_king_pos;
    t_point             white_king_pos;
}                       t_info;

typedef struct          s_chess
{
    char                **board;
    int                 to_move;
    int                 number_of_moves;
    int                 type_of_board;
    t_notation          notation;
    t_info              info;
}                       t_chess;

typedef struct          s_move
{
    t_point             from;
    t_point             dest;
    char                piece;
    char                specification_letter;
    char                specification_number;
    int                 if_check;
    int                 if_mate;
    int                 if_takes;
    char                promotion;
    int                 kingside_castle;
    int                 queenside_castle;
    int                 en_passant;
}                       t_move;

// DRAWING
void                    header();
void                    draw_board(t_chess chess);

// CREATING THE BOARD
void	                create_board(t_chess *chess);
void                    reverse_board(t_chess *chess);

//CHECKING INPUT
int                     parsing_input(char *line, t_move *move, t_chess *chess);
int                     check_if_valid(t_chess *chess, t_move *move);

// CHECKING MOVES
int                     check_rook_move(t_chess *chess, t_move *move, int i, int j);
int                     check_bishop_move(t_chess *chess, t_move *move, int i, int j);
int                     check_queen_move(t_chess *chess, t_move *move, int i, int j);
int                     check_king_move(t_move *move, int i, int j);
int                     check_pawn_move(t_move *move, int i, int j);
int                     check_knight_move(t_move *move, int i, int j);

// CHECKING IF CHECK
int                     check(t_chess *chess, t_move *move, char *line);
int             		check_for_check(char **board, int add, t_point king, int move);
int			            check_king_if_hit(char **board, t_point tracker, t_point king);
int			            check_knight_if_hit(char **board, t_point tracker, t_point king);
int			            check_pawn_if_hit(t_point tracker, t_point king, int move, char king_piece);
int     		    	check_bishop_if_hit(char **board, t_point tracker, t_point king);
int		        	    check_rook_if_hit(char **board, t_point tracker, t_point king);
int                     check_queen_if_hit(char **board, t_point tracker, t_point king);

// CASTLING
int                     check_kingside_castle(t_chess *chess);
int                     check_queenside_castle(t_chess *chess);
char	                **apply_kingside_castle(t_chess *chess,  char **arr);
char	                **apply_queenside_castle(t_chess *chess, char **arr);
// GAME
void	                game(t_chess *chess, int file);
void                    write_to_a_file(int file, char *line, t_chess *chess);
void                    apply_move(t_chess *chess, t_move *move);

//UTILS
int                     define_move(t_chess *chess);
t_point                 find_kings(char **board, char king);
char            		**change_map(t_chess *chess, t_move *move);
char                    **copy_board(char **board);

#endif
