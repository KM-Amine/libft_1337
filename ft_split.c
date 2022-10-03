/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou <mkhellou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 11:16:32 by mkhellou          #+#    #+#             */
/*   Updated: 2022/10/03 19:43:53 by mkhellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*strtrim(char const *s1, char const *set)
{
	int	i;
	int	j;

	if (s1 == NULL || set == NULL)
		return (0);
	i = 0;
	j = ft_strlen(s1) - 1;
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	while (s1[j] && ft_strchr(set, s1[j]))
		j--;
	return (ft_substr(s1, i, (j - i + 1)));
}

static int	count_strings(char *trimed, char c)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(trimed);
	while (ft_strchr(trimed,c))
	{
		trimed = ft_strchr(trimed,c)+1;
		if (*trimed == c)
			continue ;
		i++; 
	}	
	return (i+1);
}

char	**ft_split(char const *s, char c)
{
	char	*trimed;
	int		count;
	char	**big;
	int		i;
	int		j;

	if (!s)
		return (0);
	trimed = strtrim(s, &c);
	count = count_strings(trimed, c);
	big = (char **)ft_calloc(count + 1, sizeof(char *));
	j = 0;
	i = 0;
	while (j < count)
	{
		trimed = trimed + i;
		while (*trimed == c)
			trimed = ft_strchr(trimed, c) + 1;
		i = ft_strchr(trimed, c) - trimed;
		big[j] = ft_substr(trimed, 0, i);
		//printf("%s\n", big[j]);
		j++;
	}
	return (big);
}
