
int push (t_stk **dest, t_stk **src)
{
    t_stk *tmp;
    t_stk *hsrc;
    t_stk *hdest;

    if(ft_lstsize(*src) == 0)
        return -1;
    hdest = *dest;
    hsrc = *src;
    tmp = hsrc;
    hsrc = hsrc->next;
    *src = hsrc;
    if(!hdest)
    {
        hdest = tmp;
        hdest->next = NULL;
        *dest = hdest;
    }
    else{
        tmp->next = hdest;
        *dest = tmp;
    }
    return 0;
}

int pa (t_stk **stka , t_stk **stkb)
{
    if(push(stka,stkb) == -1)
        return -1;
    ft_putendl_fd("pa",1);
    return 0
}
int pb (t_stk **stka , t_stk **stkb)
{
    if(push(stkb,stka) == -1)
        return -1;
    ft_putendl_fd("pb",1);
    return 0
}