/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksohail- <ksohail-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 10:36:36 by ksohail-          #+#    #+#             */
/*   Updated: 2024/01/17 15:51:15 by ksohail-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*get_the_cheapest(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	make_a_up(t_stack **a, t_stack *cheapestT, t_stack *cheapest, int size)
{
	int i;
	int l;
	int k;

	i = cheapestT->how_far_from_the_midline;
	l = cheapest->how_far_from_the_midline;
	k = size / 5;
	// printf("!!!!!!!!!!!!!!!!!!!!-%d-%d-!!!!!!!!!!!!!!!!!!!!\n", cheapest->above_the_midline, cheapestT->target_node->above_the_midline);
	if (i != 0 && i < k && l > k)
	{
		while (i)
		{
			ra(a, false);
			i--;
		}
	}
}

void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest, int size)
{
	while (*a != cheapest->target_node && *b != cheapest)
		rr(a, b, false);
	set_the_position(*a);
	set_the_position(*b);
}

void	revers_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest, int size)
{
	while (*a != cheapest->target_node && *b != cheapest)
		rrr(a, b, false);
	set_the_position(*a);
	set_the_position(*b);
}

void	finish_rotation(t_stack **stack, t_stack *top_node, char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_the_midline)
				ra(stack, false);
			else
				rra(stack, false);
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_the_midline)
				rb(stack, false);
			else
				rrb(stack, false);
		}
	}
}


// void	move_nodes(t_stack **a, t_stack **b, int size)
// {
// 	t_stack	*cheapest;
	
// 	cheapest = get_the_cheapest(*b);
// 	if (cheapest->above_the_midline && cheapest->target_node->above_the_midline)
// 		rotate_both(a, b, cheapest, size);
// 	else if (!cheapest->above_the_midline
// 		&& !cheapest->target_node->above_the_midline)
// 		revers_rotate_both(a, b, cheapest, size);
// 	finish_rotation(b, cheapest, 'b');
// 	finish_rotation(a, cheapest->target_node, 'a');
// 	pa(b, a, false);
// }

void	move_nodes(t_stack **a, t_stack **b, int size)
{
	t_stack	*cheapest;

	cheapest = get_the_cheapest(*b);
	// if (cheapest->above_the_midline
	// 	&& !cheapest->target_node->above_the_midline && cheapest->target_node->the_3_4_line
	// 	&& cheapest->the_1_4_line)
	// 	{
	// 		// ft_printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!HERE!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
	// 		make_a_up(a, cheapest->target_node, cheapest, size);
	// 	}
	// printf("-%d-%d-\n", cheapest->above_the_midline, cheapest->target_node->above_the_midline);
	if (cheapest->above_the_midline && cheapest->target_node->above_the_midline)
		rotate_both(a, b, cheapest, size);
	else if (!cheapest->above_the_midline
		&& !cheapest->target_node->above_the_midline)
		revers_rotate_both(a, b, cheapest, size);
	finish_rotation(b, cheapest, 'b');
	finish_rotation(a, cheapest->target_node, 'a');
	pa(b, a, false);
}
