/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstsize.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksohail- <ksohail-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 11:10:00 by ksohail-          #+#    #+#             */
/*   Updated: 2024/01/25 15:12:54 by ksohail-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	lstsize(t_stack *lst)
{
	t_stack	*curr;
	int		i;

	if (!lst)
		return (0);
	i = 0;
	curr = lst;
	while (curr != NULL)
	{
		curr = curr->next;
		i++;
	}
	return (i);
}
