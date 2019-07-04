/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tetra_divider.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvolberg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 11:15:47 by rvolberg          #+#    #+#             */
/*   Updated: 2018/01/30 11:40:56 by lballiot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

/*
** function that changes the '#' (sharp) in Alphabet, in order of arrival
*/

static char		**ft_tetra_is_alpha(char **tab)
{
	int		x;
	size_t	y;
	int		a;

	a = 'A';
	x = -1;
	y = -1;
	while (tab[++y])
	{
		while (tab[y][++x] != '\0')
		{
			if (tab[y][x] == '#')
				tab[y][x] = a;
		}
		x = -1;
		a++;
	}
	return (tab);
}

/*
** function that separate the char* of tetra in char** each with
** only one tetra
*/

char			**ft_tetra_divider(char *str, size_t i)
{
	char	**tab;
	int		ind;
	char	*cpy;
	int		tmp;

	tmp = i - 1;
	ind = 0;
	if (!(tab = (char **)malloc(sizeof(char *) * i + 1)))
		return (NULL);
	tab[i] = NULL;
	while (i-- > 0)
	{
		tab[ind] = ft_strnew(22);
		cpy = ft_strnew(ft_strlen(str));
		cpy = ft_strcpy(cpy, str);
		tab[ind] = ft_strncpy(tab[ind], cpy, 21);
		str = str + 21;
		ind++;
	}
	ind = ft_strlen(tab[tmp]) - 1;
	if (tab[tmp][ind] == '\n' && tab[tmp][ind - 1] == '\n')
		return (NULL);
	tab = ft_tetra_is_alpha(tab);
	return (tab);
}
