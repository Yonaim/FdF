/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmt_itoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 03:17:22 by yona              #+#    #+#             */
/*   Updated: 2022/12/04 18:20:10 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

static int	uint64_to_arr(t_uint64 n, int radix, char arr[17], const char *base)
{
	int			len;
	int			i;
	char		tmp;

	len = 0;
	if (n == 0)
		arr[len++] = '0';
	while (n > 0)
	{
		arr[len++] = base[n % radix];
		n /= radix;
	}
	i = 0;
	while (i < len / 2)
	{
		tmp = arr[i];
		arr[i] = arr[(len - 1) - i];
		arr[(len - 1) - i] = tmp;
		i++;
	}
	arr[len] = '\0';
	return (len);
}

static int	uint32_to_arr(t_uint32 n, int radix, char arr[17], const char *base)
{
	int			len;
	int			i;
	char		tmp;

	len = 0;
	if (n == 0)
		arr[len++] = '0';
	while (n > 0)
	{
		arr[len++] = base[n % radix];
		n /= radix;
	}
	i = 0;
	while (i < len / 2)
	{
		tmp = arr[i];
		arr[i] = arr[(len - 1) - i];
		arr[(len - 1) - i] = tmp;
		i++;
	}
	arr[len] = '\0';
	return (len);
}

char	*fmt_itoa(t_int64 n, int prsc, char *sign)
{
	char		buf[17];

	if (n < 0)
	{
		n = -n;
		*sign = '-';
	}
	else
		*sign = '+';
	if (n == 0 && prsc == 0)
		return (fmt_strdup(""));
	uint32_to_arr(n, 10, buf, "0123456789abcdef");
	return (fmt_strdup(buf));
}

char	*fmt_uitoa(t_uint64 n, int prsc, int type)
{
	char		buf[17];
	int			radix;

	if (n == 0 && prsc == 0)
		return (fmt_strdup("\0"));
	{
		if (type == TYPE_UINT)
			radix = 10;
		else if (type == TYPE_HEX_LOWER || \
				type == TYPE_HEX_UPPER || \
				type == TYPE_PTR)
			radix = 16;
	}
	if (type == TYPE_PTR)
		uint64_to_arr(n, radix, buf, "0123456789abcdef");
	else
		uint32_to_arr(n, radix, buf, "0123456789abcdef");
	return (fmt_strdup(buf));
}
