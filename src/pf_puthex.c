/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouahib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 16:55:47 by aouahib           #+#    #+#             */
/*   Updated: 2019/10/31 15:14:26 by aouahib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	put_hex(unsigned long h, char type)
{
	char *hex;

	if (!h)
		return ;
	hex = type == 'X'
		? "0123456789ABCDEF"
		: "0123456789abcdef";
	put_hex(h / 16, type);
	ft_putchar(hex[h % 16]);
}

static void	put_width(int width, int zero)
{
	int	i;

	i = 0;
	while (i++ < width)
		ft_putchar(zero ? '0' : ' ');
}

static void	put_prec_nbr(t_printf *pf, unsigned long n)
{
	int	i;

	i = 0;
	while (i++ < pf->precision)
		ft_putchar('0');
	if (!n)
		ft_putchar('0');
	else
		put_hex(n, pf->type);
}

static void	priority(t_printf *pf, unsigned long h)
{
	if (pf->minus)
	{
		if (pf->hash)
			ft_putstr("0x");
		put_prec_nbr(pf, h);
		put_width(pf->width, pf->zero);
	}
	else
	{
		put_width(pf->width, pf->zero);
		if (pf->hash)
			ft_putstr("0x");
		put_prec_nbr(pf, h);
	}
}

int			pf_puthex(t_printf *pf, va_list *vl)
{
	unsigned long	h;
	int				size;

	if (pf->type == 'p')
		h = va_arg(*vl, unsigned long);
	else
		h = va_arg(*vl, unsigned int);
	size = pf_getdignum(h, 16);
	pf->zero = pf->zero && !pf->precision && !pf->minus;
	pf->precision = pf->precision - size;
	pf->precision = pf->precision < 0 ? 0 : pf->precision;
	pf->hash = pf->hash || pf->type == 'p';
	if (pf->hash)
		size += 2;
	pf->width = pf->width - pf->precision - size;
	pf->width = pf->width < 0 ? 0 : pf->width;
	priority(pf, h);
	return (size + pf->width + pf->precision);
}
