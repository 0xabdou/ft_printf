/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouahib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 19:13:27 by aouahib           #+#    #+#             */
/*   Updated: 2019/10/30 19:46:41 by aouahib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	put_width(int width, int zero)
{
	int	i;

	i = 0;
	while (i++ < width)
		ft_putchar(zero ? '0' : ' ');
}

static void	put_prec_nbr(long n, int prec, char type)
{
	int	i;

	i = 0;
	while (type != 'c' && i++ < prec)
		ft_putchar('0');
	type == 'c' ? ft_putchar(n) : ft_putnbr(n);
}

static void	priority(t_printf *pf, long l)
{
	if (l < 0)
	{
		ft_putchar('-');
		l *= -1;
	}
	if (pf->minus)
	{
		put_prec_nbr(l, pf->precision, pf->type);
		put_width(pf->width, pf->zero);
	}
	else
	{
		put_width(pf->width, pf->zero);
		put_prec_nbr(l, pf->precision, pf->type);
	}
}
#include <stdio.h>
int			pf_putint(t_printf *pf, va_list *vl)
{
	int		size;
	long	n;

	if (pf->type == 'u')
		n = va_arg(*vl, unsigned int);
	else
		n = va_arg(*vl, int);
	size = pf->type == 'c' ? 1 : pf_getdignum(n, 10);
	pf->precision = pf->type == 'c' ? 0 : pf->precision;
	pf->zero = pf->zero && !pf->precision && !pf->minus;
	pf->precision = pf->precision - size;
	pf->precision = pf->precision < 0 ? 0 : pf->precision;
	pf->width = pf->width - pf->precision - size;
	pf->width = pf->width < 0 ? 0 : pf->width;
	size += (n < 0);
	priority(pf, n);
	return (size + pf->width + pf->precision);
}
