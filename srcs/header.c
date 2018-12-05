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

    int     i;

    i = 0;
    while (i++ < 4)
    {
        ft_printf("%s%s        %s%s        ", CBWHITE, CBLACK, CBBLACK, CWHITE);
        ft_printf("%s%s        %s%s        ", CBWHITE, CBLACK, CBBLACK, CWHITE);
        ft_printf("%s%s        %s%s        ", CBWHITE, CBLACK, CBBLACK, CWHITE);
        ft_printf("%s%s        %s%s        \n", CBWHITE, CBLACK, CBBLACK, CWHITE);
    }
    i = 0;
    while (i++ < 4)
    {
        ft_printf("%s%s        %s%s        ", CBBLACK, CWHITE, CBWHITE, CBLACK);
        ft_printf("%s%s        %s%s        ", CBBLACK, CWHITE, CBWHITE, CBLACK);
        ft_printf("%s%s        %s%s        ", CBBLACK, CWHITE, CBWHITE, CBLACK);
        ft_printf("%s%s        %s%s        \n", CBBLACK, CWHITE, CBWHITE, CBLACK);
    }
    i = 0;
    while (i++ < 4)
    {
        ft_printf("%s%s        %s%s        ", CBWHITE, CBLACK, CBBLACK, CWHITE);
        ft_printf("%s%s        %s%s        ", CBWHITE, CBLACK, CBBLACK, CWHITE);
        ft_printf("%s%s        %s%s        ", CBWHITE, CBLACK, CBBLACK, CWHITE);
        ft_printf("%s%s        %s%s        \n", CBWHITE, CBLACK, CBBLACK, CWHITE);
    }
    i = 0;
    while (i++ < 4)
    {
        ft_printf("%s%s        %s%s        ", CBBLACK, CWHITE, CBWHITE, CBLACK);
        ft_printf("%s%s        %s%s        ", CBBLACK, CWHITE, CBWHITE, CBLACK);
        ft_printf("%s%s        %s%s        ", CBBLACK, CWHITE, CBWHITE, CBLACK);
        ft_printf("%s%s        %s%s        \n", CBBLACK, CWHITE, CBWHITE, CBLACK);
    }
    i = 0;
    while (i++ < 4)
    {
        ft_printf("%s%s        %s%s        ", CBWHITE, CBLACK, CBBLACK, CWHITE);
        ft_printf("%s%s        %s%s        ", CBWHITE, CBLACK, CBBLACK, CWHITE);
        ft_printf("%s%s        %s%s        ", CBWHITE, CBLACK, CBBLACK, CWHITE);
        ft_printf("%s%s        %s%s        \n", CBWHITE, CBLACK, CBBLACK, CWHITE);
    }
    i = 0;
    while (i++ < 4)
    {
        ft_printf("%s%s        %s%s        ", CBBLACK, CWHITE, CBWHITE, CBLACK);
        ft_printf("%s%s        %s%s        ", CBBLACK, CWHITE, CBWHITE, CBLACK);
        ft_printf("%s%s        %s%s        ", CBBLACK, CWHITE, CBWHITE, CBLACK);
        ft_printf("%s%s        %s%s        \n", CBBLACK, CWHITE, CBWHITE, CBLACK);
    }
    i = 0;
    while (i++ < 4)
    {
        ft_printf("%s%s        %s%s        ", CBWHITE, CBLACK, CBBLACK, CWHITE);
        ft_printf("%s%s        %s%s        ", CBWHITE, CBLACK, CBBLACK, CWHITE);
        ft_printf("%s%s        %s%s        ", CBWHITE, CBLACK, CBBLACK, CWHITE);
        ft_printf("%s%s        %s%s        \n", CBWHITE, CBLACK, CBBLACK, CWHITE);
    }
    i = 0;
    while (i++ < 4)
    {
        ft_printf("%s%s        %s%s        ", CBBLACK, CWHITE, CBWHITE, CBLACK);
        ft_printf("%s%s        %s%s        ", CBBLACK, CWHITE, CBWHITE, CBLACK);
        ft_printf("%s%s        %s%s        ", CBBLACK, CWHITE, CBWHITE, CBLACK);
        ft_printf("%s%s        %s%s         %s\n", CBBLACK, CWHITE, CBWHITE, CBLACK, CBBLACK);
    }
}