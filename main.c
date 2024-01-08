/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksohail- <ksohail-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 09:48:58 by error01           #+#    #+#             */
/*   Updated: 2024/01/08 09:17:51 by ksohail-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long    *error_handel(char **argv)
{
    long *values;
    int i;
    int l;
	int flag;

	i = 0;
	l = 0;
	errors0(argv);
    while (argv[l])
        l++;
    values = malloc(sizeof(long *) * (l));
	if (!values)
		return (NULL);
	flag = l;
	l--;
    while (i < flag)
        values[i++] = ft_atol(argv[l--]);
	errors1(values, flag);
	return (values);
}

void	sort_all(t_stack **a, t_stack  **b)
{
	
}

int	lstlast_value(t_stack *lst)
{
	if (lst == NULL)
		return (0);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst->value);
}

void sort_five(t_stack **a, t_stack **b)
{
	t_stack *curr;
	int		last_node_value;
	int		value;
	int		value1;
	int		i = 0;
	
	pb(a, b, false);
	pb(a, b, false);
	value = (*b)->value;
	value1 = (*b)->next->value;
	sort_three(a);
	while (i < 2)
	{
		last_node_value = lstlast_value(*a);
		if (last_node_value < value)
		{
			pa(a, b, false);
			ra(a, false);
		}
		value = value1;
		i++;
	}
}

int main(int argc, char **argv)
{
	t_stack *node;
	t_stack *b;
	t_stack *a;
	long	*values;
	int		l;

    if (argc == 1 || (argc == 2 && !argv[0]))
		return (1);
	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	values = error_handel(argv + 1);
	l = size(argv + 1);
	stack_init(&a, node, values, l);
	t_stack *curr = a;
	while (curr)
	{
		printf("%d \n", curr->value);
		curr = curr->next;
	}
	printf("\n!!!\n\n");
	if (!is_nsorted(a))
	{
		if (l == 2)
			sa(&a, false);
		else if (l == 3)
			sort_three(&a);
		else if (l <= 5 && l > 3)
			sort_five(&a, &b);
		else if (l > 5)
			sort_all(&a, &b);
	}
	t_stack *cur = a;
	printf("\n!!!\n\n");
	while (cur)
	{
		printf("%d \n", cur->value);
		cur = cur->next;
	}
	printf("\n!!!\n");
	// t_stack *currr = b;
	// while (currr)
	// {
	// 	printf("%d \n", currr->value);
	// 	currr = currr->next;
	// }
}
