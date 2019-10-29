/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouahib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 19:13:27 by aouahib           #+#    #+#             */
/*   Updated: 2019/10/29 17:09:02 by aouahib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	get_size(int n)
{
	int	size;

	if (!n)
		return (1);
	size = 0;
	while (n)
	{
		size++;
		n /= 10;
	}
	return (size);
}

static void	put_width(int width, int zero)
{
	int	i;

	i = 0;
	while (i++ < width)
		ft_putchar(zero ? '0' : ' ');
}

static void	put_prec_nbr(int n, int prec)
{
	int	i;

	i = 0;
	while (i++ < prec)
		ft_putchar('0');
	ft_putnbr(n);
}

int			pf_putint(t_printf *pf, va_list *vl)
{
	int	size;
	int	width;
	int precision;
	int	zero;
	int	n;

	n = va_arg(*vl, int);
	size = get_size(n);
	precision = pf->precision - size;
	precision = precision < 0 ? 0 : precision;
	width = pf->width - (precision) - size;
	width = width < 0 ? 0 : width;
	zero = pf->zero && !pf->precision && !pf->minus;
	if (pf->minus)
	{
		put_prec_nbr(n, precision);
		put_width(width, zero);
	}
	else
	{
		put_width(width, zero);
		put_prec_nbr(n, precision);
	}
	return (size + width + precision);
}
