/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: error01 <error01@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 12:54:54 by ksohail-          #+#    #+#             */
/*   Updated: 2024/01/12 13:00:01 by error01          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	fill(char const *s1, char const *s2, char *ptr)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i++] = ' ';
	while (s2[j])
		ptr[i++] = s2[j++];
	ptr[i] = '\0';
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;

	if (s1 == NULL && s2 != NULL)
	{
		ptr = ft_strdup((char *)s2);
		return (ptr);
	}
	if (s2 == NULL && s1 != NULL)
	{
		ptr = ft_strdup((char *)s1);
		free((char *)s1);
		return (ptr);
	}
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	ptr = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 2) * sizeof(char));
	if (ptr == 0)
		return (0);
	fill(s1, s2, ptr);
	free((char *)s1);
	return (ptr);
}
