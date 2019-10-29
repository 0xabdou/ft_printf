/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouahib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 17:18:56 by aouahib           #+#    #+#             */
/*   Updated: 2019/10/29 14:02:32 by aouahib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*sub;

	if (!s)
		return (0);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	sub = malloc(len + 1);
	if (sub)
		ft_strlcpy(sub, s + start, len + 1);
	return (sub);
}
