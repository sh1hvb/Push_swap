#include "push_swap.h"

static void initialStk(t_stk **stk ,int ac , char **av )
{
    t_stk *lst;
    char **arguments;
    int i;

    i = 0;
    if(ac == 2)
        arguments = ft_split(av[1],' ');
    else
    {
        i = 1;
        arguments = av;
    }
    while(arguments[i])
    {
        lst = ft_lstnew(ft_atoi(arguments[i]));
        ft_lstadd_back(stk , new);
        i++;
    }
    index_stk(stk);
    if(argc == 2)
        ft_free(arguments);
}
static void sortStk(t_stk **stka, t_stk **stkb)
{
    if(ft_lstsize(stka) <= 5)
        simple_sort(stka , stkb);
    else
        bnrSort(stka , stkb);
}

int main(int ac , char **av)
{
    t_stk **stkA;
    t_stk **stkB;

    if(ac < 2)
        return (-1);
    arg_checker(ac, av);
    stkA = (t_stk **)malloc(sizeof(t_stk));
    stkB = (t_stk **)malloc(sizeof(t_stk));
    *stkA = NULL;
    *stkB = NULL;
    initialStk(stkA,ac,av);
    if(sorted(stkA) && !stkB)
    {
        freeStk(stkA);
        freeStk(stkB);
        return 0;
    }
    sortStk(stkA,stkB);
    freeStk(stkA);
    freeStk(stkB);
    return 0;
}