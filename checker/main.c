/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksohail- <ksohail-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 10:32:04 by ksohail-          #+#    #+#             */
/*   Updated: 2024/01/13 13:09:06 by ksohail-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

void	error(char **av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (av[i][0] == '\0')
		{
			ft_printf("Error\n");
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	t_stack		*b;
	t_stack		*a;
	t_struct	var;

	if (ac == 1 || (ac == 2 && !av[0]))
		return (1);
	error(av);
	b = NULL;
	a = NULL;
	var.ptr = NULL;
	var.l = 1;
	while (var.l < ac)
		var.ptr = ft_strjoin(var.ptr, av[var.l++]);
	av = ft_split(var.ptr, ' ');
	var.l = size(av + 1);
	var.values = error_handel(av + 1);
	if (var.values != NULL)
		stack(&a, &b, var);
	var.i = 0;
	while (var.i <= var.l)
		free(av[var.i++]);
	free(av);
	free(var.ptr);
}
