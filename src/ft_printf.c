/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouahib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 17:46:44 by aouahib           #+#    #+#             */
/*   Updated: 2019/11/04 19:09:39 by aouahib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

static int	put_printf(t_printf *pf, va_list *vl, int res)
{
	char	c;

	c = pf->type;
	if (!pf_istype(c))
	{
		ft_putchar(c);
		return (1);
	}
	if (c == 's')
		return (pf_putstr(pf, vl));
	else if (c == '%' || c == 'c' || c == 'd' || c == 'i' || c == 'u')
		return (pf_putint(pf, vl));
	else if (c == 'p' || c == 'x' || c == 'X')
		return (pf_puthex(pf, vl));
	else if (c == 'n')
		return (pf_write_data(pf, vl, res));
	return (0);
}
#include <stdio.h>
static int	append(t_linked_char **lc, char c)
{
	static t_linked_char	*cur;
	t_linked_char			*new;

	new = pf_lcnew(c);
	if (!new)
		return (0);
	if (!*lc)
	{
		*lc = new;
		cur = new;
	}
	else
	{
		cur->next = new;
		cur = new;
	}
	return (1);
}

int			ft_printf(const char *format, ...)
{
	va_list			valist;
	t_printf		*pf;
	t_linked_char	*lc;
	int				res;

	va_start(valist, format);
	lc = 0;
	res = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			pf = pf_parse(&format, &valist);
			if (!pf || (pf->type == 'c' && pf->l))
			{
				free(pf);
				pf_lcclear(&lc);
				return (-1);
			}
			pf_lcprint_n_clear(&lc);
			res += put_printf(pf, &valist, res);
			free(pf);
		}
		else
		{
			if (!append(&lc, *format++))
			{
				pf_lcclear(&lc);
				return (-1);
			}
			res++;
		}
	}
	pf_lcprint_n_clear(&lc);
	return (res);
}
