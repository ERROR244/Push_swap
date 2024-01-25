/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_i_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksohail- <ksohail-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:09:03 by ksohail-          #+#    #+#             */
/*   Updated: 2023/11/23 12:08:14 by ksohail-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_i_d(long long n)
{
	char		*str;
	int			len;

	len = 0;
	str = ft_itoa(n);
	if (str == NULL)
		return (-1);
	len += print_str(str);
	free(str);
	return (len);
}
