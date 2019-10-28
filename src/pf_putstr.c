/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouahib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 16:44:53 by aouahib           #+#    #+#             */
/*   Updated: 2019/10/28 19:09:58 by aouahib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>
int	pf_putstr(t_printf *pf, va_list *vl)
{
	char	*str;

	str = va_arg(*vl, char *);
	ft_putstr(str);
	(void)pf;
	return (ft_strlen(str));
}
