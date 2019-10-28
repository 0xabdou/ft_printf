/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouahib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 19:45:27 by aouahib           #+#    #+#             */
/*   Updated: 2019/10/18 23:47:10 by aouahib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	fill(char **split, const char *s, char c, int count)
{
	int	i;
	int	j;
	int	start;
	int	len;

	i = 0;
	j = 0;
	while (j < count)
	{
		while (s[i] == c)
			i++;
		start = i;
		len = 0;
		while (s[i] && s[i] != c)
		{
			len++;
			i++;
		}
		split[j] = ft_substr(s, start, len);
		j++;
	}
	split[count] = 0;
}

char		**ft_split(char const *s, char c)
{
	char	**split;
	int		i;
	int		count;

	if (!s)
		return (0);
	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || !s[i + 1]))
			count++;
		i++;
	}
	split = malloc(count * sizeof(char *) + 1);
	if (!split)
		return (0);
	fill(split, s, c, count);
	return (split);
}
