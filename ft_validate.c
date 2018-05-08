/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 16:59:31 by mkorniie          #+#    #+#             */
/*   Updated: 2017/12/25 17:13:11 by mkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "libft.h"

char	**ft_strsplit1(char *s)
{
	char		**res;
	size_t		i;
	size_t		nb;
	size_t		j;

	res = (char**)malloc(sizeof(char*) * (t_nbr(s) + 1));
	i = -1;
	nb = 0;
	while (s[++i])
		if (s[i] == '.' || s[i] == '#')
		{
			res[nb] = (char*)malloc(sizeof(char) * (20));
			j = -1;
			while ((++j <= 19) && !(s[i + 1] == '\0'))
			{
				if (s[i] == '\n' && s[i + 1] == '\n')
					break ;
				res[nb][j] = s[i++];
			}
			res[nb][j] = '\0';
			nb++;
		}
	res[nb] = 0;
	return (res);
}

char	*map_read(int argc, char *argv)
{
	char	buff;
	int		fd;
	int		i;
	char	*res;

	if (!(res = (char*)malloc(sizeof(char) * (smb_nbr(argc, argv) + 1))))
		return (NULL);
	i = 0;
	fd = open(argv, O_RDONLY);
	if (argc != 2)
		return (NULL);
	else
	{
		while (read(fd, &buff, 1) > 0)
		{
			res[i] = buff;
			i++;
		}
	}
	close(fd);
	res[i] = '\0';
	return (res);
}

int		connection(char *map)
{
	int touch;
	int i;

	i = 0;
	touch = 0;
	while (map[i])
	{
		if (map[i] == '#')
		{
			if ((i + 1) < 20 && map[i + 1] == '#')
				touch++;
			if ((i - 1) < 20 && map[i - 1] == '#')
				touch++;
			if ((i - 5) < 20 && map[i + 5] == '#')
				touch++;
			if ((i + 1) < 20 && map[i - 5] == '#')
				touch++;
		}
		i++;
	}
	if (touch == 8 || touch == 6)
		return (1);
	return (0);
}

size_t	check(char *s)
{
	size_t	i;
	size_t	a;
	size_t	flag;

	a = 0;
	flag = 0;
	if (ft_strlen(s) < 20 || ft_strlen(s) % 21 == 0)
		return (0);
	while (a < ft_strlen(s))
	{
		flag = a % 21;
		i = (flag == 0 ? 1 : i + 1);
		if ((i % 21) == 0 && s[a] != '\n')
			return (0);
		if (flag != 0 && i % 5 == 0 && s[a] != '\n')
			return (0);
		if (s[a] != '\n' && s[a] != '#' && s[a] != '.')
			return (0);
		a++;
	}
	return (1);
}

int		ft_validate(int argc, char **argv, char **content, char ***split)
{
	int			a;

	if (argc != 2)
	{
		ft_putstr("usage: fillit input_file\n");
		return (1);
	}
	if ((*content = map_read(argc, argv[1])) == NULL || !check(*content))
	{
		ft_putstr("error\n");
		return (0);
	}
	*split = ft_strsplit1(*content);
	a = -1;
	while ((*split)[++a])
		if (!connection((*split)[a]))
		{
			ft_putstr("error\n");
			return (0);
		}
	return (1);
}
