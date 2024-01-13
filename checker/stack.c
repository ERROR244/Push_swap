/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksohail- <ksohail-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 11:25:45 by ksohail-          #+#    #+#             */
/*   Updated: 2024/01/13 13:06:49 by ksohail-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	ft_strcmp(char *str_1, char *str_2)
{
	while (*str_1 == *str_2 && *str_1)
	{
		++str_1;
		++str_2;
	}
	return (*str_1 - *str_2);
}

int	error_exit(void)
{
	ft_printf("Error\n");
	return (1);
}

int	command(char *cmd, t_stack **a, t_stack **b, int flag)
{
	if (!ft_strcmp(cmd, "sa\n"))
		sa(a, true);
	else if (!ft_strcmp(cmd, "sb\n"))
		sb(b, true);
	else if (!ft_strcmp(cmd, "ss\n"))
		ss(a, b, true);
	else if (!ft_strcmp(cmd, "pa\n"))
		pa(b, a, true);
	else if (!ft_strcmp(cmd, "pb\n"))
		pb(a, b, true);
	else if (!ft_strcmp(cmd, "ra\n"))
		ra(a, true);
	else if (!ft_strcmp(cmd, "rb\n"))
		rb(b, true);
	else if (!ft_strcmp(cmd, "rr\n"))
		rr(a, b, true);
	else if (!ft_strcmp(cmd, "rra\n"))
		rra(a, true);
	else if (!ft_strcmp(cmd, "rrb\n"))
		rrb(b, true);
	else if (!ft_strcmp(cmd, "rrr\n"))
		rrr(a, b, true);
	else
		flag = error_exit();
	return (flag);
}

void	stack(t_stack **a, t_stack **b, t_struct var)
{
	char	*cmd;
	int		size;
	int		flag;

	flag = 0;
	stack_init(a, var.values, var.l);
	cmd = get_next_line(INPUT);
	size = lstsize(*a);
	while (cmd)
	{
		flag = command(cmd, a, b, flag);
		if (flag == 1)
			break ;
		cmd = get_next_line(INPUT);
	}
	if (flag == 0)
	{
		if (is_nsorted(*a) && lstsize(*a) == size)
			ft_printf("OK\n");
		else
			ft_printf("KO\n");
	}
	lstclear(a);
	lstclear(b);
	free(var.values);
}
