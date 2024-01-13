/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksohail- <ksohail-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 10:32:04 by ksohail-          #+#    #+#             */
/*   Updated: 2024/01/13 11:01:59 by ksohail-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	error(char **av)
{
	int i = 0;
	
	while (av[i])
	{
		if (av[i][0] == '\0')
		{
			printf("Error\n");
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

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

int	duplicates(long value, long *values, int k, int l)
{
	int	i;

	i = 0;
	while (i < l)
	{
		if (value == values[i] && i != k)
		{
			printf("Error\n		duplicates\n");
			printf("%ld- \n", values[i]);
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
			printf("Error\n		some arguments are ");
			printf("bigger/less than an integer\n");
			printf("%ld- \n", values[i]);
			free(values);
			return (0);
		}
		if (duplicates(values[i], values, i, l) == 0)
			return (0);
		i++;
	}
	return (1);
}

void	error_msg1(void)
{
	printf("Error\n 	some arguments aren’t integers\n");
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

long	*error_handel(char **argv)
{
	long	*values;
	int		i;
	int		l;

	i = 0;
	l = 0;
	while (argv[l])
		l++;
	if (errors0(argv) == 0)
		return (NULL);
	values = malloc(sizeof(long *) * (l));
	if (!values)
		return (NULL);
	while (i < l)
	{
		values[i] = ft_atol(argv[i]);
		i++;
	}
	if (errors1(values, l) == 0)
	{
		free(values);
		return (NULL);
	}
	return (values);
}

int	size(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int main(int ac, char **av)
{
    t_stack		*b;
	t_stack		*a;
	t_struct	var;

    if (ac == 1 || (ac == 2 && !av[0]))
        return (1);
    error(av);
    b = NULL;
	a = NULL;
	var.ptr = NULL;
	var.l = 1;
	while (var.l < ac)
		var.ptr = ft_strjoin(var.ptr, av[var.l++]);
	av = ft_split(var.ptr, ' ');
	var.l = size(av + 1);
	var.values = error_handel(av + 1);
    for (int i = 0; i < var.l; i++)
        printf("var.values[%d]->%ld-\n", i, var.values[i]);
}