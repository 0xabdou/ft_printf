/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouahib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 17:52:22 by aouahib           #+#    #+#             */
/*   Updated: 2019/10/25 20:53:47 by aouahib          ###   ########.fr       */
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
	char			type;
	t_bool			minus;
	t_bool			zero;
	t_bool			period;
	int				width;
	int				precision;
	struct s_printf	*next;
}				t_printf;

int				ft_printf(const char *format, ...);
int				pf_isflag(char c);
int				pf_istype(char c);
int				pf_count(char *f);
int				pf_parse(char *f, t_printf **h);
#endif
