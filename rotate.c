/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksohail- <ksohail-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 12:38:23 by ksohail-          #+#    #+#             */
/*   Updated: 2024/01/25 14:43:46 by ksohail-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **a)
{
	t_stack	*curr;

	if (!a || !*a || lstsize(*a) == 1)
		return ;
	curr = lstlast(*a);
	curr->next = *a;
	*a = (*a)->next;
	(*a)->prev = NULL;
	curr->next->next = NULL;
	curr->next->next = NULL;
}

void	ra(t_stack **a)
{
	rotate(a);
	printf("ra\n");
}

void	rb(t_stack **b)
{
	rotate(b);
	printf("rb\n");
}

void	rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
	printf("rr\n");
}
