/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_getdignum.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouahib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 15:42:36 by aouahib           #+#    #+#             */
/*   Updated: 2019/10/30 16:32:19 by aouahib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	pf_getdignum(long long n, int base)
{
	int	size;

	if (!n)
		return (1);
	size = 0;
	while (n)
	{
		size++;
		n /= base;
	}
	return (size);
}
