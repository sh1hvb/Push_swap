
int reverserotate(t_stk **stk)
{
    t_stk *head;
    t_stk *last;

    if(ft_lstsize(*stk) < 2)
        return -1;
    head =*stk;
    last - ft_lstlast(head);
    while(head)
    {
        if(head->next->next== NULL)
        {
            head->next = NULL;
            break ;
        }
        head = head->next;
    }
    last->next = *stk;
    *stk = last;
    return 0;
}

int rra(t_stk **stka)
{
    if(reverserotate(stka) == -1)
        return -1;
    ft_putendl_fd("rra",1);
    return 0;
}
int rrb(t_stk **stkb)
{
    if(reverserotate(stkb) == -1)
        return -1;
    ft_putendl_fd("rrb",1);
    return 0;
}

int rrr(t_stk **stka , t_stk **stkb )
{
    if((ft_lstsize(*stka) < 2) || (ft_lstsize(*stkb)))
        return -1;
    reverserotate(stka);
    reverserotate(stkb);
    ft_putendl_fd("rrr",1);
    return 0;
}