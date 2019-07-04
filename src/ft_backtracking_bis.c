/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backtracking_bis.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvolberg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 13:09:55 by rvolberg          #+#    #+#             */
/*   Updated: 2018/01/30 11:37:15 by lballiot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

/*
** function that removes a tetra in the tab
*/

void	ft_remove(char c, t_str *map)
{
	size_t x;
	size_t y;

	x = -1;
	y = -1;
	while (++y < map->sq)
	{
		while (++x < map->sq)
			if (map->str[y][x] == c)
				map->str[y][x] = '.';
		x = -1;
	}
}

/*
** function that puts a tetra in the tab
*/

void	ft_place(char c, t_str *map, t_tetra *list, int *tab)
{
	int n;
	int i;
	int j;

	n = -1;
	j = 0;
	i = 0;
	while (++n < 4)
	{
		i = tab[0] - list->x[0] + list->x[n];
		j = tab[1] - list->y[0] + list->y[n];
		if (map->str[j][i] == '.')
			map->str[j][i] = c;
	}
}

/*
** function that checks the space for a tetra form a particular x and y
*/

int		ft_check_place(t_tetra *list, t_str *map, int x, int y)
{
	int i;
	int j;
	int c;
	int tab[2];

	c = -1;
	j = 0;
	i = 0;
	tab[0] = x;
	tab[1] = y;
	while (++c < 4)
	{
		i = x - list->x[0] + list->x[c];
		j = y - list->y[0] + list->y[c];
		if ((i < 0) || (j < 0) || (i >= (int)map->sq) || (j >= (int)map->sq))
			return (-1);
		if (map->str[j][i] != '.')
			return (-1);
	}
	ft_place(list->c, map, list, tab);
	return (1);
}

/*
** solving function : check space and next space
*/

int		ft_tetra_in_str(t_tetra *list, t_str *map)
{
	int		x;
	int		y;

	y = -1;
	if (list == NULL)
		return (1);
	while (++y < (int)map->sq)
	{
		x = -1;
		while (++x < (int)map->sq)
			if (ft_check_place(list, map, x, y) == 1)
			{
				if (ft_tetra_in_str(list->next, map) != 1)
				{
					ft_remove(list->c, map);
					ft_remove((list->next)->c, map);
				}
				else
					return (1);
			}
	}
	return (0);
}
