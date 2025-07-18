/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaliev <ilaliev@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 13:32:31 by ilaliev           #+#    #+#             */
/*   Updated: 2025/07/18 17:28:29 by ilaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// libs
# include "../ft_printf/ft_printf.h"
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>

typedef struct s_stack
{
	int				number;
	int				pos;
	int				push_cost;
	bool			below_median;
	struct s_stack	*target;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

//	commands
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack**b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);

//	functions
t_stack	*last_node(t_stack *first);
int		no_duplicates(t_stack *a, int num);
void	free_list(t_stack **a);
void	free_all(t_stack **a, char **av, int ac, bool error);
void	set_taget_nodes(t_stack **a, t_stack **b);
void	set_positions(t_stack **stack);
void	calc_cost(t_stack **a, t_stack **b);
t_stack	*find_cheapest(t_stack *b);
void	sort_stacks(t_stack **a, t_stack **b);
t_stack	*find_biggest(t_stack *a);
t_stack	*find_smallest(t_stack *a);
void	sort_three(t_stack **a);
char	**split(char *s, char c);
int		check_syntax(char *str);
long	ft_atol(char *str);
int		stack_a(t_stack **a, char **av, int ac);
int		stack_len(t_stack **a);
int		stack_sorted(t_stack **a);
void	rotate_till_done(t_stack **a);

#endif
