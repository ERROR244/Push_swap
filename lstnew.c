/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstnew.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksohail- <ksohail-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 11:09:54 by ksohail-          #+#    #+#             */
/*   Updated: 2024/01/07 09:50:29 by ksohail-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*lstnew(int value, t_stack *last_node)
{
	t_stack	*n_node;

	n_node = (t_stack *)malloc(sizeof(struct s_stack));
	if (n_node == NULL)
		return (NULL);
	n_node->value = value;
	n_node->next = NULL;
	if (!last_node)
		n_node->prev = NULL;
	n_node->prev = last_node;
	return (n_node);
}
