/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou <mkhellou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 11:16:32 by mkhellou          #+#    #+#             */
/*   Updated: 2022/10/03 12:32:13 by mkhellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count(char *trimed, char c)
{
	int		i;
	char	*inter;

	inter = trimed;
	i = 0;
	while (ft_strchr(inter, c))
	{
		inter = ft_strchr(inter, c) + 1;
		i++;
	}
	i++;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	*trimed;
	int		i;
	char	*inter;

	trimed = ft_strtrim(s, &c);
	printf("%d", count(trimed, c));
	free (trimed);
	return (0);
}
