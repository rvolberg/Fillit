/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvolberg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 11:28:40 by rvolberg          #+#    #+#             */
/*   Updated: 2018/01/30 11:06:06 by lballiot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

/*
** function that check the number of input files and if need be, return
** the usage of the program
*/

int			ft_check_number_arg(int ac)
{
	char	*usage;

	usage = "usage:\t ./fillit source_file target_file\n"
		"\t ./fillit source_file ... target_directory";
	if (ac != 2)
	{
		ft_putstr_fd(usage, 2);
		return (0);
	}
	return (1);
}

/*
** function that open the iput file
*/

int			ft_open(char **argv)
{
	int		open_fd;

	open_fd = 0;
	open_fd = open(argv[1], O_RDONLY);
	if (open_fd == -1)
		ft_putstr_fd("open() failed\n", 2);
	return (open_fd);
}

/*
** continuation of the function ft_read
*/

static char	**ft_read2(int tmp, char *str, char **tab, size_t counter)
{
	if (tmp == 0 && str[0] == '\0')
	{
		ft_putstr("error\n");
		exit(EXIT_FAILURE);
	}
	tab = ft_tetra_divider(str, counter);
	if (tab == NULL)
	{
		ft_putstr("error\n");
		exit(EXIT_FAILURE);
	}
	ft_backtracking(tab, counter);
	return (tab);
}

/*
** function that reads the input file and send it to the function
** that changes it to a char**
*/

void		ft_read(int o_fd, char **tab_tetra)
{
	char	*buf;
	char	*str_tetra;
	size_t	counter;
	int		tetra;
	int		tmp;

	tetra = 0;
	counter = 0;
	str_tetra = ft_strnew(21);
	buf = ft_strnew(21);
	tmp = 0;
	while ((tmp = read(o_fd, buf, 21)) > 0)
	{
		tetra += ft_strlen(buf);
		if (ft_check(buf, tetra) == -1)
		{
			ft_putstr("error\n");
			exit(EXIT_FAILURE);
		}
		str_tetra = ft_strjoin(str_tetra, buf);
		buf = ft_strnew(21);
		counter++;
	}
	free(buf);
	ft_read2(tmp, str_tetra, tab_tetra, counter);
}

/*
** main function
*/

int			main(int argc, char **argv)
{
	int		open_fd;
	char	**tab_tetra;

	tab_tetra = NULL;
	if ((ft_check_number_arg(argc)) == 0)
		return (0);
	open_fd = ft_open(argv);
	if (open_fd == -1)
		return (0);
	ft_read(open_fd, tab_tetra);
	if (tab_tetra == NULL)
		return (0);
	if (close(open_fd) == -1)
	{
		ft_putstr_fd("close() failed\n", 2);
		return (0);
	}
	return (0);
}
