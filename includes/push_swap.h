/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlebard <jlebard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 11:44:44 by jlebard            #+#    #+#             */
/*   Updated: 2024/05/23 11:44:44 by jlebard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>

typedef struct node
{	
	int			value;
	int			index;
	int			price;
	bool		cheapest;
	bool		under_median;
	struct node	*previous;
	struct node	*next;
	struct node	*target;
}	t_stack_node;

//split
char			**ft_split(char *s, char c);
//main
int				main(int argc, char **argv);
//errors
bool			check_str(char *str);
bool			check_rep(t_stack_node *stack, int n);
//free
void			free_stack(t_stack_node **stack);
void			error_free(t_stack_node **stack, char **argv, bool nb_argc);
void			free_argv(char **argv);
//utils
t_stack_node	*find_last(t_stack_node *stack);
bool			is_sorted(t_stack_node *stack);
int				pile_size(t_stack_node *stack);
t_stack_node	*find_biggest(t_stack_node *stack);
t_stack_node	*find_smallest(t_stack_node *stack);
t_stack_node	*who_cheapest(t_stack_node *stack);
//commandes
void			sa(t_stack_node **a);
void			sb(t_stack_node **b);
void			ss(t_stack_node **a, t_stack_node **b);
void			pa(t_stack_node **a, t_stack_node **b);
void			pb(t_stack_node **a, t_stack_node **b);
void			rb(t_stack_node **b);
void			ra(t_stack_node **a);
void			rr(t_stack_node **a, t_stack_node **b);
void			rra(t_stack_node **a);
void			rrb(t_stack_node **b);
void			rrr(t_stack_node **a, t_stack_node **b);
//set nodes
void			stack_init(t_stack_node **stack, char **argv,
					bool nb_argc);
void			set_index(t_stack_node *stack);
void			set_price(t_stack_node *a, t_stack_node *b);
void			set_cheapest(t_stack_node *b);
void			set_nodes(t_stack_node *a, t_stack_node *b);
//algo
void			sort_3(t_stack_node **a);
void			push_swap(t_stack_node **a, t_stack_node **b);

#endif
