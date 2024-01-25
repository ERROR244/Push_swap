/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksohail- <ksohail-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 20:57:54 by ksohail-          #+#    #+#             */
/*   Updated: 2024/01/25 15:17:29 by ksohail-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	count_words(char const *s, char c)
{
	int	count;
	int	in_word;

	count = 1;
	in_word = 0;
	while (s && *s)
	{
		if (*s == c)
			in_word = 0;
		else
		{
			if (in_word == 0 && *s != c)
			{
				count++;
				in_word = 1;
			}
		}
		s++;
	}
	return (count);
}

static char	*ndup(const char *s, size_t n)
{
	char	*dup;
	size_t	i;

	if (!s)
		return (NULL);
	dup = (char *)malloc((n + 1) * sizeof(char));
	if (dup != NULL)
	{
		i = 0;
		while (i < n)
		{
			dup[i] = s[i];
			i++;
		}
		dup[n] = '\0';
	}
	return (dup);
}

static void	ft_free(char **ptr, int i)
{
	int	j;

	j = 0;
	while (j < i)
		free(ptr[j++]);
	free(ptr);
}

static char	**split(char const *s, char c, int i, char **ptr)
{
	const char	*start;

	ptr[i++] = NULL;
	while (*s)
	{
		if (*s != c)
		{
			start = s;
			while (*s && *s != c)
				s++;
			ptr[i] = ndup(start, s - start);
			if (ptr[i] == NULL)
			{
				ft_free(ptr, i);
				return (NULL);
			}
			i++;
		}
		else
			s++;
	}
	ptr[i] = NULL;
	return (ptr);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	int		word_count;

	if (s == NULL)
		return (NULL);
	word_count = count_words(s, c);
	ptr = malloc((word_count + 1) * sizeof(char *));
	if (ptr == NULL)
	{
		return (NULL);
	}
	return (split(s, c, 0, ptr));
}

// int main()
// {
//     char **str = ft_split("214749 828 8282 11 11 44 55 66", ' ');
//     printf("%s \n", str[0]);
//     free(str[0]);
//     for (int i = 1; str[i]; i++)
//     {
//         printf("%s \n", str[i]);
//         free(str[i]);
//     }
//     free(str);
// }
