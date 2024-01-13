/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksohail- <ksohail-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 12:31:43 by ksohail-          #+#    #+#             */
/*   Updated: 2024/01/13 13:13:33 by ksohail-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **a)
{
	t_stack	*curr;

	if (*a && (*a)->next && lstsize(*a) == 2)
	{
		(*a)->prev = (*a)->next;
		*a = (*a)->next;
		(*a)->prev->next = NULL;
		(*a)->next = (*a)->prev;
		(*a)->prev = NULL;
	}
	else if (*a && (*a)->next && lstsize(*a) != 2)
	{
		curr = (*a)->next;
		(*a)->next = curr->next;
		curr->next->prev = *a;
		curr->next = *a;
		(*a)->prev = curr;
		curr->prev = NULL;
		*a = curr;
	}
}

void	sa(t_stack **a, bool print)
{
	if (lstsize(*a) < 2)
		return ;
	swap(a);
	if (!print)
		printf("sa\n");
}

void	sb(t_stack **b, bool print)
{
	if (lstsize(*b) < 2)
		return ;
	swap(b);
	if (!print)
		printf("sb\n");
}

void	ss(t_stack **a, t_stack **b, bool print)
{
	if (lstsize(*a) < 2 || lstsize(*b) < 2)
		return ;
	swap(a);
	swap(b);
	if (!print)
		printf("ss\n");
}
