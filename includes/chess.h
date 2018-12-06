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

# define CLEAN "\e[1;1H\e[2J"
# define CRED  "\x1B[31m"
# define CBLUE  "\x1B[34m"
# define CPINK  "\x1B[35m"
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

typedef struct          s_notation
{
    char                **move;
    struct s_notation   *next;
}                       t_notation;

typedef struct          s_chess
{
    char                **board;
    int                 to_move;
    int                 number_of_moves;
    int                 type_of_board;
    t_notation          notation;
}                       t_chess;

typedef struct          s_move
{
    int                 if_check;
    int                 if_mate;
    int                 if_take;
    int                 if_promote;
    int                 kingside_castle;
    int                 queenside_castle;
}                       t_move;

void                    header();
void                    draw_board(t_chess chess);
void	                create_board(t_chess *chess);
void	                game(t_chess *chess);

#endif
