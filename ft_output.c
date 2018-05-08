/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 16:48:39 by mkorniie          #+#    #+#             */
/*   Updated: 2017/12/25 16:49:55 by mkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "libft.h"

void	ft_free(int *i, int *s, int *pos, int (*res)[])
{
	*i = -1;
	while (++(*i) < 4)
		(*res)[(*i)] = 0;
	*i = 2;
	*s = 0;
	*pos = 1;
}

void	ft_print_arr(char **arr, int n)
{
	int i;

	i = -1;
	while (++i < n)
	{
		ft_putstr(arr[i]);
		ft_putchar('\n');
	}
}

void	ft_fill_arr(char ***fig, char **arr)
{
	int i;
	int x;
	int y;
	int a;

	i = -1;
	while ((*fig)[++i])
	{
		x = (*fig)[i][0];
		y = (*fig)[i][1];
		if (x == -1)
			break ;
		a = 2;
		while ((*fig)[i][++a] != '\0')
		{
			if ((*fig)[i][a] == '\n')
			{
				x = (*fig)[i][0] - 1;
				y++;
			}
			else if ((*fig)[i][a] == '#')
				arr[y][x] = 65 + i;
			x++;
		}
	}
}

void	ft_dsply(char ***fig, int n)
{
	char	**arr;
	int		i;

	arr = (char**)malloc(sizeof(char*) * (n + 1));
	arr[n] = 0;
	i = -1;
	while (++i < n)
	{
		arr[i] = (char*)malloc(sizeof(char) * (n + 1));
		arr[i][n] = '\0';
		ft_memset(arr[i], '.', n);
	}
	ft_fill_arr(fig, arr);
	ft_print_arr(arr, n);
	i = -1;
	ft_freearr(arr);
	ft_freearr(*fig);
}
