/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha_blending_color_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 07:30:56 by yeonhkim          #+#    #+#             */
/*   Updated: 2023/01/22 18:56:51 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

int	alpha_blending_color(int color1, int color2, double alpha)
{
	int	res;
	int	mask;

	res = 0;
	mask = 0xFF0000;
	while (mask)
	{
		res |= (int)((color1 & mask) * alpha + (color2 & mask) * (1 - alpha)) \
				& mask;
		mask >>= 8;
	}
	return (res);
}
