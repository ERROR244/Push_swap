/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksohail- <ksohail-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 09:48:58 by error01           #+#    #+#             */
/*   Updated: 2024/01/07 12:11:35 by ksohail-         ###   ########.fr       */
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

void	sort_stack(t_stack **a, t_stack  **b)
{
	
}

void sort_five(t_stack **a, t_stack **b)
{
	
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
	// if (!is_nsorted(a))
	// {
	// 	if (l == 2)
	// 		sa(&a, false);
	// 	else if (l == 3)
	// 		sort_three(&a);
	// 	else if (l == 5)
	// 		sort_five(&a, &b);
	// 	else if (l > 5)
	// 		sort_stack(&a, &b);
	// }

	pb(&a, &b, false);
	pb(&a, &b, false);
	pb(&a, &b, false);
	printf("%d \n", b->value);
	printf("\n!!!\n\n");
	while (b->next)
	{
		printf("%d \n", b->value);
		b = b->next;
	}
	printf("\n!!!\n\n");
	while (b)
	{
		printf("%d \n", b->value);
		if (b->prev == NULL)
			break;
		b = b->prev;
	}
	printf("\n!!!\n\n");
	curr = a;
	while (curr)
	{
		printf("%d \n", curr->value);
		curr = curr->prev;
	}
	printf("\n!!!\n\n");
	pa(&a, &b, false);
	pa(&a, &b, false);
	pa(&a, &b, false);
	while (a)
	{
		printf("%d \n", a->value);
		a = a->next;
	}
}
