
int swap (t_stk **stk)
{
    t_stk *head;
    t_stk *next;
    int tmp_val;
    int tmp_i;

    if(ft_lstsize(*stk) < 2)
        return (-1);
    head = *stk;
    next = head->next;
    if(!head && !next)
        ft_error("Error");
    tmp_val = head->value;
    tmp_i = head->index;
    head->value = next->value;
    head->index = next->index;
    next->value = tmp_val;
    next->index = tmp_i;
    return 0;
}
int sa (t_stk **stk_a)
{
    if(swap(stk_a) == -1)
        return (-1);
    ft_putendl_fd("sa", 1);
    return (0);
}
int sb (t_stk **stk_b)
{
    if(swap(stk_b) == -1)
        return (-1);
    ft_putendl_fd("sb", 1);
    return (0);
}
int ss(t_stk **stka , t_stk **stkb )
{
    if((ft_lstsize(*stka) < 2) || ft_lstsize(*stk_b) < 2)
        return -1;
    swap(stka);
    swap(stkb);
    ft_putendl_fd("ss",1);
    return 0;
}
