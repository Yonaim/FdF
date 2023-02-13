/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 10:56:12 by yeonhkim          #+#    #+#             */
/*   Updated: 2022/12/05 03:28:54 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	srcsize;
	size_t	orisize;
	size_t	i;

	orisize = 0;
	srcsize = 0;
	while (dst[orisize])
		orisize++;
	while (src[srcsize])
		srcsize++;
	if (dstsize > orisize)
	{
		i = 0;
		while (src[i] && i < (dstsize - orisize - 1))
		{
			dst[orisize + i] = src[i];
			i++;
		}
		dst[orisize + i] = '\0';
		return (orisize + srcsize);
	}
	return (dstsize + srcsize);
}
