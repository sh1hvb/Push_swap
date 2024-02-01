#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H


#include <limits.h>

typedef struct s_stk
{
	int				value;
	int				index;
	struct s_list	*next;
}				t_stk;

#endif