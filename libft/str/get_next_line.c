/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstarfir <rstarfir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 17:07:32 by rstarfir          #+#    #+#             */
/*   Updated: 2020/06/25 14:49:27 by rstarfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*find_fd(t_list **curr_ln, int fd)
{
	t_list			*tmp;

	tmp = *curr_ln;
	while (tmp)
	{
		if ((int)tmp->content_size == fd)
			return (tmp);
		tmp = tmp->next;
	}
	if (!(tmp = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	tmp->content_size = fd;
	tmp->next = NULL;
	tmp->content = (void *)ft_strnew(0);
	ft_lstadd(curr_ln, tmp);
	return (*curr_ln);
}

void	cpytillbr(char **dst, char **src, char c)
{
	int				num;
	char			*tmp;
	size_t			len;

	len = ft_strlen(*src);
	if ((tmp = ft_strchr(*src, c)))
		num = tmp - *src;
	else
		num = len;
	*dst = ft_strsub(*src, 0, num);
	tmp = *src;
	if (num < (int)len)
	{
		*src = ft_strdup(*src + num + 1);
		free(tmp);
	}
	else
		ft_strclr(*src);
}

char	*freestrjoin(char *s1, char *s2)
{
	char	*tmpstr;

	tmpstr = ft_strjoin(s1, s2);
	free(s1);
	return (tmpstr);
}

void	couldntfit(char **line, char **cnt, char *tmpstr, size_t rdbl)
{
	if (ft_strchr(tmpstr, '\0'))
		cpytillbr(line, cnt, '\n');
	else
	{
		*line = ft_strsub(tmpstr, 0, rdbl);
		ft_strclr(tmpstr);
	}
}

int		get_next_line(const int fd, char **line)
{
	char			buff[BUFF_SIZE + 1];
	size_t			rdbl;
	static t_list	*curr_ln;
	t_list			*curr;
	char			*tmpstr;

	if (!line || (read(fd, buff, 0) < 0) || fd < 0)
		return (-1);
	curr = find_fd(&curr_ln, fd);
	while ((rdbl = read(fd, buff, BUFF_SIZE)))
	{
		buff[rdbl] = '\0';
		if (!(curr->content = freestrjoin(curr->content, buff)))
			return (-1);
		if (ft_strchr(buff, '\n'))
			break ;
	}
	tmpstr = curr->content;
	if (rdbl == 0 && !(*tmpstr))
		return (0);
	rdbl = 0;
	while (tmpstr[rdbl] != '\n' && tmpstr[rdbl])
		rdbl++;
	couldntfit(line, (char **)&curr->content, tmpstr, rdbl);
	return (1);
}
