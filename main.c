/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouahib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 19:09:54 by aouahib           #+#    #+#             */
/*   Updated: 2019/10/30 18:19:43 by aouahib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libftprintf.h"

int main()
{
	char *o = "or: %-0.5u\n";
	char *f = "ft: %-0.5u\n";
	int n = -1;
	int a = printf(o, &n);
	int b = ft_printf(f, &n);
	printf("%i %i\n", a, b);
}
