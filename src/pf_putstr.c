/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouahib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 16:44:53 by aouahib           #+#    #+#             */
/*   Updated: 2019/10/29 17:38:04 by aouahib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	put_width(int width)
{
	while (width--)
		ft_putchar(' ');
}

static void	putnstr(char *s, int n)
{
	while (n && *s)
	{
		ft_putchar(*s++);
		n--;
	}
}

int			pf_putstr(t_printf *pf, va_list *vl)
{
	char	*str;
	int		len;
	int		width;

	str = va_arg(*vl, char *);
	len = ft_strlen(str);
	len = len < pf->precision ? len : pf->precision;
	width = pf->width - len;
	width = width < 0 ? 0 : width;
	if (pf->minus)
	{
		putnstr(str, len);
		put_width(width);
	}
	else
	{
		put_width(width);
		putnstr(str, len);
	}
	return (width + len);
}
