/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 15:25:18 by yeonhkim          #+#    #+#             */
/*   Updated: 2022/07/23 00:08:37 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		num;
	char	sign;

	sign = 1;
	while (*str == '\t' || *str == '\n' || *str == '\v' || *str == '\f'\
			|| *str == '\r' || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			sign = -1;
	num = 0;
	while ('0' <= *str && *str <= '9')
		num = (num * 10) + (*str++ - '0');
	return (sign * num);
}
