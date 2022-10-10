/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mkhellou < mkhellou@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 15:03:33 by mkhellou          #+#    #+#             */
/*   Updated: 2022/10/10 07:54:06 by  mkhellou        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*v;
	t_list	*tmp;

	if (!lst || !del)
		return ;
	tmp = *lst;
	v = *lst;
	while (*lst != NULL )
	{
		v = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = v;
	}
	tmp = NULL;
}
