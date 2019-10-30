/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouahib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 19:09:54 by aouahib           #+#    #+#             */
/*   Updated: 2019/10/30 16:48:58 by aouahib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libftprintf.h"

int main()
{
	//t_printf *head = 0;
	//int cnt = pf_parse(f, &head);
	//t_printf *h = head;
	//while (h)
	//{
	//	put_printf(h);
	//	h = h->next;
	//}
	//printf("cnt:%i, f:%s\n", cnt, f);
	//printf("h%.immmh", 5,3,2,1, 5,2);
	//ft_printf("Hello %-05*.4*i, world %s\n", 7, 3, 8, "LOL");
	//char *format = "%50*.*-i\n";
	//int a = printf(format, 9, 4, 20, 4);
	//int b = ft_printf(format, 9, 4, 20, 4);
	//printf("%i %i\n", a, b);
	//char *format = "%05c%50*.*s\n";
	//char *s = "HELLO WORLD OMG LOL";
	//int a = printf(format, 'z', 0, 0, s, 4);
	//int b = ft_printf(format, 'z', 0, 0, s, 4);
	//printf("%i %i\n", a, b);
	char *s = "ft: %-20**10i,%0.5c\n";
	int n = 2147483647, w = 50, p = 100;
	char c = 'z';
	int a, b;
	a = b = -1;
	a = printf(s, n, w, p, c);
	b = ft_printf(s, n, w, p, c);
	printf("%i %i\n", a, b);
}
