/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: error01 <error01@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 13:32:12 by error01           #+#    #+#             */
/*   Updated: 2024/01/04 13:32:43 by error01          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(const char *nptr)
{
	long	i;
	long	sign;
	long	res;

	i = 0;
	sign = 1;
	res = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] >= 48 && nptr[i] <= 57)
	{
		res *= 10;
		res += nptr[i] - '0';
		i++;
	}
	return (sign * res);
}

void duplicates(long value, long *values, int k)
{
	int i;

	i = 0;
	while (values[i])
	{
		if (value == values[i] && i != k)
		{
			printf("Error\n		duplicates\n");
			printf("%ld- \n", values[i]);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

void	errors1(long *values)
{
	int i = 0;
	while (values[i])
	{
		if (values[i] > INT_MAX || values[i] < INT_MIN)
		{
			printf("Error\n		some arguments are bigger/less than an integer\n");
			printf("%ld- \n", values[i]);
			exit(EXIT_FAILURE);
		}
		duplicates(values[i], values, i);
		i++;
	}
	
}

void error_msg1(void)
{
	printf("Error\n 	some arguments aren’t integers\n");
	exit(EXIT_FAILURE);
}

void	errors0(char **argv)
{
	int i;
	int k;

	i = 0;
	while (argv[i])
	{
		k = 0;
		while (argv[i][k])
		{
			if (!(argv[i][k] <= '9' && argv[i][k] >= '0') && argv[i][k] != '-' && argv[i][k] != '+')
				error_msg1();
			if ((argv[i][k] == '-' || argv[i][k] == '+') && (argv[i][k + 1] == '-' || argv[i][k + 1] == '+'))
				error_msg1();
			if ((argv[i][k] == '-' || argv[i][k] == '+') && k != 0)
				error_msg1();
			if ((argv[i][k] == '-' || argv[i][k] == '+') && argv[i][k + 1] == '\0')
				error_msg1();
			k++;
		}
		i++;
	}
}
