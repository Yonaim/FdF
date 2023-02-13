/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 17:42:17 by yeonhkim          #+#    #+#             */
/*   Updated: 2022/07/08 19:13:45 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*dst_p;
	const unsigned char	*src_p;

	if (!dst && !src)
		return (NULL);
	dst_p = (unsigned char *)dst;
	src_p = (const unsigned char *)src;
	if (src_p >= dst_p)
	{
		while (len--)
			*dst_p++ = *src_p++;
	}
	else
	{
		while (len)
		{
			*(dst_p + len - 1) = *(src_p + len - 1);
			len--;
		}
	}
	return (dst);
}
