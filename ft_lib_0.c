/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 16:13:32 by mkorniie          #+#    #+#             */
/*   Updated: 2017/12/25 16:40:30 by mkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "libft.h"

void		ft_freearr(char **split)
{
	int i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void		*ft_memset(void *str, int c, size_t n)
{
	size_t			i;
	unsigned char	*s;

	i = 0;
	s = (unsigned char *)str;
	while (i < n)
	{
		s[i] = c;
		i++;
	}
	return ((void *)s);
}

static int	root(int nb)
{
	int max;
	int min;

	max = 46340;
	min = 0;
	while (max != (min + 1))
	{
		if ((((max + min) / 2) * ((max + min) / 2)) == nb)
			return ((max + min) / 2);
		if ((((max + min) / 2) * ((max + min) / 2)) > nb)
			max = (max + min) / 2;
		else
			min = (max + min) / 2;
	}
	return ((max + min) / 2);
}

int			ft_sqrt(int nb)
{
	if (nb <= 0 || nb > 2147395600)
		return (0);
	if (nb == 1)
		return (1);
	if (nb == 2147395600)
		return (46340);
	return (root(nb));
}
