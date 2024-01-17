/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions04.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksohail- <ksohail-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 21:10:49 by error01           #+#    #+#             */
/*   Updated: 2024/01/17 15:53:11 by ksohail-         ###   ########.fr       */
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

void	sort_all(t_stack **a, t_stack **b, int size)
{
	t_stack	*smallest;
	int		len_a;

	len_a = lstsize(*a);
	while (len_a-- > 3)
		pb(a, b, false);
	sort_three(a);
	while (*b)
	{
		set_the_stacks(*a, *b);
		move_nodes(a, b, size);
	}
	set_the_position(*a);
	smallest = smallest_node(*a);
	if (smallest->above_the_midline)
		while (*a != smallest)
			ra(a, false);
	else
		while (*a != smallest)
			rra(a, false);
}

void	stack(t_stack **a, t_stack **b, t_struct var)
{
	stack_init(a, var.values, var.l);
	// set_the_position(*a);
	// t_stack *curr = *a;
	// while (curr)
	// {
	// 	printf("value->%d-above_the_midline->%d-how_far_from_the_midline->%d-the_1_4_line->%d-the_3_4_line->%d-\n", 
	// 			curr->value, curr->above_the_midline, curr->how_far_from_the_midline, curr->the_1_4_line , curr->the_3_4_line);
	// 	curr = curr->next;
	// }

	// printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
	
	// int len_a = lstsize(*a);
	// while (len_a-- > 3)
	// 	pb(a, b, false);
	// set_the_position(*b);
	// t_stack *currr = *b;
	// while (currr)
	// {
	// 	printf("value->%d-above_the_midline->%d-how_far_from_the_midline->%d-the_1_4_line->%d-the_3_4_line->%d-\n", 
	// 			currr->value, currr->above_the_midline, currr->how_far_from_the_midline,
	// 			currr->the_1_4_line , currr->the_3_4_line);
	// 	currr = currr->next;
	// }
	if (!is_nsorted(*a))
	{
		if (var.l == 2)
			sa(a, false);
		else if (var.l == 3)
			sort_three(a);
		else if (var.l > 3)
			sort_all(a, b, var.l);
	}
	lstclear(a);
	lstclear(b);
	free(var.values);
}