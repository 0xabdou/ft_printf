/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouahib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 19:13:27 by aouahib           #+#    #+#             */
/*   Updated: 2019/10/28 19:18:41 by aouahib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	pf_putint(t_printf *pf, va_list *vl)
{
	ft_putnbr_fd(va_arg(*vl, int), 1);
	(void)pf;
	return (0);
}
