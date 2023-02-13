/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compose_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 07:24:44 by yeonhkim          #+#    #+#             */
/*   Updated: 2023/01/22 14:49:11 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	compose_move_matrix(t_matrix *m, double x, double y, double z)
{
	const t_matrix	m_move = (t_matrix){
		(t_vector){1, 0, 0, 0},
		(t_vector){0, 1, 0, 0},
		(t_vector){0, 0, 1, 0},
		(t_vector){x, y, z, 1}
	};

	*m = matmul(*m, m_move);
}

void	compose_rotate_matrix(t_matrix *m, double x, double y, double z)
{
	const double	radian = M_PI / 180;
	const t_matrix	m_rotate_x = (t_matrix){
		(t_vector){1, 0, 0, 0},
		(t_vector){0, cos(x * radian), sin(x * radian), 0},
		(t_vector){0, -sin(x * radian), cos(x * radian), 0},
		(t_vector){0, 0, 0, 1}
	};
	const t_matrix	m_rotate_y = (t_matrix){
		(t_vector){cos(y * radian), 0, -sin(y * radian), 0},
		(t_vector){0, 1, 0, 0},
		(t_vector){sin(y * radian), 0, cos(y * radian), 0},
		(t_vector){0, 0, 0, 1}
	};
	const t_matrix	m_rotate_z = (t_matrix){
		(t_vector){cos(z * radian), sin(z * radian), 0, 0},
		(t_vector){-sin(z * radian), cos(z * radian), 0, 0},
		(t_vector){0, 0, 1, 0},
		(t_vector){0, 0, 0, 1}
	};

	*m = matmul(*m, m_rotate_x);
	*m = matmul(*m, m_rotate_y);
	*m = matmul(*m, m_rotate_z);
}

void	compose_scale_matrix(t_matrix *m, double x, double y, double z)
{
	const t_matrix	m_scale = (t_matrix){
		(t_vector){x, 0, 0, 0},
		(t_vector){0, y, 0, 0},
		(t_vector){0, 0, z, 0},
		(t_vector){0, 0, 0, 1}
	};

	*m = matmul(*m, m_scale);
}
