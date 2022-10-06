/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou <mkhellou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 18:20:22 by mkhellou          #+#    #+#             */
/*   Updated: 2022/10/06 18:38:04 by mkhellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	size_t	len;
	t_list	*dup;

	len = ft_lstsize(lst);
	while (len > 0)
	{
		ft_lstadd_back(&dup, ft_lstnew(NULL));
		len--;
	}
	while (dup != NULL)
	{
		f(dup ->)
		dup = dup -> next;
	}	
	return (0);
}
