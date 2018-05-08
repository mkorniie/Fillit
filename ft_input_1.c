/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 16:40:57 by mkorniie          #+#    #+#             */
/*   Updated: 2017/12/25 16:46:11 by mkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "libft.h"

size_t	smb_nbr(int argc, char *argv)
{
	char	buff;
	int		fd;
	size_t	i;

	i = 0;
	argc++;
	fd = open(argv, O_RDONLY);
	while (read(fd, &buff, 1) > 0)
		i++;
	close(fd);
	return (i);
}

size_t	t_nbr(char *s)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		if (*s == '#')
			count++;
		s++;
	}
	count = count / 4;
	return (count);
}

int		raw_check(char *s)
{
	while (*s)
	{
		if (*s == '#')
			return (1);
		s++;
	}
	return (0);
}

int		columns(char *str)
{
	char	**s;
	int		j;
	int		count;

	s = ft_strsplit(str, '\n');
	j = 0;
	count = 0;
	while (s[j])
	{
		if (raw_check(s[j]) == 1)
			count++;
		j++;
	}
	ft_freearr(s);
	return (count);
}

int		main(int argc, char **argv)
{
	char		*content;
	int			i;
	int			map[16];
	char		**split;
	char		**final;

	if (ft_validate(argc, argv, &content, &split) == 0)
		return (0);
	i = -1;
	while (++i < 16)
		map[i] = 0;
	final = (char**)malloc(sizeof(char*) * (t_nbr(content) + 1));
	i = -1;
	while (split[++i] != 0)
		final[i] = cut_chunk(split[i]);
	final[i] = 0;
	ft_freearr(split);
	i = ft_sqrt(t_nbr(content) * 4);
	i = (ft_pow(i, 2) < (long)(t_nbr(content) * 4) ? i + 1 : i);
	if (t_nbr(content) <= 26)
		while (ft_recurs(&map, &i, &final) == 0)
			i++;
	free(content);
	ft_dsply(&(final), i);
	return (0);
}
