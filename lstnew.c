/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstnew.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksohail- <ksohail-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 11:09:54 by ksohail-          #+#    #+#             */
/*   Updated: 2024/01/13 09:26:16 by ksohail-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*lstnew(int value, t_stack *stack)
{
	t_stack	*n_node;
	t_stack	*last_node;

	n_node = (t_stack *)malloc(sizeof(struct s_stack));
	if (n_node == NULL)
		return (NULL);
	n_node->value = value;
	n_node->next = NULL;
	if (stack == NULL)
	{
		n_node->prev = NULL;
	}
	else
	{
		last_node = lstlast(stack);
		n_node->prev = last_node;
	}
	return (n_node);
}
