/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou <mkhellou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 11:16:32 by mkhellou          #+#    #+#             */
/*   Updated: 2022/10/04 16:51:05 by mkhellou         ###   ########.fr       */
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


// static int	count_strings(char *trimed, char c)
// {
// 	int	i;

// 	while (*trimed == c)
// 		trimed ++;
// 	while ()
// 	{
// 		if (*trimed == c)
// 			trimed ++;
// 		if(*trimed != c)
// 			trimed ++;
// 			i++;
// 	}
// 	i = 0;
// 	return (i + 1);
// }

// static int	c_count(char const *trimed, char c)
// {
// 	int	i;
// 	int	len;

// 	i = 0;
// 	len = ft_strlen(trimed);
// 	while (ft_strchr(trimed, c))
// 	{
// 		trimed = ft_strchr(trimed, c)+1;
// 		if (*trimed == c)
// 			continue ;
// 		i++; 
// 	}	
// 	return (i+1);
// }

char	**ft_split(char const *s, char c)
{
	char	*trimed;
	int		count;
	char	**big;
	int		i;
	int		j;

	if (!s)
		return (0);
	trimed = ft_strtrim(s, &c);
	if (!trimed)
		return (0);
	count = c_count(trimed, c);
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
		if (!big[j])
			return (free_all(big, j));
		j++;
	}
	free(trimed);
	return (big);
}

// char **ft_split(char const *s, char c)
// {
// 	char*	trimed;

// 	trimed = (char *)s;
// 	while (*trimed == c)
// 	{
// 		trimed++;
// 	}
// 	while (*trimed != c)
// 	{
// 		trimed ++;
// 	}
// 	printf("%s", trimed);
// 	return (0);
// }




// static char	*get_word(char const *s, char c, int *index)
// {
// 	int		i;
// 	int		wdlen;
// 	char	*str;

// 	wdlen = 0;
// 	i = 0;
// 	while (s[(*index)] == c)
// 		(*index)++;
// 	i = *index;
// 	while (s[i] && s[i] != c)
// 	{
// 		wdlen++;
// 		i++;
// 	}
// 	str = (char *)malloc((wdlen + 1) * (sizeof(char)));
// 	if (!str)
// 		return (0);
// 	i = 0;
// 	while (s[(*index)] && s[(*index)] != c)
// 		str[i++] = s[(*index)++];
// 	str[i] = 0;
// 	return (str);
// }

// char	**ft_split(char const *s, char c)
// {
// 	int		c_occurence;
// 	int		i;
// 	char	**arr;
// 	int		index;

// 	if (s == NULL)
// 		return (0);
// 	index = 0;
// 	i = 0;
// 	c_occurence = c_count(s, c);
// 	arr = (char **)malloc(sizeof(char *) * (c_occurence + 1));
// 	if (!arr)
// 		return (0);
// 	while (i < c_occurence)
// 	{
// 		arr[i] = get_word(s, c, &index);
// 		if (!arr)
// 			return (free_all(arr, i));
// 		i++;
// 	}
// 	arr[i] = 0;
// 	return (arr);
// }
