/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poatmeal <poatmeal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 15:09:30 by poatmeal          #+#    #+#             */
/*   Updated: 2020/02/11 10:45:09 by poatmeal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list				*ft_check_fd(t_list **start, int fd)
{
	t_list			*lst;

	lst = *start;
	while (lst)
	{
		if ((int)lst->content_size == fd)
			return (lst);
		lst = lst->next;
	}
	if (!(lst = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	lst->content_size = fd;
	lst->next = NULL;
	lst->content = ft_strnew(0);
	ft_lstadd(start, lst);
	return (*start);
}

char				*ft_check_lst(t_list *lst, char **line, size_t rd, size_t c)
{
	char			*copy;

	copy = lst->content;
	if (copy[c] == '\n')
	{
		if (c > 0)
			*line = ft_strsub(copy, 0, c);
		else
			*line = ft_strnew(0);
		if (copy[c + 1] != '\0')
		{
			lst->content = ft_strdup(&copy[c + 1]);
			free(copy);
		}
		else
			ft_strclr(lst->content);
	}
	else if (copy[c] == '\0' && rd == 0)
	{
		*line = ft_strdup(copy);
		ft_strclr(lst->content);
	}
	return (*line);
}

char				*ft_distribution_lst(t_list *lst, char **line, size_t flag)
{
	size_t			i;
	size_t			c;
	char			*copy;

	c = 0;
	i = ft_strlen(lst->content);
	if (i > 0)
	{
		copy = lst->content;
		while (copy[c] != '\n' && copy[c] != '\0')
			c++;
		*line = ft_check_lst(lst, line, flag, c);
		return (*line);
	}
	return (NULL);
}

char				*ft_rec_buf(t_list *lst, char *buf, char **line, size_t rd)
{
	char			*copy;
	size_t			i;

	i = ft_strlen(lst->content);
	if ((copy = ft_strchr(lst->content, '\n')))
	{
		*line = ft_distribution_lst(lst, line, rd);
		copy = lst->content;
		if (!(lst->content = ft_strjoin(lst->content, buf)))
			return (NULL);
		free(copy);
		return (*line);
	}
	copy = lst->content;
	if (!(lst->content = ft_strjoin(lst->content, buf)))
		return (NULL);
	free(copy);
	copy = ft_strchr(lst->content, '\n');
	if (copy)
	{
		*line = ft_distribution_lst(lst, line, rd);
		return (*line);
	}
	return (NULL);
}

int					get_next_line(const int fd, char **line)
{
	static t_list	*start;
	t_list			*lst;
	size_t			redd;
	char			buf[BUFF_SIZE + 1];

	if (fd < 0 || BUFF_SIZE < 1 || !line || read(fd, 0, 0) < 0)
		return (-1);
	lst = ft_check_fd(&start, fd);
	while ((redd = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[redd] = '\0';
		if ((ft_rec_buf(lst, buf, line, redd)))
			return (1);
	}
	if ((ft_distribution_lst(lst, line, redd)))
		return (1);
	return (0);
}
