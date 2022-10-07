/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou <mkhellou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 18:08:23 by mkhellou          #+#    #+#             */
/*   Updated: 2022/10/07 16:35:16 by mkhellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*var;
	unsigned char	byte;
	size_t			i;

	i = 0;
	byte = (unsigned char)c;
	var = (unsigned char *)b;
	while (i < len)
	{
		var[i] = byte;
		i++;
	}
	return (b);
}
