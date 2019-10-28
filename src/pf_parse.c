/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouahib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 18:56:59 by aouahib           #+#    #+#             */
/*   Updated: 2019/10/27 21:18:08 by aouahib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>
static void	set_field(t_printf *pf, char **f)
{
	char *format;

	format = *f;
	if (*format == '0')
		pf->zero = True;
	else if (*format == '-')
		pf->minus = True;
	else
	{
		if (ft_isdigit(*format))
			pf->width = ft_atoi(format);
		else if (*format == '.')
			pf->precision = ft_atoi(++format);
		while (ft_isdigit(*format))
			*format++ = '%';
		*f = format;
		return ;
	}
	*format++ = '%';
	*f = format;
}

static int	set_fields(t_printf *pf, char **format)
{
	char	*f;
	int		count;

	f = *format + 1;
	count = 1;
	while (pf_isflag(*f) || ft_isdigit(*f))
	{
		if (*f == '*')
		{
			count++;
			*f++ = '%';
		}
		else
			set_field(pf, &f);
	}
	pf->type = *f;
	if (*f == '%')
		count--;
	*format = f + 1;
	return (count);
}

static void	enlist(t_printf **head, t_printf **cur, t_printf *new)
{
	if (!*head)
	{
		*head = new;
		*cur = new;
	}
	else
	{
		(*cur)->next = new;
		*cur = new;
	}
}

static void	init(t_printf *pf)
{
	pf->type = 0;
	pf->minus = False;
	pf->zero = False;
	pf->period = False;
	pf->width = 0;
	pf->precision = 0;
}

int			pf_parse(char *f, t_printf **h)
{
	t_printf	*head;
	t_printf	*pf;
	t_printf	*cur;
	int			count;

	head = 0;
	count = 0;
	while (*f)
	{
		if (*f== '%')
		{
			pf = malloc(sizeof(t_printf));
			init(pf);
			count += set_fields(pf, &f);
			enlist(&head, &cur,pf);
		}
		else
			f++;
	}
	*h = head;
	return (count);
}
