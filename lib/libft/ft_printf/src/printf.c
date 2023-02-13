/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 20:14:28 by yona              #+#    #+#             */
/*   Updated: 2022/12/04 18:18:43 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

static int	putout_normal_str(const char **format)
{
	int	strlen;
	int	err;

	strlen = 0;
	while ((*format)[strlen] && (*format)[strlen] != '%')
		strlen++;
	err = putout(*format, strlen);
	(*format) += strlen;
	return (err);
}

static int	putout_formatted_str(va_list arg, const char **format)
{
	t_finfo			f_info;
	t_out			out;
	const t_putf	putf[] = {
	[TYPE_DEC] = put_num_dec_signed,
	[TYPE_INT] = put_num_dec_signed,
	[TYPE_UINT] = put_num_dec_unsigned,
	[TYPE_HEX_LOWER] = put_num_hex_unsigned,
	[TYPE_HEX_UPPER] = put_num_hex_unsigned,
	[TYPE_PTR] = put_num_ptr_address,
	[TYPE_CHAR] = put_txt_char,
	[TYPE_STR] = put_txt_str,
	[TYPE_PERSIGN] = put_txt_char};
	int				err;

	fmt_memset(f_info, 0, sizeof(*f_info));
	parse_format_info(format, f_info);
	err = putf[f_info->type](arg, f_info, out);
	free(out->str);
	return (err);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		err;

	va_start(args, format);
	while (*format && err != FAIL)
	{
		if (*format == '%' && *(format + 1))
			err = putout_formatted_str(args, &format);
		else
			err = putout_normal_str(&format);
	}
	va_end(args);
	if (!*format)
		return (writeout(STDOUT_FILENO));
	else
		return (FAIL);
}
