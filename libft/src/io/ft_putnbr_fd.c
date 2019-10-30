/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouahib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 23:22:02 by aouahib           #+#    #+#             */
/*   Updated: 2019/10/30 13:36:26 by aouahib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	recursive_print(long n, int fd)
{
	if (!n)
		return ;
	recursive_print(n / 10, fd);
	ft_putchar_fd(ABS(n % 10) + '0', fd);
}

void		ft_putnbr_fd(long n, int fd)
{
	if (!n)
		ft_putchar_fd('0', fd);
	else
	{
		if (n < 0)
			ft_putchar_fd('-', fd);
		recursive_print(n, fd);
	}
}
