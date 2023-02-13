/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 17:40:33 by yeonhkim          #+#    #+#             */
/*   Updated: 2022/07/08 17:42:07 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*ptr_d;
	const char	*ptr_s;

	if (dst == 0 && src == 0)
		return (NULL);
	ptr_d = dst;
	ptr_s = (const char *)src;
	while (n--)
		*ptr_d++ = *ptr_s++;
	return (dst);
}
