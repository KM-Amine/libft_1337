/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou <mkhellou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 16:54:59 by mkhellou          #+#    #+#             */
/*   Updated: 2022/10/07 17:17:25 by mkhellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;

	if (s == NULL)
		return (NULL);
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	if (start >= ft_strlen(s))
		return ((char *)ft_calloc(1, sizeof(char)));
	res = (char *)ft_calloc(sizeof(char), len + 1);
	if (!res)
		return (0);
	ft_strlcpy(res, &s[start], len + 1);
	return (res);
}
