/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_the_stacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksohail- <ksohail-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:34:46 by ksohail-          #+#    #+#             */
/*   Updated: 2024/01/17 15:52:43 by ksohail-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_the_position(t_stack *stack)
{
	int	midline;
	int	i;
	int the_3_4_line;
	int	the_1_4_line;
	int how_far;

	i = 0;
	if (!stack)
		return;
	midline = lstsize(stack) / 2;
	the_3_4_line = midline + (midline / 2);
	the_1_4_line = midline - (midline / 2);
	stack->how_far_from_the_midline = midline;
	stack->the_3_4_line = 0;
	stack->the_1_4_line = 0;
	while (stack)
	{
		stack->index_position = i;
		if (i <= midline)
		{
			stack->the_3_4_line = false;
			stack->above_the_midline = true;
			if (stack->prev != NULL)
			{
				how_far = stack->prev->how_far_from_the_midline - 1;
				stack->how_far_from_the_midline = how_far;
				if (i >= the_1_4_line && i < midline)
					stack->the_1_4_line = true;
				if (i >= midline)
					stack->the_1_4_line = false;
			}
		}
		else
		{
			stack->the_1_4_line = false;
			stack->above_the_midline = false;
			if (stack->prev != NULL)
			{
				how_far = stack->prev->how_far_from_the_midline + 1;
				stack->how_far_from_the_midline = how_far;
				if (i <= the_3_4_line)
					stack->the_3_4_line = true;
				if (i > the_3_4_line)
					stack->the_3_4_line = false;
			}
		}
		stack = stack->next;
		++i;
	}
}

void	set_target_node(t_stack *a, t_stack *b)
{
	t_stack	*target_node;
	t_stack	*curr_a;
	long	best_match_index;

	while (b)
	{
		best_match_index = LONG_MAX;
		curr_a = a;
		while (curr_a)
		{
			if (curr_a->value > b->value && curr_a->value < best_match_index)
			{
				best_match_index = curr_a->value;
				target_node = curr_a;
			}
			curr_a = curr_a->next;
		}
		if (best_match_index == LONG_MAX)
			b->target_node = smallest_node(a);
		else
			(b)->target_node = target_node;
		b = (b)->next;
	}
}

void	set_price(t_stack *a, t_stack *b)
{
	int	len_a;
	int	len_b;

	if (!a || !b)
		return ;
	len_a = lstsize(a);
	len_b = lstsize(b);
	while (b)
	{
		b->push_price = b->index_position;
		if (!(b->above_the_midline))
			b->push_price = len_b - (b->index_position);
		if (b->target_node->above_the_midline)
			b->push_price += b->target_node->index_position;
		else
			b->push_price += len_a - (b->target_node->index_position);
		b = b->next;
	}
}

void	set_cheapest(t_stack *b)
{
	t_stack	*best_match_node;
	long	best_match_value;

	if (NULL == b)
		return ;
	best_match_value = LONG_MAX;
	while (b)
	{
		if (b->push_price < best_match_value)
		{
			best_match_value = b->push_price;
			best_match_node = b;
		}
		b = b->next;
	}
	best_match_node->cheapest = true;
}

void	set_the_stacks(t_stack *a, t_stack *b)
{
	set_the_position(a);
	set_the_position(b);
	set_target_node(a, b);
	set_price(a, b); 
	set_cheapest(b);
	// t_stack *curr = a;
	// while (curr)
	// {
	// 	printf("value->%d-above_the_midline->%d-above_the_1_4_line->%d-above_the_3_4_line->%d\n", 
	// 			curr->value, curr->above_the_midline, curr->the_1_4_line, curr->the_3_4_line);
	// 	curr = curr->next;
	// }
}
