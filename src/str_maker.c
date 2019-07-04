/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_maker.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lballiot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 15:54:37 by lballiot          #+#    #+#             */
/*   Updated: 2018/01/30 11:42:43 by lballiot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

/*
** function that find the square root to use to find the smallest square
*/

size_t	ft_sqrt_tetra(size_t nb)
{
	size_t rc;
	size_t nb_cpy;

	nb_cpy = nb;
	rc = 1;
	while (rc <= nb_cpy)
	{
		if (rc * rc == nb_cpy)
			return (rc);
		rc++;
		if (rc == nb_cpy)
		{
			rc = 1;
			nb_cpy = nb_cpy + 1;
		}
	}
	return (0);
}

/*
** function that create and fill the final struct
*/

t_str	*ft_str_struct_maker(size_t sq, size_t i)
{
	t_str	*map;
	size_t	x;
	size_t	y;

	x = -1;
	if (!(map = (t_str*)malloc(sizeof(t_str))))
		return (NULL);
	map->sq = sq;
	map->i = i;
	if (!(map->str = (char**)malloc(sizeof(char*) * (sq))))
		return (NULL);
	map->str[sq] = NULL;
	while (++x < sq)
	{
		map->str[x] = ft_strnew(sq + 1);
		y = 0;
		while (y < sq)
			map->str[x][y++] = '.';
		map->str[x][y] = '\n';
	}
	return (map);
}
