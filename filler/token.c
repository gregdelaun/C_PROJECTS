#include "filler.h"

t_lt do_smaller_token_three(t_lt args, int tmp2)
{
    while(args.i)
    {
        args.j = 0;
        while(args.tok[args.i][args.j])
        {
            if(args.tok[args.i][args.j] == '1' && tmp2 == 0)
            {
                args.bas = args.i;
                tmp2 = 1;
            }
            args.j++;
        }
        args.i--;
    }
    return (args);
}

t_lt do_smaller_token_four(t_lt args, int tmp , int tmp2)
{
    while(args.tok[args.i][args.j])
    {
        args.gauche = check_colom(args,args.j);
        if(tmp2 == 0 && args.gauche != 0)
        {
            if(args.gauche == 999)
                tmp = 0;
            else
                tmp = args.gauche;
            tmp2 = 1;
        }
        args.j++;
    }
    args.gauche = tmp;
    return (args);
}

t_lt do_smaller_token_five(t_lt args, int tmp, int tmp2)
{
    while(args.j)
    {
        args.droite = check_colom_two(args,args.j);
        if(tmp2 == 0 && args.droite != 0)
        {
            if(args.droite == 999)
                tmp = 0;
            else
                tmp = args.droite;
            tmp2 = 1;
        }
        args.j--;
    }
    args.droite = tmp;
    return(args);
}
t_lt do_smaller_token(t_lt args)
{
    static int tmp;
    static int tmp2;

    args.i = 0;
    args.bas = 0;
    args.haut = 0;
    args.gauche = 0;
    args.droite = 0;
    tmp = 0;
    tmp2 = 0;
    args = do_smaller_token_two(args, tmp2);
    args.i--;
    tmp2 = 0;
    args = do_smaller_token_three(args , tmp2);
    args.i = 0;
    args.j = 0;
    tmp2 = 0;
    args = do_smaller_token_four(args, tmp, tmp2);
    args.j--;
    tmp2 = 0;
    args = do_smaller_token_five(args, tmp, tmp2);
    return (args);
}


t_lt do_new_token(t_lt args)
{
    static int i;
    static int tmp;
    static int j;

    i = 0;
    if(!(args.tok2 = malloc(sizeof(args.tok2) * (args.bas - args.haut + 2))))
        exit(0);
    while(i < (args.bas - args.haut + 1))
    {
        if(!(args.tok2[i++] = malloc(sizeof(args.tok2[i]) * (args.droite - args.gauche + 1))))
            exit(0);
    }
    args.tok2[i] = NULL;
    tmp = args.gauche;
    i = 0;
    args = init_variab(args);
    while(args.haut <= args.bas)
    {
        args.gauche = tmp;
        j = 0;
        while(args.gauche <= args.droite)
        {
            args.tok2[i][j++] = args.tok[args.haut][args.gauche];
            args.gauche++;
        }
        i++;
        args.haut++;
    }
    return (args);
}