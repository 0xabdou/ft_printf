/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouahib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 18:56:59 by aouahib           #+#    #+#             */
/*   Updated: 2019/10/31 21:47:31 by aouahib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	set_field(const char **format, t_printf *pf)
{
	const char *f;

	f = *format;
	if (*f == '0')
		pf->zero = True;
	else if (*f == '#')
		pf->hash = True;
	else if (*f == '+')
		pf->plus = True;
	else if (*f == ' ')
		pf->space = True;
	else if (*f == '-')
		pf->minus = True;
	else
	{
		if (ft_isdigit(*f))
			pf->width = ft_atoi(f);
		else if (*f == '.')
		{
			pf->precision = ft_atoi(++f);
			pf->period = True;
		}
		while (ft_isdigit(*f))
			f++;
		*format = f;
		return ;
	}
	*format = ++f;
}

static void	set_format(const char **format, t_printf *pf)
{
	const char	*f;

	f = *format;
	if (*f == 'l' && *(f + 1) == 'l')
	{
		pf->ll = True;
		f += 2;
	}
	else if (*f == 'l')
	{
		pf->l = True;
		f++;
	}
	else if (*f == 'h' && *(f + 1) == 'h')
	{
		pf->hh = True;
		f += 2;
	}
	else if (*f == 'h')
	{
		pf->h = True;
		f++;
	}
	*format = f;
}

static void	set_fields(const char **format, va_list *vl, t_printf *pf)
{
	const char	*f;

	f = *format;
	while (pf_isflag(*f) || ft_isdigit(*f) || *f == 'l' || *f == 'h')
	{
		if (*f == '*')
			pf->width = va_arg(*vl, int);
		else if (*f == '.' && *(f + 1) == '*')
		{
			pf->period = True;
			pf->precision = va_arg(*vl, int);
			f++;
		}
		else if (*f == 'l' || *f == 'h')
		{
			set_format(&f, pf);
			continue;
		}
		{
			set_field(&f, pf);
			continue ;
		}
		f++;
	}
	pf->type = *f;
	*format = ++f;
}

static void	init(t_printf *p)
{
	p->type = 0;
	p->space = False;
	p->plus = False;
	p->minus = False;
	p->zero = False;
	p->period = False;
	p->hash = False;
	p->width = 0;
	p->precision = 0;
	p->ll = 0;
	p->l = 0;
	p->hh = 0;
	p->h = 0;
}

t_printf	*pf_parse(const char **format, va_list *vl)
{
	t_printf	*pf;

	pf = malloc(sizeof(t_printf));
	if (!pf)
		return (0);
	init(pf);
	set_fields(format, vl, pf);
	return (pf);
}
