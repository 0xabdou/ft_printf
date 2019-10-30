/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouahib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 19:13:27 by aouahib           #+#    #+#             */
/*   Updated: 2019/10/30 11:56:21 by aouahib          ###   ########.fr       */
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

static void	put_prec_nbr(int n, int prec, char type)
{
	int	i;

	i = 0;
	while (i++ < prec)
		ft_putchar('0');
	type == 'c' ? ft_putchar(n) : ft_putnbr(n);
}

int			pf_putint(t_printf *pf, va_list *vl)
{
	int	size;
	int	width;
	int precision;
	int	zero;
	int	n;

	n = va_arg(*vl, int);
	size = pf->type == 'c' ? 1 : pf_getdignum(n, 10);
	precision = pf->precision - size;
	precision = precision < 0 ? 0 : precision;
	width = pf->width - precision - size;
	width = width < 0 ? 0 : width;
	zero = pf->zero && !pf->precision && !pf->minus;
	if (pf->minus)
	{
		put_prec_nbr(n, precision, pf->type);
		put_width(width, zero);
	}
	else
	{
		put_width(width, zero);
		put_prec_nbr(n, precision, pf->type);
	}
	return (size + width + precision);
}
