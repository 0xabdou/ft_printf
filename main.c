/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouahib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 19:09:54 by aouahib           #+#    #+#             */
/*   Updated: 2019/10/28 21:01:41 by aouahib          ###   ########.fr       */
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
	ft_printf("Hello %-05*.4*i, world %s\n", 7, 3, 8, "LOL");
	printf("%08.5#0i\n", 9);
}
