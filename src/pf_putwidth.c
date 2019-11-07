/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putwidth.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouahib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 16:40:57 by aouahib           #+#    #+#             */
/*   Updated: 2019/11/07 22:12:12 by aouahib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	pf_putwidth(int width, int zero)
{
	int	i;

	i = 0;
	while (i++ < width)
		ft_putchar(zero ? '0' : ' ');
}
