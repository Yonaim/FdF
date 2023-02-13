/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 15:09:27 by yeonhkim          #+#    #+#             */
/*   Updated: 2022/12/16 21:09:56 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_internal.h"

int	get_next_lf_idx(t_buff *buf)
{
	int	idx;

	idx = buf->offset;
	while (idx < buf->rbytes)
	{
		if (buf->str[idx] == '\n')
		{
			buf->lf_idx = idx;
			return (idx);
		}
		idx++;
	}
	buf->lf_idx = FAIL;
	return (FAIL);
}

char	*append_buf_to_line(t_line *line, t_buff *buf, int start, int end)
{
	char	*dst;
	int		i;

	if (start > end && line->str == NULL)
		return (NULL);
	if (start > end)
		dst = malloc(sizeof(char) * (line->len + 1));
	else
		dst = malloc(sizeof(char) * (line->len + (end - start + 1) + 1));
	if (!dst)
		return (NULL);
	i = -1;
	while (++i < line->len)
		dst[i] = line->str[i];
	i = -1;
	while (++i <= (end - start))
		dst[line->len + i] = buf->str[start + i];
	line->len += (end - start + 1);
	if (line->str)
		free(line->str);
	line->str = NULL;
	return (dst);
}

char	*final_append_and_complete_line(t_line *line, t_buff *buf, \
int start, int end)
{
	char	*dst;

	dst = append_buf_to_line(line, buf, start, end);
	if (!dst)
		return (NULL);
	dst[line->len] = '\0';
	buf->offset = end + 1;
	return (dst);
}

int	do_read_next(int fd, t_buff *buf, t_line *line)
{
	buf->rbytes = read(fd, buf->str, BUFFER_SIZE);
	if (buf->rbytes <= 0)
	{
		if (buf->rbytes == -1 && line->str)
			free(line->str);
		buf->offset = BUFFER_SIZE + 1;
		return (FAIL);
	}
	else
	{
		buf->offset = 0;
		return (SUCCESS);
	}
}

char	*get_next_line(int fd)
{
	static t_buff	buf;
	t_line			line;

	line.str = NULL;
	line.len = 0;
	while (get_next_lf_idx(&buf) == FAIL)
	{
		line.str = append_buf_to_line(&line, &buf, buf.offset, buf.rbytes - 1);
		if (do_read_next(fd, &buf, &line) == FAIL)
		{
			if (buf.rbytes == -1 || (line.str == NULL && buf.rbytes == 0))
				return (NULL);
			if (buf.rbytes < BUFFER_SIZE && get_next_lf_idx(&buf) == FAIL)
				return (final_append_and_complete_line(&line, &buf, 0, \
				buf.rbytes - 1));
		}
	}
	return (final_append_and_complete_line(&line, &buf, buf.offset, \
	buf.lf_idx));
}
