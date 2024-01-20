/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions04.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksohail- <ksohail-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 21:10:49 by error01           #+#    #+#             */
/*   Updated: 2024/01/20 18:02:25 by ksohail-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

// void	sort_all(t_stack **a, t_stack **b, int size)
// {
// 	t_stack	*smallest;
// 	int		len_a;

// 	len_a = lstsize(*a);
// 	while (len_a-- > 3)
// 		pb(a, b, false);
// 	sort_three(a);
// 	while (*b)
// 	{
// 		set_the_stacks(*a, *b);
// 		move_nodes(a, b, size);
// 	}
// 	set_the_position(*a);
// 	smallest = smallest_node(*a);
// 	if (smallest->above_the_midline)
// 		while (*a != smallest)
// 			ra(a, false);
// 	else
// 		while (*a != smallest)
// 			rra(a, false);
// }

t_stack *return_node(t_stack *stack, int index)
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
	t_stack *curr;
	int mid = (size_push - last_size) / 2;
	mid = size_push + mid;
	int size;
	
	size = lstsize(*a);
	while (last_size < size_push && size > 3)
	{
		set_the_position(*a);
		curr = return_node(*a, last_size);
		finish_rotation(a, curr, 'a');
		if ((*a)->index < mid || last_size == 0)
			pb(a, b, false);
		else
		{
			pb(a, b, false);
			rb(b, false);
		}
		last_size++;
		size--;
	}
	return (last_size);
}

void	sort_all(t_stack **a, t_stack **b, t_struct *var)
{
	int size_push;
	int last_size;

	last_size = 0;
	size_push = 0;
	set_the_position_index(*a);
	
	// printf("last_size->%d-\n", last_size);
	while (lstsize(*a) > 3)
	{
		size_push += ((lstsize(*a) - 3) / 4) + 1;
		// printf("size_push->%d-\n", size_push);
		// printf("last_size->%d-\n", last_size);
		last_size = function(a, b, size_push, last_size);
		// size_push += last_size;
	}
	// printf("HERE\n");
	// printf("\n\n!!!\n\n");
	sort_three(a);
	// t_stack *last = lstlast(*a);
	// last->index = -1;
	// while (*b)
	// {
	// 	t_stack *stack = bigest_node(*b);
	// 	finish_rotation(b, stack, 'b');
	// 	pa(b, a, false);
	// }
	// while (*b)
	// {
	// 	pa(b, a, false);
	// }
	
	
	
	// printf("\n\n!!!\n\n");
	
	
	
	
	t_stack *curr = *a;
	while (curr)
	{
		printf("value->%d-index->%d-\n", curr->value, curr->index);
		curr = curr->next;
	}
	printf("\n\n!!!\n\n");
	t_stack *currr = *b;
	while (currr)
	{
		printf("value->%d-index->%d-\n", currr->value, currr->index);
		currr = currr->next;
	}
}

void	stack(t_stack **a, t_stack **b, t_struct var)
{
	stack_init(a, var.values, var.l);
	if (!is_nsorted(*a))
	{
		if (var.l == 2)
			sa(a, false);
		else if (var.l == 3)
			sort_three(a);
		else if (var.l > 3)
			sort_all(a, b, &var);
	}
	lstclear(a);
	lstclear(b);
	free(var.values);
}
