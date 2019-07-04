/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coord_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvolberg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 13:36:06 by rvolberg          #+#    #+#             */
/*   Updated: 2018/01/30 11:31:16 by lballiot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

/*
** function that changes the coordinate to place them in the upper left corner
*/

t_tetra		*ft_initial_move_tetra(t_tetra *list)
{
	int i;
	int x;
	int y;

	x = list->x[0];
	y = list->y[0];
	i = -1;
	while (++i < 4)
		if (list->x[i] < x)
			x = list->x[i];
	i = -1;
	while (++i < 4)
	{
		list->x[i] = list->x[i] - x;
		list->y[i] = list->y[i] - y;
	}
	return (list);
}

/*
** function that creates and fill a link for
*/

t_tetra		*ft_lst_tetra(int *a, int *b, char c, int nb)
{
	t_tetra	*maillon;
	int		i;

	i = -1;
	if (!(maillon = (t_tetra*)malloc(sizeof(t_tetra))))
		return (NULL);
	if ((a) && (b))
	{
		if (!(maillon->x = (void*)malloc(sizeof(int) * (4))))
			return (NULL);
		if (!(maillon->y = (void*)malloc(sizeof(int) * (4))))
			return (NULL);
		maillon->c = c;
		maillon->nb = nb;
		while (++i <= 3)
		{
			maillon->x[i] = a[i];
			maillon->y[i] = b[i];
		}
	}
	maillon->next = NULL;
	return (maillon);
}

/*
** funtion that find the coordinate of the tetra to send it to t_tetra
*/

t_tetra		*ft_tetra_coord(char *tab, t_tetra *list, char c, int nb)
{
	t_struct l;

	l.t = -1;
	l.vertical = 0;
	l.horizontal = 0;
	l.i = -1;
	while (tab[++l.i] != '\0')
	{
		if (tab[l.i] == '\n')
		{
			l.horizontal++;
			l.i++;
			l.vertical = 0;
		}
		if ((tab[l.i] >= 'A' && tab[l.i] <= 'Z') && (++l.t < 4))
		{
			l.a[l.t] = l.vertical;
			l.b[l.t] = l.horizontal;
		}
		l.vertical++;
	}
	list = ft_lst_tetra(l.a, l.b, c, nb);
	list = ft_initial_move_tetra(list);
	return (list);
}
