/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksohail- <ksohail-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 09:48:58 by error01           #+#    #+#             */
/*   Updated: 2024/01/25 16:02:09 by ksohail-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	there_is_num(char **av)
{
	int	x;
	int	y;

	x = 0;
	while (av[x])
	{
		y = 0;
		while (av[y])
		{
			if (av[x][y] >= '0' && av[x][y] <= '9')
				return (1);
			y++;
		}
		x++;
	}
	return (0);
}

void	error(char **av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (av[i][0] == '\0' || !there_is_num(av))
		{
			ft_printf("Error\n");
			exit(EXIT_SUCCESS);
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
		return (0);
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
