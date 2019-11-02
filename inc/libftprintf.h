/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouahib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 17:52:22 by aouahib           #+#    #+#             */
/*   Updated: 2019/11/02 16:51:28 by aouahib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include "libft.h"
# include <stdarg.h>

typedef enum	e_bool
{
	False,
	True
}				t_bool;

typedef struct	s_printf
{
	char				type;
	t_bool				space;
	t_bool				plus;
	t_bool				minus;
	t_bool				zero;
	t_bool				period;
	t_bool				hash;
	t_bool				ll;
	t_bool				l;
	t_bool				h;
	t_bool				hh;
	int					width;
	int					precision;
	struct s_percent	*next;
}				t_printf;

int				ft_printf(const char *format, ...);
int				pf_isflag(char c);
int				pf_istype(char c);
int				pf_getdignum(unsigned long long n, int base, char type);
t_printf		*pf_parse(const char **format, va_list *vl);
int				pf_putstr(t_printf *pf, va_list *vl);
int				pf_putint(t_printf *pf, va_list *vl);
int				pf_puthex(t_printf *pf, va_list *vl);
int				pf_write_data(t_printf *pf, va_list *vl, int val);
void			pf_order(t_printf *pf, unsigned long long l);
void			pf_putprec(t_printf *pf, unsigned long long ul);
void			pf_putprefix(t_printf *pf, unsigned long long *ul);
void			pf_putwidth(int width, int zero);

#endif
