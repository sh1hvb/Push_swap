

static t_stk * next_min(t_stk **stk)
{
    t_stk *head;
    t_stk *min;
    int has_min;

    min = NULL;
    has_min = 0;
    head = *stk;
    if(head)
    {
        while(head)
        {
            if((head->index == -1) && (!has_min || head->value < min->value))
            {
                min = head;
                has_min = 1;
            }
            head = head->next;
        }
    }
    return min;
}

void add_index(t_stk **stk)
{
    t_stk *head;
    int index;
    index = -1;
    head = next_min(stk);
    while(head)
    {
        head->index = ++index;
        head = next_min(stk);
    }
}