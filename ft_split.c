/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou <mkhellou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 11:16:32 by mkhellou          #+#    #+#             */
/*   Updated: 2022/10/06 10:08:28 by mkhellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	c_count(char const *str, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			i++;
		else
		{
			count++;
			while (str[i] && str[i] != c)
				i++;
		}
	}
	return (count);
}

static char	**free_all(char **big, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		free(big[i]);
		i++;
	}
	free(big);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	int		count;
	char	**big;
	int		i;
	int		j;

	if (!s)
		return (0);
	count = c_count(s, c);
	big = (char **)ft_calloc(count + 1, sizeof(char *));
	if (!big)
		return (0);
	j = 0;
	i = 0;
	while (j < count)
	{
		s = s + i;
		while (*s == c)
			s = ft_strchr(s, c) + 1;
		i = ft_strchr(s, c) - s;
		big[j] = ft_substr(s, 0, i);
		if (!big[j])
			return (free_all(big, j));
		j++;
	}
	return (big);
}
