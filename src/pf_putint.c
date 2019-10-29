/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouahib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 19:13:27 by aouahib           #+#    #+#             */
/*   Updated: 2019/10/29 14:24:54 by aouahib          ###   ########.fr       */
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

int	pf_putint(t_printf *pf, va_list *vl)
{
	int	size;
	int	width;
	int precision;
	int	zero;
	int	n;
	int	i;

	n = va_arg(*vl, int);
	size = get_size(n);
	width = pf->width - pf->precision - size;
	precision = size - pf->precision;
	zero = pf->zero && !pf->precision;
	i = 0;
	while (i++ < width)
		ft_putchar(zero ? '0' : ' ');
	i = 0;
	while (i++ < precision)
		ft_putchar('0');
	ft_putnbr(n);

	return (0);
}
