/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akirmizi <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 16:06:12 by akirmizi          #+#    #+#             */
/*   Updated: 2022/01/31 18:01:45 by akirmizi         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*a;

	if (!*lst)
		return ;
	while (*lst)
	{
		a = (*lst)-> next;
		ft_lstdelone(*lst, del);
		*lst = a;
	}
	*lst = NULL;
}
