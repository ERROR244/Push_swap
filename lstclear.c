/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstclear.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksohail- <ksohail-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 11:09:37 by ksohail-          #+#    #+#             */
/*   Updated: 2024/01/06 11:09:39 by ksohail-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lstclear(t_stack **lst, void (*del)(void*))
{
	t_stack	*curr1;
	t_stack	*curr2;

	if (lst == NULL || *lst == NULL || del == NULL)
		return ;
	curr1 = *lst;
	while (curr1->next != NULL)
	{
		curr2 = curr1->next;
		lstdelone(curr1, del);
		curr1 = curr2;
	}
	lstdelone(curr1, del);
	*lst = NULL;
}
