/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksohail- <ksohail-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 09:48:58 by error01           #+#    #+#             */
/*   Updated: 2024/01/09 15:56:18 by ksohail-         ###   ########.fr       */
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
	errors0(argv);
	while (argv[l])
		l++;
	values = malloc(sizeof(long *) * (l));
	if (!values)
		return (NULL);
	while (i < l)
	{
		values[i] = ft_atol(argv[i]);
		i++;
	}
	errors1(values, l);
	return (values);
}

void	sort_all(t_stack **a, t_stack **b)
{
	t_stack	*smallest;
	int len_a;

	len_a = lstsize(*a);
	while (len_a-- > 3)
		pb(a, b, false);
	sort_three(a);
	while (*b)
	{
		set_the_stacks(*a, *b);
		move_nodes(a, b);
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

int	main(int argc, char **argv)
{
	t_stack	*node;
	t_stack	*b;
	t_stack	*a;
	long	*values;
	int		l;
	t_stack	*cur;

	b = NULL;
	a = NULL;
	if (argc == 1 || (argc == 2 && !argv[0]))
		return (1);
	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	values = error_handel(argv + 1);
	l = size(argv + 1);
	stack_init(&a, node, values, l);
	if (!is_nsorted(a))
	{
		if (l == 2)
			sa(&a, false);
		else if (l == 3)
			sort_three(&a);
		else if (l > 3)
			sort_all(&a, &b);
	}
	// cur = a;
	// while (cur)
	// {
	// 		printf("value->%d-\n", cur->value);
	// 	cur = cur->next;
	// }
}
