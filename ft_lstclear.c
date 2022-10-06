/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou <mkhellou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 15:03:33 by mkhellou          #+#    #+#             */
/*   Updated: 2022/10/06 16:38:14 by mkhellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*v;

	if (!lst || !del)
		return ;
	v = *lst;
	while (*lst != NULL )
	{
		v = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = v;
	}
	*lst = NULL;
}
