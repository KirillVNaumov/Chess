# include "chess.h"

int		parse_for_piece(char **line, t_move *move)
{
	if (**line == 'R' || **line == 'B' || **line == 'N' || \
		**line == 'K' || **line == 'Q' || (**line >= 'a' && **line <= 'h'))
	{
		move->piece = **line;
		++(*line);
		return (1);
	}
	return (-1);
}

void	parse_for_specification_and_takes(char **line, t_move *move)
{
	if (ft_strlen(*line) > 2)
		if (!(move->piece >= 'a' && move->piece <= 'h'))
			if ((**line >= 'a' && **line <= 'h') || (**line >= '1' && **line <= '8'))
			{
				move->specification = **line;
				++(*line);
			}
	if (**line == 'x')
	{
		move->if_takes = 1;
		++(*line);
	}
}

int		parse_for_destination(char **line, t_move *move)
{
	if ((move->piece >= 'a' && move->piece <= 'h' && \
		move->if_takes == 1) || move->piece < 'a' || move->piece > 'h')
	{
		if (**line >= 'a' && **line <= 'h')
		{
			move->dest.x = (**line) - 'a';
			++(*line);
		}
		else
			return (-1);
	}
	if (**line >= '1' && **line <= '8')
	{
		move->dest.y = (**line) - '0';
		move->dest.y = 8 - move->dest.y;
		++(*line);
	}
	else
		return (-1);
	return (1);
}

void	parse_for_check_and_mate(char **line, t_move *move)
{
	if (**line == '+')
	{
		move->if_check = 1;
		++(*line);
		return ;
	}
	if (**line == '#')
	{
		move->if_mate = 1;
		++(*line);
		return ;
	}
}

int     parsing_input(char *line, t_move *move)
{
    if (!ft_strcmp(line, "O-O"))
		move->kingside_castle = 1;
	if (!ft_strcmp(line, "O-O-O"))
		move->queenside_castle = 1;
	if (move->queenside_castle || move->kingside_castle)
		return (1);
	if (parse_for_piece(&line, move) == -1)
		return (-1);
	parse_for_specification_and_takes(&line, move);
	if (parse_for_destination(&line, move) == -1)
		return (-1);
	parse_for_check_and_mate(&line, move);
	if (*line == '\0')
		return (1);
	return (-1);
}