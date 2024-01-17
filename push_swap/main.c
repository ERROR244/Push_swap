/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksohail- <ksohail-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 09:48:58 by error01           #+#    #+#             */
/*   Updated: 2024/01/15 22:03:33 by ksohail-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	main(int argc, char **argv)
{
	t_stack		*b;
	t_stack		*a;
	t_struct	var;

	if (argc == 1 || (argc == 2 && !argv[0]))
		return (1);
	error(argv);
	b = NULL;
	a = NULL;
	var.ptr = NULL;
	var.l = 1;
	while (var.l < argc)
		var.ptr = ft_strjoin(var.ptr, argv[var.l++]);
	argv = ft_split(var.ptr, ' ');
	var.l = size(argv + 1);
	var.values = error_handel(argv + 1);
	if (var.values != NULL)
		stack(&a, &b, var);
	var.i = 0;
	while (var.i <= var.l)
		free(argv[var.i++]);
	free(argv);
	free(var.ptr);
	return (0);
}
