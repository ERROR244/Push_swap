/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksohail- <ksohail-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 12:51:19 by ksohail-          #+#    #+#             */
/*   Updated: 2024/01/06 10:32:17 by ksohail-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void reverse_rotate(t_stack **a)
{
    t_stack *curr;

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

void rra(t_stack **a, bool print)
{
	reverse_rotate(a);
	if (!print)
		printf("rra\n");
}

void rrb(t_stack **b, bool print)
{
	reverse_rotate(b);
	if (!print)
		printf("rrb\n");
}

void rrr(t_stack **a, t_stack **b, bool print)
{
	reverse_rotate(a);
	reverse_rotate(b);
	if (!print)
		printf("rrr\n");
}
