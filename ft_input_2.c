/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 16:52:33 by mkorniie          #+#    #+#             */
/*   Updated: 2017/12/25 16:59:21 by mkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "libft.h"

size_t	len_1(const char *s)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while (s[i] != '#' && s[i] != '.')
		i++;
	j = i;
	while (s[j] != '\0' && s[j] != '*')
		j++;
	return (j - i);
}

void	ft_trim(char **fin, char **s)
{
	int a;
	int k;
	int j;

	a = 0;
	j = 3;
	while (s[a])
	{
		k = 0;
		while (s[a][k] != '#' && s[a][k] != '.')
			k++;
		while (s[a][k] != '\0' && s[a][k] != '*')
		{
			if (s[a][k] == '*')
				k++;
			(*fin)[j] = s[a][k];
			k++;
			j++;
		}
		(*fin)[j++] = '\n';
		a++;
	}
	(*fin)[--j] = '\0';
}

char	*ft_string(char **s)
{
	char	*fin;
	int		k;
	int		a;

	a = -1;
	k = 0;
	while (s[++a] != 0)
		k = len_1(s[a]) + k;
	if ((fin = ((char *)malloc(sizeof(char) * (k + a + 4)))) == NULL)
		return (NULL);
	fin[0] = -1;
	fin[1] = -1;
	fin[2] = a;
	ft_trim(&fin, s);
	ft_freearr(s);
	return (fin);
}

int		column_check(char **str, int i)
{
	int j;

	j = 0;
	while (j < 4)
	{
		if (str[j][i] == '#')
			return (1);
		j++;
	}
	return (0);
}

char	*cut_chunk(char *s)
{
	char	**chunk;
	char	**trim;
	int		n[3];
	char	*string;

	chunk = ft_strsplit(s, '\n');
	trim = (char **)malloc(sizeof(char*) * (columns(s) + 1));
	n[0] = 0;
	n[2] = -1;
	while (chunk[++n[2]])
		if (raw_check(chunk[n[2]]) != 0)
		{
			trim[n[0]] = (char *)malloc(sizeof(char) * (4 + 1));
			n[1] = -1;
			while (++n[1] < 4)
				if (column_check(chunk, n[1]) == 0)
					trim[n[0]][n[1]] = '*';
				else
					trim[n[0]][n[1]] = chunk[n[2]][n[1]];
			trim[n[0]++][n[1]] = '\0';
		}
	trim[n[0]] = 0;
	string = ft_string(trim);
	ft_freearr(chunk);
	return (string);
}
