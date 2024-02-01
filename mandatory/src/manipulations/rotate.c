
int rotate (t_stk **stk)
{
    t_stk *head;
    t_stk *last;
    if(ft_lstsize(*stk)<2)
        return -1;
    head = *stk;
    last = ft_lstlast(head);
    *stk = head->next;
    head->next = NULL;
    last->next = head;
    return 0;
}

int ra (t_stk **stka)
{
    if(rotate(stka) == -1)
        return -1;
    ft_putendl_fd("pa",1);
    return 0;
}
int rb (t_stk **stkb)
{
    if(rotate(stkb) == -1)
        return -1;
    ft_putendl_fd("pb",1);
    return 0;
}

int rr (t_stk **stka, t_stk **stkb)
{
    if((ft_lstsize(*stka)< 2) || (ft_lstsize(*stkb)) < 2)
        return -1;
    rotate(stka);
    rotate(stkb);
    ft_putendl_fd("rr",1);
    return 0;
}