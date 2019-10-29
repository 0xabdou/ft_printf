/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_istype.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouahib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 14:29:15 by aouahib           #+#    #+#             */
/*   Updated: 2019/10/28 11:53:11 by aouahib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	pf_istype(char c)
{
	return (c == 'c'
			|| c == 's'
			|| c == 'p'
			|| c == 'd'
			|| c == 'i'
			|| c == 'u'
			|| c == 'x'
			|| c == 'X');
}