/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_num.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 03:07:44 by yona              #+#    #+#             */
/*   Updated: 2022/12/04 18:19:58 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

static void	complete_out_str(t_out out, const int flag, const t_pref *pref, \
							const t_arg *arg)
{
	if (flag & FLAG_LEFT)
	{
		fmt_memset(out->str + pref->len, '0', arg->spc);
		fmt_memcpy(&(out->str[0]), pref->str, pref->len);
		fmt_memcpy(&(out->str[ft_max(arg->spc - arg->strlen + pref->len, 0)]), \
		arg->str, arg->strlen);
	}
	else
	{
		fmt_memset(&(out->str[out->len - arg->spc]), '0', arg->spc);
		if (flag & FLAG_ZERO)
			fmt_memcpy(&(out->str[0]), pref->str, pref->len);
		else
			fmt_memcpy(&(out->str[out->len - arg->spc - pref->len]), \
		pref->str, pref->len);
		fmt_memcpy(&(out->str[out->len - arg->strlen]), arg->str, arg->strlen);
	}
}

int	put_num_dec_signed(va_list args, t_finfo f_info, t_out out)
{
	t_arg		arg;
	t_pref		pref;

	arg.str = fmt_itoa(va_arg(args, t_int32), f_info->prsc, pref.str);
	if (!arg.str)
		return (FAIL);
	pref.len = 1;
	{
		if (*pref.str == '+' && (f_info->flag & FLAG_SPACE))
			pref.str[0] = ' ';
		else if (*pref.str == '+' && !(f_info->flag & FLAG_PLUS))
			pref.len = 0;
	}
	arg.strlen = fmt_strlen(arg.str);
	arg.spc = ft_max(arg.strlen, f_info->prsc);
	out->len = ft_max(arg.spc + pref.len, f_info->width);
	out->str = malloc(sizeof(char) * out->len);
	if (!fmt_memset(out->str, f_info->pad, out->len))
		return (FAIL);
	complete_out_str(out, f_info->flag, &pref, &arg);
	free(arg.str);
	return (putout(out->str, out->len));
}

int	put_num_dec_unsigned(va_list args, t_finfo f_info, t_out out)
{
	t_arg			arg;
	const t_pref	pref = {{'\0'}, 0};

	arg.str = fmt_uitoa(va_arg(args, t_uint32), f_info->prsc, f_info->type);
	if (!arg.str)
		return (FAIL);
	arg.strlen = fmt_strlen(arg.str);
	arg.spc = ft_max(arg.strlen, f_info->prsc);
	out->len = ft_max(arg.spc, f_info->width);
	out->str = malloc(sizeof(char) * out->len);
	if (!fmt_memset(out->str, f_info->pad, out->len))
		return (FAIL);
	complete_out_str(out, f_info->flag, &pref, &arg);
	free(arg.str);
	return (putout(out->str, out->len));
}

int	put_num_hex_unsigned(va_list args, t_finfo f_info, t_out out)
{
	t_arg				arg;
	t_pref				pref;

	arg.str = fmt_uitoa(va_arg(args, t_uint32), f_info->prsc, f_info->type);
	if (!arg.str)
		return (FAIL);
	arg.strlen = fmt_strlen(arg.str);
	fmt_memset(&pref, 0, sizeof(t_pref));
	if ((f_info->flag & FLAG_HASH) && (*arg.str != '0' && arg.strlen != 0))
	{
		fmt_memcpy(pref.str, "0x", 2);
		pref.len = 2;
	}
	arg.spc = ft_max(arg.strlen, f_info->prsc);
	out->len = ft_max(arg.spc + pref.len, f_info->width);
	out->str = malloc(sizeof(char) * out->len);
	if (!fmt_memset(out->str, f_info->pad, out->len))
		return (FAIL);
	complete_out_str(out, f_info->flag, &pref, &arg);
	if (f_info->type == TYPE_HEX_UPPER)
		fmt_str_toupper(out->str, out->len);
	free(arg.str);
	return (putout(out->str, out->len));
}

int	put_num_ptr_address(va_list args, t_finfo f_info, t_out out)
{
	t_arg			arg;
	const t_pref	pref = {"0x", 2};

	arg.str = fmt_uitoa(va_arg(args, t_uint64), f_info->prsc, f_info->type);
	if (!arg.str)
		return (FAIL);
	arg.strlen = fmt_strlen(arg.str);
	arg.spc = ft_max(arg.strlen, f_info->prsc);
	out->len = ft_max(arg.spc + pref.len, f_info->width);
	out->str = malloc(sizeof(char) * out->len);
	if (!fmt_memset(out->str, f_info->pad, out->len))
		return (FAIL);
	complete_out_str(out, f_info->flag, &pref, &arg);
	free(arg.str);
	return (putout(out->str, out->len));
}
