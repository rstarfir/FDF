/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poatmeal <poatmeal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 17:09:55 by poatmeal          #+#    #+#             */
/*   Updated: 2019/09/21 18:53:55 by poatmeal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_cleanlst(t_list *clean)
{
	t_list	*cln;

	while (clean->next)
	{
		cln = clean->next;
		free(clean);
		clean = cln;
	}
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*another;
	t_list	*new;

	if (lst && f)
	{
		another = f(lst);
		new = another;
		while (lst->next != NULL)
		{
			lst = lst->next;
			if (!(another->next = f(lst)))
			{
				ft_cleanlst(new);
				return (NULL);
			}
			another = another->next;
		}
		return (new);
	}
	return (NULL);
}
