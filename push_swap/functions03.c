/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions03.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksohail- <ksohail-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:12:41 by ksohail-          #+#    #+#             */
/*   Updated: 2024/01/25 13:46:16 by ksohail-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*smallest_node(t_stack *stack)
{
	t_stack	*smallest_node;
	long	smallest;

	if (NULL == stack)
		return (NULL);
	smallest = LONG_MAX;
	while (stack)
	{
		if (stack->value < smallest)
		{
			smallest = stack->value;
			smallest_node = stack;
		}
		stack = stack->next;
	}
	return (smallest_node);
}

long	*error_handel(char **argv)
{
	long	*values;
	int		i;
	int		l;

	i = 0;
	l = 0;
	while (argv[l])
		l++;
	if (errors0(argv) == 0)
		return (NULL);
	values = malloc(sizeof(long *) * (l));
	if (!values)
		return (NULL);
	while (i < l)
	{
		values[i] = ft_atol(argv[i]);
		i++;
	}
	if (errors1(values, l) == 0)
	{
		free(values);
		return (NULL);
	}
	return (values);
}

t_stack	*return_node(t_stack *stack, int index)
{
	while (stack)
	{
		if (stack->index == index)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

int	function(t_stack **a, t_stack **b, int size_push, int last_size)
{
	t_stack	*curr;
	int		mid;

	mid = ((size_push - last_size) / 2) + last_size;
	curr = *a;
	while (curr)
	{
		if ((curr)->index < size_push)
		{
			set_the_position(*a);
			finish_rotation(a, curr, 'a');
			pb(a, b, false);
			if ((*b)->index < mid)
				rb(b, false);
			curr = *a;
		}
		else
			curr = (curr)->next;
	}
	return (size_push);
}

t_stack	*is_it_in(t_stack *b, int index)
{
	while (b)
	{
		if (b->index == index)
			return (b);
		b = b->next;
	}
	return (NULL);
}
