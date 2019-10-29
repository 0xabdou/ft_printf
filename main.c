/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouahib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 19:09:54 by aouahib           #+#    #+#             */
/*   Updated: 2019/10/29 17:45:06 by aouahib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libftprintf.h"

int main()
{
	char	*f = "abcd%-0-5.4ifr**%**8#**%**x";
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
	char *format = "%50*.*s\n";
	char *s = "HELLO WORLD OMG LOL";
	int a = printf(format, 0, 0, s, 4);
	int b = ft_printf(format, 0, 0, s, 4);
	printf("%i %i\n", a, b);
}
