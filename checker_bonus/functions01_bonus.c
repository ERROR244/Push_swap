/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions01_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksohail- <ksohail-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 11:15:16 by ksohail-          #+#    #+#             */
/*   Updated: 2024/01/29 21:03:25 by ksohail-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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

void	error_msg1(void)
{
	write(1, "Error\n", 6);
}

int	duplicates(long value, long *values, int k, int l)
{
	int	i;

	i = 0;
	while (i < l)
	{
		if (value == values[i] && i != k)
		{
			write(1, "Error\n", 6);
			return (0);
		}
		i++;
	}
	return (1);
}

int	errors1(long *values, int l)
{
	int	i;

	i = 0;
	while (i < l)
	{
		if (values[i] > INT_MAX || values[i] < INT_MIN)
		{
			write(1, "Error\n", 6);
			return (0);
		}
		if (duplicates(values[i], values, i, l) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	errors0(char **argv)
{
	int	i;
	int	k;

	i = 0;
	while (argv[i])
	{
		k = 0;
		while (argv[i][k])
		{
			if ((!(argv[i][k] <= '9' && argv[i][k] >= '0') && argv[i][k] != '-'
					&& argv[i][k] != '+') || ((argv[i][k] == '-'
						|| argv[i][k] == '+') && (argv[i][k + 1] == '-'
						|| argv[i][k + 1] == '+')) || ((argv[i][k] == '-'
						|| argv[i][k] == '+') && k != 0) || ((argv[i][k] == '-'
						|| argv[i][k] == '+') && argv[i][k + 1] == '\0'))
			{
				error_msg1();
				return (0);
			}
			k++;
		}
		i++;
	}
	return (1);
}
