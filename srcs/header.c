# include "chess.h"

void    header()
{
    ft_printf("%s", CLEAN);
    ft_printf("############################################################\n");
    ft_printf("#                                                          #\n");
    ft_printf("#    %s*****   *   *   *****   *****   *****%s                 #\n", CTURQ, CWHITE);
    ft_printf("#    %s*       *   *   *       *       *    %s                 #\n", CTURQ, CWHITE);
    ft_printf("#    %s*       *****   *****   *****   *****%s                 #\n", CTURQ, CWHITE);
    ft_printf("#    %s*       *   *   *           *       *%s                 #\n", CTURQ, CWHITE);
    ft_printf("#    %s*****   *   *   *****   *****   *****%s                 #\n", CTURQ, CWHITE);
    ft_printf("#                                                          #\n");
    ft_printf("#  Created by Kirill Naumov <kirill.v.naumov@gmail.com>    #\n");
    ft_printf("#                                                          #\n");
    ft_printf("############################################################\n\n");
}
