/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: error01 <error01@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 09:48:58 by error01           #+#    #+#             */
/*   Updated: 2024/01/04 13:52:15 by error01          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long    *error_handel(char **argv)
{
    long *values;
    int i = 0;
    int l = 0;
	errors0(argv);
    while (argv[l])
        l++;
    values = malloc(sizeof(int *) * (l));
    while (i < l)
    {
        values[i] = ft_atol(argv[i]);
        i++;
    }
	errors1(values);
	return (values);
}

int get_lstsize(long *values)
{
	int i;

	i = 0;
	while (values[i])
	{
		i++;
	}
	return (i);
}

void	stack_init(t_stack *a, t_stack *node, long *valuse)
{
	int size = get_lstsize(valuse) - 1;
	printf("size = %d-\n", size);
	for (int i = 0; )
}

int main(int argc, char **argv)
{
	t_stack *node;
	t_stack *a;
	long	*values;

    if (argc == 1 || (argc == 2 && !argv[0]))
		return (1);
	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	values = error_handel(argv + 1);
	stack_init(a, node, values);
}