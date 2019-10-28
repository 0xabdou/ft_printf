/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouahib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 19:09:54 by aouahib           #+#    #+#             */
/*   Updated: 2019/10/27 23:11:08 by aouahib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libftprintf.h"

void put_printf(t_printf *p)
{
	printf("type:%c, minus:%i, zero:%i, period:%i. width:%i, prec:%i\n",
			p->type, p->minus, p->zero, p->period, p->width, p->precision);
}

int main()
{
	char	*f = "abcd%5.4ifr**%**8#**%**x";
	t_printf *head = 0;
	char *sf = ft_strdup(f);
	int cnt = pf_parse(sf, &head);
	t_printf *h = head;
	while (h)
	{
		put_printf(h);
		h = h->next;
	}
	printf("cnt:%i, f:%s\n", cnt, sf);
	printf("%***.**i", 5,3,2,1, 5,2);
}
