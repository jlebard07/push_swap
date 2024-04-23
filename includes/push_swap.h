/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlebard <jlebard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 13:20:53 by jlebard           #+#    #+#             */
/*   Updated: 2024/04/22 15:43:24 by jlebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"
# include "ft_printf/libft/libft.h"
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


//check des erreurs
bool			ft_check_error_int_array(int *int_arr);
bool			chek_error_str(char *str);
//initialisation des piles
t_stack_node	*stack_init(int *array, int size);
int				*split_and_check(char	*str);
void			set_pile(t_stack_node **a, t_stack_node **b);
//operations sur les piles
void			current_position(t_stack_node **stack);
size_t			pile_size(t_stack_node *stack);
bool			is_sorted(t_stack_node *stack);
void			target_node(t_stack_node **a, t_stack_node **b);
void			who_cheapest(t_stack_node **stack);
void			set_price(t_stack_node **a, t_stack_node **b)
//commandes
void			pa(t_stack_node **a, t_stack_node **b);
void			pb(t_stack_node **a, t_stack_node **b);
void			sa(t_stack_node **a);
void			sb(t_stack_node **b);
void			ss(t_stack_node **a, t_stack_node **b);
void			ra(t_stack_node a);
void			rb(t_stack_node b);
void			rr(t_stack_node a, t_stack_node b);
void			rra(t_stack_node a);
void			rrb(t_stack_node b);
void			rrr(t_stack_node a, t_stack_node b);
//algorithmie
void			sort_3(t_stack_node **stack);

#endif
