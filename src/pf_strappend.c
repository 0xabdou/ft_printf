/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_strappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouahib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 17:28:08 by aouahib           #+#    #+#             */
/*   Updated: 2019/11/04 17:32:43 by aouahib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

int	pf_strappend(t_string **s, char c)
{
	t_string *new;

	if (!s)
		return ;
	new = malloc(sizeof(t_string));
	if (!new)
		return (-1);
	new->next = 0;
	new->c = c;
	if (!*s)
		*s = new;
	else
	{
		w	
	}
}
