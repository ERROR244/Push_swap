/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstclear.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksohail- <ksohail-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 11:09:37 by ksohail-          #+#    #+#             */
/*   Updated: 2024/01/25 15:12:41 by ksohail-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	lstclear(t_stack **lst)
{
	t_stack	*curr1;
	t_stack	*curr2;

	if (lst == NULL || *lst == NULL)
		return ;
	curr1 = *lst;
	while (curr1->next != NULL)
	{
		curr2 = curr1->next;
		free(curr1);
		curr1 = curr2;
	}
	free(curr1);
	*lst = NULL;
}
