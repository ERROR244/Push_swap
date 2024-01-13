/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: error01 <error01@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 09:48:58 by error01           #+#    #+#             */
/*   Updated: 2024/01/12 21:10:01 by error01          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack		*b;
	t_stack		*a;
	t_struct	var;

	b = NULL;
	a = NULL;
	var.ptr = NULL;
	if (argc == 1 || (argc == 2 && !argv[0]))
		return (1);
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
