/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou <mkhellou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 13:15:40 by mkhellou          #+#    #+#             */
/*   Updated: 2022/10/01 14:10:01 by mkhellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*duplicate;

	len = ft_strlen(s1)+1;
	duplicate = (char *)malloc(len * sizeof(char));
	if (!duplicate)
		return (0);
	ft_strlcpy(duplicate, s1, len +1);
	return (duplicate);
}