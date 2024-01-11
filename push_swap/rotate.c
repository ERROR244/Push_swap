/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksohail- <ksohail-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 12:38:23 by ksohail-          #+#    #+#             */
/*   Updated: 2024/01/09 16:29:21 by ksohail-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **a)
{
	t_stack	*curr;

	if (!a || !*a || lstsize(*a) == 1)
		return;
	curr = lstlast(*a);
	curr->next = *a;
	*a = (*a)->next;
	(*a)->prev = NULL;
	curr->next->next = NULL;
	curr->next->next = NULL;
}

void ra(t_stack **a, bool print)
{
	rotate(a);
	if (!print)
		printf("ra\n");
}

void rb(t_stack **b, bool print)
{
	rotate(b);
	if (!print)
		printf("rb\n");
}

void rr(t_stack **a, t_stack **b, bool print)
{
	rotate(a);
	rotate(b);
	if (!print)
		printf("rr\n");
}