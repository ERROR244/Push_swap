/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksohail- <ksohail-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 12:38:23 by ksohail-          #+#    #+#             */
/*   Updated: 2024/01/25 15:18:52 by ksohail-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
}

void	rb(t_stack **b)
{
	rotate(b);
}

void	rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
}
