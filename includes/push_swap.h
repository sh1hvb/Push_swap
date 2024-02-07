
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

// Stack
typedef struct s_stk
{
	int				value;
	int				index;
	struct s_stk	*next;
}					t_stk;

// Util functions
int					do_commands(char *line, t_stk **stack_a, t_stk **stack_b);
t_stk				*ft_lstnew(int value);
t_stk				*ft_lstlast(t_stk *head);
void				ft_lstadd_front(t_stk **stack, t_stk *new);
void				ft_lstadd_back(t_stk **stack, t_stk *new);
void				printList(t_stk *head);
int					ft_lstsize(t_stk *head);
int					get_min(t_stk **stack, int val);


void				ft_error(char *msg);
void				ft_check_args(int argc, char **argv);
int					is_sorted(t_stk **stack);
int					get_distance(t_stk **stack, int index);
void				top(t_stk **stack, int distance);
void				free_stack(t_stk **stack);
void				ft_free(char **str);

void				radix_sort(t_stk **stack_a, t_stk **stack_b);
void				simple_sort(t_stk **stack_a, t_stk **stack_b);
void 				sort_3(t_stk **stack_a);
void			sort_4(t_stk **stack_a, t_stk **stack_b);



void				index_stack(t_stk **stack);

// Instruction functions
int					swap(t_stk **stack);
int					push(t_stk **stack_to, t_stk **stack_from);
int					rotate(t_stk **stack);
int					reverseRotate(t_stk **stack);

int					sa(t_stk **stack_a);
int					sb(t_stk **stack_b);
int					ss(t_stk **stack_a, t_stk **stack_b);
int					pa(t_stk **stack_a, t_stk **stack_b);
int					pb(t_stk **stack_b, t_stk **stack_a);
int					ra(t_stk **stack_a);
int					rb(t_stk **stack_b);
int					rr(t_stk **stack_a, t_stk **stack_b);
int					rra(t_stk **stack_a);
int					rrb(t_stk **stack_b);
int					rrr(t_stk **stack_a, t_stk **stack_b);
//Bonus

int process_sa(t_stk **stack_a);
int process_sb(t_stk **stack_b) ;
int	process_ss(t_stk **stack_a, t_stk **stack_b);
int process_pa(t_stk **stack_a, t_stk **stack_b);
int process_pb(t_stk **stack_b, t_stk **stack_a);
int process_rb(t_stk **stack_b);
int process_ra(t_stk **stack_a);
int process_rr(t_stk **stack_a, t_stk **stack_b);
int process_rra(t_stk **stack_a);
int process_rrb(t_stk **stack_b);
int process_rrr(t_stk **stack_a, t_stk **stack_b); 
#endif
