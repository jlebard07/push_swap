/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlebard <jlebard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 13:20:53 by jlebard           #+#    #+#             */
/*   Updated: 2024/05/16 16:18:03 by jlebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>

typedef struct Stack
{
	int				data;
	int				index;
	int				price;
	bool			cheapest;
	bool			under_avg_rank;
	struct Stack	*target;
	struct Stack	*previous;
	struct Stack	*next;
}	t_stack_node;
//utils
char			**ft_split(char const *s, char c);
void			ft_putstr_fd(char *s, int fd);
int				ft_atoi(const char	*str);
//gestion des erreurs et free
bool			ft_check_error_repetition(t_stack_node *stack, int n);
bool			ft_check_error_str(char *str);
void			free_stack(t_stack_node **stack);
void			free_argv(char	**argv);
void			free_error(t_stack_node **stack, char **argv, bool n_argc);
//initialisation des piles
void			stack_init(t_stack_node **a, char **argv, bool n_argc);
char			**split_and_check(char **argv);
void			set_pile_utils(t_stack_node *a, t_stack_node *b);
//operations sur les piles
void			current_position(t_stack_node *stack);
size_t			pile_size(t_stack_node *stack);
bool			is_sorted(t_stack_node *stack);
void			target_node(t_stack_node *a, t_stack_node *b);
void			set_cheapest(t_stack_node *stack);
void			set_price(t_stack_node *a, t_stack_node *b);
t_stack_node	*who_cheapest(t_stack_node *stack);
t_stack_node	*find_lowest(t_stack_node *stack);
t_stack_node	*find_last(t_stack_node *stack);
//commandes
void			pa(t_stack_node **a, t_stack_node **b);
void			pb(t_stack_node **a, t_stack_node **b);
void			sa(t_stack_node **a);
void			sb(t_stack_node **b);
void			ss(t_stack_node **a, t_stack_node **b);
void			ra(t_stack_node **a);
void			rb(t_stack_node **b);
void			rr(t_stack_node **a, t_stack_node **b);
void			rra(t_stack_node **a);
void			rrb(t_stack_node **b);
void			rrr(t_stack_node **a, t_stack_node **b);
//algorithmie
void			sort_3(t_stack_node **stack);
void			ft_pushswap(t_stack_node **a, t_stack_node **b);

#endif
