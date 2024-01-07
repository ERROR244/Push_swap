/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksohail- <ksohail-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 12:31:43 by ksohail-          #+#    #+#             */
/*   Updated: 2024/01/06 10:24:54 by ksohail-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **a)
{
	t_stack	*curr;

	if (*a && (*a)->next)
	{
		curr = (*a)->next;
		(*a)->next = curr->next;
		curr->next = *a;
		*a = curr;
	}
}

void sa(t_stack **a, bool print)
{
	swap(a);
	if (!print)
		printf("sa\n");
}

void sb(t_stack **b, bool print)
{
	swap(b);
	if (!print)
		printf("sb\n");
}

void ss(t_stack **a, t_stack **b, bool print)
{
	swap(a);
	swap(b);
	if (!print)
		printf("ss\n");
}
