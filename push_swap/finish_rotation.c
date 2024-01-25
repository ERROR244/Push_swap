/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish_rotation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksohail- <ksohail-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 10:36:36 by ksohail-          #+#    #+#             */
/*   Updated: 2024/01/25 13:46:11 by ksohail-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	finish_rotation(t_stack **stack, t_stack *top_node, char stack_name)
{
	if (!top_node)
		return ;
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

int	bigger(t_stack *curr, int value)
{
	int	bigger;

	bigger = 0;
	while (curr)
	{
		if (curr->value > value)
			bigger++;
		curr = curr->next;
	}
	return (bigger);
}

void	set_the_position_index(t_stack *stack)
{
	t_stack	*curr;
	int		midline;
	int		i;
	int		size;

	i = 0;
	if (!stack)
		return ;
	curr = stack;
	size = lstsize(stack);
	midline = size / 2;
	while (stack)
	{
		stack->index_position = i;
		stack->index = (size - bigger(curr, stack->value)) - 1;
		if (i <= midline)
			stack->above_the_midline = true;
		else
			stack->above_the_midline = false;
		stack = stack->next;
		++i;
	}
}

void	set_the_position(t_stack *stack)
{
	int	midline;
	int	i;

	i = 0;
	if (!stack)
		return ;
	midline = lstsize(stack) / 2;
	while (stack)
	{
		stack->index_position = i;
		if (i <= midline)
			stack->above_the_midline = true;
		else
			stack->above_the_midline = false;
		stack = stack->next;
		++i;
	}
}
