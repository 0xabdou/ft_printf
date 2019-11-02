/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouahib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 19:13:27 by aouahib           #+#    #+#             */
/*   Updated: 2019/11/02 21:59:25 by aouahib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

static void	adjust_flags(t_printf *pf, int *size, unsigned long long n)
{
	pf->space = pf->type == 'u' || pf->type == 'c' ? 0 : pf->space;
	pf->space = pf->type == '%' ? 0 : pf->space;
	pf->plus = pf->type == 'u' || pf->type == 'c' ? 0 : pf->plus;
	pf->plus = pf->type != 'u' && (long long)n < 0 ? 0 : pf->plus;
	pf->plus = pf->type == '%' ? 0 : pf->plus;
	pf->precision = pf->type == 'c' || pf->type == '%' ? 0 : pf->precision;
	pf->zero = pf->zero && !pf->precision && !pf->minus;
	pf->precision = pf->precision - *size;
	pf->precision = pf->precision < 0 ? 0 : pf->precision;
	*size += (pf->type != 'u' && ((long long)n < 0)) || pf->plus || pf->space;
	pf->width = pf->width - pf->precision - *size;
	pf->width = pf->width < 0 ? 0 : pf->width;
}

int			pf_putint(t_printf *pf, va_list *vl)
{
	int					size;
	unsigned long long	n;

	if (pf->type == '%')
		n = '%';
	else
		n = pf_getarg(pf, vl);
	if (pf->type == 'c' || pf->type == '%')
		size = 1;
	else if (!n && !pf->precision && pf->period)
		size = 0;
	else
		size = pf_getdignum(n, 10, pf->type);
	adjust_flags(pf, &size, n);
	pf_order(pf, n);
	return (size + pf->width + pf->precision + pf->space);
}
