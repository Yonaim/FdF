/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 21:47:47 by yeonhkim          #+#    #+#             */
/*   Updated: 2022/12/04 14:40:13 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_word(char const *s, char c)
{
	int	count;
	int	flag;

	count = 0;
	flag = 1;
	while (*s)
	{
		if (flag && *s != c)
		{
			count++;
			flag = 0;
		}
		else if (*s == c)
			flag = 1;
		s++;
	}
	return (count);
}

static char	*dup_until_c(char const *s, char c)
{
	char	*dst;
	int		len;
	int		i;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	dst = malloc(sizeof(char) * (len + 1));
	if (!dst)
		return (NULL);
	i = 0;
	while (*s && *s != c)
		dst[i++] = *s++;
	dst[i] = '\0';
	return (dst);
}

void	*free_all(char **dst)
{
	while (*dst)
		free(*dst++);
	free(dst);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**dst;
	int		idx;
	int		flag;

	dst = malloc(sizeof(char *) * (count_word(s, c) + 1));
	if (!dst)
		return (NULL);
	idx = 0;
	flag = 1;
	while (*s)
	{
		if (flag && *s != c)
		{
			dst[idx] = dup_until_c(s, c);
			if (!dst[idx++])
				return (free_all(dst));
			flag = 0;
		}
		else if (*s == c)
			flag = 1;
		s++;
	}
	dst[idx] = NULL;
	return (dst);
}
