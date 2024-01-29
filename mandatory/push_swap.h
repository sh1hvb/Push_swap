#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H


#include <stdbool.h>
#include <limits.h>

typedef struct s_stk
{
    int nbr;
    int index;
    int steps;
    bool cheapest;
    struct s_stk *target;
    struct s_stk *next;
    struct s_stk *prev;
} t_stk;

#endif