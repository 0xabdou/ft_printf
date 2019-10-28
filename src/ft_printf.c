/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouahib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 17:46:44 by aouahib           #+#    #+#             */
/*   Updated: 2019/10/28 19:19:04 by aouahib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>
void put_printf(t_printf *pf, va_list *vl)
{
	char	c;

	(void)vl;
	c = pf->type;
	if (!pf_istype(c))
	{
		ft_putchar(c);
		return;
	}
	if (c == 's')
		pf_putstr(pf, vl);
	////else if (c == 'p')
	////	pf_putptr(pf, vl);
	else if (c == 'd' || c == 'i' || c == 'u')
		pf_putint(pf, vl);
	////else if (c == 'x' || c == 'X')
	////	pf_puthex(pf, vl);
	else
		printf("(type:%c, minus:%i, zero:%i, period:%i. width:%i, prec:%i)",
				pf->type, pf->minus, pf->zero, pf->period, pf->width, pf->precision);
}

int	ft_printf(const char *format, ...)
{
	va_list		valist;
	t_printf	*pf;

	va_start(valist, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			pf = pf_parse(&format, &valist);
			if (!pf)
				return (-1);
			put_printf(pf, &valist);
			free(pf);
		}
		else
			ft_putchar(*format++);
	}
	return (0);
}
