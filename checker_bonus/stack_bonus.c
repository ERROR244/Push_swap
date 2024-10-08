/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksohail- <ksohail-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 11:25:45 by ksohail-          #+#    #+#             */
/*   Updated: 2024/01/28 10:47:30 by ksohail-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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
	write(1, "Error\n", 6);
	return (1);
}

int	commands_check(char *cmd, t_stack **a, t_stack **b, int flag)
{
	if (!ft_strcmp(cmd, "sa\n"))
		sa(a);
	else if (!ft_strcmp(cmd, "sb\n"))
		sb(b);
	else if (!ft_strcmp(cmd, "ss\n"))
		ss(a, b);
	else if (!ft_strcmp(cmd, "pa\n"))
		pa(b, a);
	else if (!ft_strcmp(cmd, "pb\n"))
		pb(a, b);
	else if (!ft_strcmp(cmd, "ra\n"))
		ra(a);
	else if (!ft_strcmp(cmd, "rb\n"))
		rb(b);
	else if (!ft_strcmp(cmd, "rr\n"))
		rr(a, b);
	else if (!ft_strcmp(cmd, "rra\n"))
		rra(a);
	else if (!ft_strcmp(cmd, "rrb\n"))
		rrb(b);
	else if (!ft_strcmp(cmd, "rrr\n"))
		rrr(a, b);
	else
		flag = error_exit();
	return (flag);
}

int	command(char *cmd, t_stack **a, t_stack **b, int flag)
{
	flag = commands_check(cmd, a, b, flag);
	free(cmd);
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
			write(!1, "OK\n", 3);
		else
			write(!1, "KO\n", 3);
	}
	lstclear(a);
	lstclear(b);
	free(var.values);
}
