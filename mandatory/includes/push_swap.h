#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H
#include <limits.h>

typedef struct s_stk
{
	int				value;
	int				index;
	struct s_list	*next;
}				t_stk;

int rrr(t_stk **stka , t_stk **stkb );
int sb (t_stk **stk_b);
int sa (t_stk **stk_a);
int ss(t_stk **stka , t_stk **stkb );
int pa (t_stk **stka , t_stk **stkb);
int pb (t_stk **stka , t_stk **stkb);
int rra(t_stk **stka);
int rrb(t_stk **stkb);
int rr (t_stk **stka, t_stk **stkb);
int ra (t_stk **stka);
int rb (t_stk **stkb);
#endif

