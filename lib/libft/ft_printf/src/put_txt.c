/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_txt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 03:10:43 by yona              #+#    #+#             */
/*   Updated: 2022/12/04 18:19:39 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

int	put_txt_char(va_list args, t_finfo f_info, t_out out)
{
	char	arg;

	if (f_info->type == TYPE_PERSIGN)
		arg = '%';
	else
		arg = (char)va_arg(args, int);
	out->len = ft_max(1, f_info->width);
	out->str = malloc(sizeof(char) * out->len);
	if (!fmt_memset(out->str, f_info->pad, out->len))
		return (FAIL);
	{
		if (f_info->flag & FLAG_LEFT)
			out->str[0] = arg;
		else
			out->str[out->len - 1] = arg;
	}
	return (putout(out->str, out->len));
}

int	put_txt_str(va_list args, t_finfo f_info, t_out out)
{
	t_arg	arg;

	arg.str = va_arg(args, char *);
	if (arg.str == NULL)
		arg.str = "(null)";
	if (f_info->flag & FLAG_PRECISION)
		arg.strlen = ft_min(f_info->prsc, fmt_strlen(arg.str));
	else
		arg.strlen = fmt_strlen(arg.str);
	out->len = ft_max(f_info->width, arg.strlen);
	out->str = malloc(sizeof(char) * out->len);
	if (!fmt_memset(out->str, f_info->pad, out->len))
		return (FAIL);
	{
		if (f_info->flag & FLAG_LEFT)
			fmt_memcpy(&out->str[0], arg.str, arg.strlen);
		else
			fmt_memcpy(&out->str[out->len - arg.strlen], arg.str, arg.strlen);
	}
	return (putout(out->str, out->len));
}
