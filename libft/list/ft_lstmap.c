/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstarfir <rstarfir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 17:15:46 by rstarfir          #+#    #+#             */
/*   Updated: 2019/09/23 17:39:17 by rstarfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *ptr;

	if (!lst && !f)
		return (0);
	while (lst)
	{
		ptr = (*f)(lst);
		ptr->next = ft_lstmap(lst->next, f);
		return (ptr);
	}
	return (NULL);
}
