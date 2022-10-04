/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou <mkhellou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 11:16:32 by mkhellou          #+#    #+#             */
/*   Updated: 2022/10/04 11:56:27 by mkhellou         ###   ########.fr       */
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

	while (*trimed == c)
		trimed ++;
	while ()
	{
		if (*trimed == c)
			trimed ++;
		if(*trimed != c)
			trimed ++;
			i++;
	}
	i = 0;
	return (i + 1);
}

static void	free_all(char **big,int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		free(big[i]);
		i++;
	}
	free(big);
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

	i = 0;
	while (s[i] == c)
		i++;
	if (s[i] =='\0')
		return(big = ft_calloc(2,sizeof(char **)));
	if (!s)
		return (0);
	if( s[0] == '\0')
	{
		return(big = ft_calloc(1,sizeof(char **)));
	}
	trimed = ft_strtrim(s, &c);
	if(!trimed)
		return(0);
	count = count_strings(trimed, c);
	big = (char **)ft_calloc(count + 1, sizeof(char *));
	if(!big)
		return(0);
	j = 0;
	i = 0;
	while (j < count)
	{
		trimed = trimed + i;
		while (*trimed == c)
			trimed = ft_strchr(trimed, c) + 1;
		i = ft_strchr(trimed, c) - trimed;
		big[j] = ft_substr(trimed, 0, i);
		if (!big[j])
			free_all(big,j);
		j++;
	}
	return (big);
}