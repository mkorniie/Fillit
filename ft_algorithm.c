/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 16:46:30 by mkorniie          #+#    #+#             */
/*   Updated: 2017/12/25 16:55:42 by mkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "header.h"

void	ft_chartoint(int (*res)[], char *fig)
{
	int i;
	int s;
	int pos;

	ft_free(&i, &s, &pos, res);
	while (fig[++i] != '\0')
		if (fig[i] == '#')
		{
			(*res)[s] <<= 1;
			(*res)[s] ^= 1;
			pos++;
		}
		else if (fig[i] == '\n')
		{
			(*res)[s] <<= ((int)(sizeof(int) * 8) - pos);
			pos = 1;
			s++;
		}
		else
		{
			(*res)[s] <<= 1;
			pos++;
		}
	(*res)[s] <<= ((int)(sizeof(int) * 8) - pos);
}

int		ft_t(int m_line, int f_line, char *fig, int *n)
{
	int test;

	if (fig[1] + fig[2] > *n)
		return (0);
	test = f_line;
	test >>= fig[0];
	if ((m_line & test) == 0)
		if ((test <<= (*n + 1)) == 0)
			return (1);
	return (0);
}

int		ft_place(int (*map)[], int *n, char *fig, int (*arr)[])
{
	int i;
	int flag;

	while ((fig[0] < (*n + 1)) && (fig[1] < *n))
	{
		if (fig[0] == -1 || fig[0] == *n)
		{
			fig[1]++;
			fig[0] = 0;
			if (fig[1] > *n)
				return (-1);
		}
		else
			fig[0]++;
		i = -1;
		flag = 0;
		while (++i < 4)
			if (ft_t((*map)[fig[1] + i], (*arr)[i], fig, n))
				flag++;
			else
				break ;
		if (flag == 4)
			return (0);
	}
	return (-1);
}

int		ft_fit(int (*map)[], int *n, char ***fig, int i)
{
	int			z;
	static	int	arr[26][4];
	int			hold;

	z = -1;
	if ((*fig)[i][0] == -1)
	{
		ft_chartoint(&(arr[i]), (*fig)[i]);
	}
	else
		while (++z < HEIGHT(i))
		{
			hold = arr[i][z] >> X_POS(i);
			(*map)[Y_POS(i) + z] ^= hold;
		}
	if (ft_place(map, n, (*fig)[i], &(arr[i])) == -1)
		return (0);
	z = -1;
	while (++z < HEIGHT(i))
	{
		hold = arr[i][z] >> X_POS(i);
		(*map)[Y_POS(i) + z] |= hold;
	}
	return (1);
}

int		ft_recurs(int (*map)[], int *n, char ***fig)
{
	int			min;
	static	int	i;

	if ((*fig)[i] == 0)
		return (*n);
	if (ft_fit(map, n, fig, i++) == 0)
	{
		i--;
		(*fig)[i][1] = -1;
		(*fig)[i][0] = -1;
		return (0);
	}
	min = ft_recurs(map, n, fig);
	if (min == 0)
	{
		i--;
		min = ft_recurs(map, n, fig);
	}
	return (min);
}
