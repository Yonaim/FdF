/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_internal.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 04:30:53 by yona              #+#    #+#             */
/*   Updated: 2022/12/04 17:43:03 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_INTERNAL_H
# define FT_PRINTF_INTERNAL_H

/*--------------- STANDARD HEADERS ----------------*/

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

/*-------------- USER DEFINED HEADERS --------------*/

# include "utils.h"

/* ----------- DEFINE MACRO CONSTANTS ------------*/

# define FAIL			-1
# define SUCCESS		0

# define BUFFER_SIZE 	256

# define TYPES			"\\diuxXpcs%"
# define TYPE_DEC 		1
# define TYPE_INT		2
# define TYPE_UINT		3
# define TYPE_HEX_LOWER	4
# define TYPE_HEX_UPPER	5
# define TYPE_PTR		6
# define TYPE_CHAR		7
# define TYPE_STR		8
# define TYPE_PERSIGN	9

# define FLAGS			"-+ #0"
# define FLAG_LEFT		0x01
# define FLAG_PLUS		0x02
# define FLAG_SPACE		0x04
# define FLAG_HASH		0x08
# define FLAG_ZERO		0x10
# define FLAG_PRECISION	0x20

/*------------- STRUCT DECLARATIONS --------------*/

typedef struct s_finfo
{
	int		type;
	int		width;
	int		flag;
	int		prsc;
	int		pad;
}	t_finfo[1];

typedef struct s_out
{
	char	*str;
	int		len;
}	t_out[1];

typedef struct s_arg
{
	char		*str;
	int			strlen;
	int			spc;
}	t_arg;

typedef struct s_pref
{
	char	str[2];
	int		len;
}	t_pref;

typedef struct s_node
{
	char			buf[BUFFER_SIZE];
	int				fillbyte;
	struct s_node	*next;
}	t_node;

/*-------------- TYPE DECLARATIONS ---------------*/

typedef unsigned long long	t_uint64;
typedef unsigned int		t_uint32;
typedef long long			t_int64;
typedef int					t_int32;
typedef int					(*t_putf)(va_list, t_finfo, t_out);

/*-------------- FUNCTION PROTOTYPES -------------*/

/* out */
int		putout(const char *str, int nbyte);
int		writeout(int fd);

/* formatted string */
void	parse_format_info(const char **format, t_finfo f_info);
int		put_txt_char(va_list arg, t_finfo f_info, t_out out);
int		put_txt_str(va_list arg, t_finfo f_info, t_out out);
int		put_num_dec_signed(va_list arg, t_finfo f_info, t_out out);
int		put_num_dec_unsigned(va_list arg, t_finfo f_info, t_out out);
int		put_num_hex_unsigned(va_list arg, t_finfo f_info, t_out out);
int		put_num_ptr_address(va_list arg, t_finfo f_info, t_out out);

/* utils for only formatted */
char	*fmt_itoa(t_int64 n, int prsc, char *sign);
char	*fmt_uitoa(t_uint64 n, int prsc, int type);
t_node	*fmt_lstlast(t_node *lst);
void	fmt_lstallclear(t_node *const startnode);
t_node	*fmt_lstaddnew_back(t_node *lst);

#endif
