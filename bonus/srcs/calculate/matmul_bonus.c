/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matmul_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 14:40:09 by yeonhkim          #+#    #+#             */
/*   Updated: 2023/01/22 18:56:51 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static double	dot(t_vector v1, t_vector v2)
{
	return ((v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z) + (v1.w * v2.w));
}

t_matrix	matmul(t_matrix m1, t_matrix m2)
{
	t_matrix	res;

	res.v1 = (t_vector){
		dot((t_vector){m2.v1.x, m2.v2.x, m2.v3.x, m2.v4.x}, m1.v1),
		dot((t_vector){m2.v1.y, m2.v2.y, m2.v3.y, m2.v4.y}, m1.v1),
		dot((t_vector){m2.v1.z, m2.v2.z, m2.v3.z, m2.v4.z}, m1.v1),
		dot((t_vector){m2.v1.w, m2.v2.w, m2.v3.w, m2.v4.w}, m1.v1)};
	res.v2 = (t_vector){
		dot((t_vector){m2.v1.x, m2.v2.x, m2.v3.x, m2.v4.x}, m1.v2),
		dot((t_vector){m2.v1.y, m2.v2.y, m2.v3.y, m2.v4.y}, m1.v2),
		dot((t_vector){m2.v1.z, m2.v2.z, m2.v3.z, m2.v4.z}, m1.v2),
		dot((t_vector){m2.v1.w, m2.v2.w, m2.v3.w, m2.v4.w}, m1.v2)};
	res.v3 = (t_vector){
		dot((t_vector){m2.v1.x, m2.v2.x, m2.v3.x, m2.v4.x}, m1.v3),
		dot((t_vector){m2.v1.y, m2.v2.y, m2.v3.y, m2.v4.y}, m1.v3),
		dot((t_vector){m2.v1.z, m2.v2.z, m2.v3.z, m2.v4.z}, m1.v3),
		dot((t_vector){m2.v1.w, m2.v2.w, m2.v3.w, m2.v4.w}, m1.v3)};
	res.v4 = (t_vector){
		dot((t_vector){m2.v1.x, m2.v2.x, m2.v3.x, m2.v4.x}, m1.v4),
		dot((t_vector){m2.v1.y, m2.v2.y, m2.v3.y, m2.v4.y}, m1.v4),
		dot((t_vector){m2.v1.z, m2.v2.z, m2.v3.z, m2.v4.z}, m1.v4),
		dot((t_vector){m2.v1.w, m2.v2.w, m2.v3.w, m2.v4.w}, m1.v4)};
	return (res);
}
