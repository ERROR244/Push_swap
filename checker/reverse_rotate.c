/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksohail- <ksohail-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 12:51:19 by ksohail-          #+#    #+#             */
/*   Updated: 2024/01/25 15:19:42 by ksohail-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	reverse_rotate(t_stack **a)
{
	t_stack	*curr;

	if (*a && (*a)->next)
	{
		curr = *a;
		while (curr->next->next)
			curr = curr->next;
		curr->next->next = *a;
		*a = curr->next;
		curr->next = NULL;
	}
}

void	rra(t_stack **a)
{
	reverse_rotate(a);
}

void	rrb(t_stack **b)
{
	reverse_rotate(b);
}

void	rrr(t_stack **a, t_stack **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
}
