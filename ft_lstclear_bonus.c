/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mkhellou < mkhellou@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 15:03:33 by mkhellou          #+#    #+#             */
/*   Updated: 2022/10/07 17:52:56 by  mkhellou        ###   ########.fr       */
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
