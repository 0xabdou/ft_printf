/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouahib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 21:54:22 by aouahib           #+#    #+#             */
/*   Updated: 2019/10/22 15:15:04 by aouahib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <errno.h>

int	ft_atoi(const char *str)
{
	long	sum;
	long	prev;
	int		sign;

	while (ft_isspace(*str))
		str++;
	sign = 1;
	if (*str == '-')
	{
		str++;
		sign = -1;
	}
	else if (*str == '+')
		str++;
	sum = 0;
	while (ft_isdigit(*str))
	{
		prev = sum;
		sum = sum * 10 + sign * (*str++ - '0');
		if (sign == 1 && sum < prev)
			return (-1);
		if (sign == -1 && sum > prev)
			return (0);
	}
	return (sum);
}
