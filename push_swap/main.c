/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: error01 <error01@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 09:48:58 by error01           #+#    #+#             */
/*   Updated: 2024/01/12 13:12:46 by error01          ###   ########.fr       */
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
	// for (int i = 0; i < l; i++)
	// 	printf("argv[%d]->%s\n", i, argv[i]);
	errors0(argv);
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

void    swap_to(t_stack **a, bool print)
{
	if (*a && (*a)->next)
    {
        (*a)->prev = (*a)->next;
    	*a = (*a)->next;
		(*a)->prev->next = NULL;
    	(*a)->next = (*a)->prev;
    	(*a)->prev = NULL;
    }
	if (!print)
		printf("sa\n");
}

int	main(int argc, char **argv)
{
	t_stack	*node;
	t_stack	*b;
	t_stack	*a;
	long	*values;
	int		l;
	bool	splited = false;
	t_stack	*cur;
	char *ptr = NULL;

	b = NULL;
	a = NULL;
	if (argc == 1 || (argc == 2 && !argv[0]))
		return (1);
	l = 1;
	while (l < argc)
	{
		ptr = ft_strjoin(ptr, argv[l]);
		l++;
	}
	argv = ft_split(ptr, ' ');
	l = 0;
	l = size(argv + 1);
	// for (int i = 1; i <= l; i++)
	// {
	// 	printf("argv[%d]->%s-\n", i, argv[i]);
	// 	free(argv[i]);
	// }
	values = error_handel(argv + 1);
	// for (int i = 0; i < l; i++)
	// 	printf("value[%d]->%ld-\n", i, values[i]);
	stack_init(&a, node, values, l);
	if (!is_nsorted(a))
	{
		if (l == 2)
			swap_to(&a, false);
		else if (l == 3)
			sort_three(&a);
		else if (l > 3)
			sort_all(&a, &b);
	}
	cur = a;
	while (cur)
	{
			printf("value->%d-\n", cur->value);
		cur = cur->next;
	}
	if (splited == true)
	{
		for (int i = 0; i <= l; i++)
			free(argv[i]);
		free(argv);
	}
	free(ptr);
	lstclear(&a);
	lstclear(&b);
	free(values);
}
