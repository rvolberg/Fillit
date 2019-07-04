/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lballiot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 10:56:52 by lballiot          #+#    #+#             */
/*   Updated: 2018/01/30 11:38:38 by lballiot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

/*
** function that count the number of link between #, the #,'\n', '.'
** and the total number of char
*/

static t_struct		ft_check2(t_struct l, char *str)
{
	if (str[l.i] == '#')
		l.sharp++;
	if (str[l.i] == '.')
		l.point++;
	if (str[l.i] == '\n' && str[l.i + 1] != '\n')
		l.backn++;
	if (str[l.i] != '\n' && str[l.i] != '\0')
		l.c++;
	if (str[l.i] == '#' && str[l.i - 5] == '#')
		l.bonds++;
	if (str[l.i] == '#' && str[l.i - 1] == '#')
		l.bonds++;
	if (str[l.i] == '#' && str[l.i + 1] == '#')
		l.bonds++;
	if (str[l.i] == '#' && str[l.i + 5] == '#')
		l.bonds++;
	return (l);
}

/*
** function that checks the numbers found to see if the tetra is valid
*/

static t_struct		ft_check3(t_struct l, char *str)
{
	if (str[l.i] != '.' && str[l.i] != '#' && str[l.i] != '\n'
			&& str[l.i] != '\0')
		l.t = -1;
	if (str[l.i] == '\n' && str[l.i + 1] != '\0')
	{
		if (l.c != 4)
			l.t = -1;
		l.c = 0;
	}
	if ((str[l.i] == '\n' && str[l.i - 1] == '\n') || (str[l.i + 1] == '\0'
				&& str[l.i] == '\n'))
	{
		if (l.sharp != 4 || l.point != 12 || l.backn != 4 || l.bonds <= 4)
			l.t = -1;
		l.sharp = 0;
		l.point = 0;
		l.backn = 0;
	}
	return (l);
}

/*
** main function to check the tetraminos, if (-1) : error
*/

int					ft_check(char *str, int tetra)
{
	t_struct l;

	l.point = 0;
	l.backn = 0;
	l.bonds = 0;
	l.i = -1;
	l.sharp = 0;
	l.c = 0;
	l.t = 0;
	if (!str)
		return (-1);
	if (tetra > 545 || tetra < 20)
		return (-1);
	while (str[++l.i])
	{
		l = ft_check2(l, str);
		l = ft_check3(l, str);
		if (l.t == -1)
			return (-1);
	}
	return (0);
}
