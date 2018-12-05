# include "chess.h"

void    header()
{
    ft_printf("%s", CLEAN);
    ft_printf("############################################################\n");
    ft_printf("#                                                          #\n");
    ft_printf("#                                                          #\n");
    ft_printf("#                                                          #\n");
    ft_printf("#                                                          #\n");
    ft_printf("#                                                          #\n");
    ft_printf("#                                                          #\n");
    ft_printf("#  Created by Kirill Naumov <kirill.v.naumov@gmail.com>    #\n");
    ft_printf("#                                                          #\n");
    ft_printf("############################################################\n");

    ft_printf("%s%s%s\n", LT, HL, RT);
    ft_printf("%s%c%s\n", VL, 'P', VL);
    ft_printf("%s%s%s\n\n", LB, HL, RB);

    ft_printf("%s%s123", CBWHITE, CBLACK);

}