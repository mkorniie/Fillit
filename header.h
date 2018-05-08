/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 16:50:20 by mkorniie          #+#    #+#             */
/*   Updated: 2017/12/25 16:52:16 by mkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# define X_POS(x) (*fig)[x][0]
# define Y_POS(x) (*fig)[x][1]
# define HEIGHT(x) (*fig)[x][2]

# include <fcntl.h>

int		ft_recurs(int (*map)[], int *n, char ***fig);
void	ft_dsply(char ***fig, int n);
void	ft_free(int *i, int *s, int *pos, int (*res)[]);
size_t	smb_nbr(int argc, char *argv);
size_t	t_nbr(char	*s);
char	**ft_strsplit1(char *s);
char	*map_read(int argc, char *argv);
int		ft_validate(int argc, char **argv, char **content, char ***split);
char	*cut_chunk(char *s);
int		columns(char *str);
int		raw_check(char *s);
void	ft_freearr(char **split);

#endif
