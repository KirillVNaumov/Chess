#include "chess.h"

void        write_to_a_file(int file, char *line, t_chess *chess)
{
    if (chess->number_of_moves % 2 == 1)
    {
        ft_putnbr_fd((chess->number_of_moves / 2) + 1, file);
        ft_putstr_fd(". ", file);
        ft_putstr_fd(line, file);
    }
    else
    {
        ft_putstr_fd(" ", file);
        ft_putstr_fd(line, file);
        ft_putstr_fd("\n", file);
    }
}