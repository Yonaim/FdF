/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 22:21:23 by yona              #+#    #+#             */
/*   Updated: 2022/12/04 18:19:27 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

static t_node	*get_startnode(void)
{
	static t_node	startnode = {{'\0'}, 0, NULL};

	return (&startnode);
}

static int	putout_into_newnode(t_node *node, const char *str, int nbyte)
{
	int				offset;
	int				cpybyte;

	offset = 0;
	while (offset != nbyte)
	{
		if (node->fillbyte == BUFFER_SIZE)
			node = fmt_lstaddnew_back(node);
		if (!node)
			return (FAIL);
		cpybyte = ft_min(nbyte - offset, BUFFER_SIZE - node->fillbyte);
		fmt_memcpy(&node->buf[node->fillbyte], &str[offset], cpybyte);
		offset += cpybyte;
		node->fillbyte += cpybyte;
	}
	return (SUCCESS);
}

int	putout(const char *str, int nbyte)
{
	t_node *const	startnode = get_startnode();
	t_node			*node;

	node = fmt_lstlast(startnode);
	if (node->fillbyte + nbyte > BUFFER_SIZE)
	{
		if (putout_into_newnode(node, str, nbyte) == FAIL)
		{
			fmt_lstallclear(startnode);
			return (FAIL);
		}
	}
	else
	{
		fmt_memcpy(&node->buf[node->fillbyte], str, nbyte);
		node->fillbyte += nbyte;
	}
	return (SUCCESS);
}

int	writeout(int fd)
{
	t_node *const	startnode = get_startnode();
	t_node			*node;
	int				done;
	int				err;

	node = (t_node *)startnode;
	done = 0;
	while (node)
	{
		err = write(fd, node->buf, node->fillbyte);
		if (err < 0)
		{
			fmt_lstallclear(startnode);
			return (FAIL);
		}
		done += err;
		node = node->next;
	}
	fmt_lstallclear(startnode);
	return (done);
}
