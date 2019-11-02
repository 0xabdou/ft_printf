/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouahib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 19:13:27 by aouahib           #+#    #+#             */
/*   Updated: 2019/11/02 16:57:11 by aouahib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

static long long	get_arg(t_printf *pf, va_list *vl)
{
	long long l;

	l = va_arg(*vl, long long);
	if (pf->type == 'u')
	{
		if (pf->ll)
			l = (unsigned long long)l;
		else if (pf->l)
			l = (unsigned long)l;
		else if (pf->h)
			l = (unsigned short)l;
		else if (pf->ll)
			l = (unsigned char)l;
	}
	else if (pf->type == 'i' || pf->type == 'd')
	{
		if (pf->ll)
			l = (long long)l;
		else if (pf->l)
			l = (long)l;
		else if (pf->h)
			l = (short)l;
		else if (pf->hh)
			l = (char)l;
		else
			l = (int)l;
	}
	else
		l = (int)l;
	return (l);
}

int					pf_putint(t_printf *pf, va_list *vl)
{
	int			size;
	unsigned long long	n;

	if (pf->type == '%')
		n = '%';
	else
		n = get_arg(pf, vl);
	if (pf->type == 'c' || pf->type == '%')
		size = 1;
	else if (!n && !pf->precision && pf->period)
		size = 0;
	else
		size = pf_getdignum(n, 10, pf->type);
	pf->space = pf->type == 'u' || pf->type == 'c' ? 0 : pf->space;
	pf->space = pf->type == '%' ? 0 : pf->space;
	pf->plus = pf->type == 'u' || pf->type == 'c'? 0 : pf->plus;
	pf->plus = pf->type != 'u' && (long long)n < 0 ? 0 : pf->plus;
	pf->plus = pf->type == '%' ? 0 : pf->plus;
	pf->precision = pf->type == 'c' || pf->type == '%' ? 0 : pf->precision;
	pf->zero = pf->zero && !pf->precision && !pf->minus;
	pf->precision = pf->precision - size;
	pf->precision = pf->precision < 0 ? 0 : pf->precision;
	size += (pf->type != 'u' && ((long long)n < 0)) || pf->plus || pf->space;
	pf->width = pf->width - pf->precision - size;
	pf->width = pf->width < 0 ? 0 : pf->width;
	pf_order(pf, n);
	return (size + pf->width + pf->precision + pf->space);
}
