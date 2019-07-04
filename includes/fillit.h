/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvolberg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 10:44:05 by rvolberg          #+#    #+#             */
/*   Updated: 2018/01/30 11:05:02 by lballiot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "../libft/libft.h"
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct		s_tetra
{
	int				*x;
	int				*y;
	char			c;
	int				nb;
	struct s_tetra	*next;
}					t_tetra;

typedef struct		s_ret
{
	size_t			i;
	size_t			sq;
	char			**str;
	struct s_ret	*next;
}					t_str;

typedef struct		s_check
{
	int				i;
	size_t			sharp;
	size_t			point;
	size_t			c;
	size_t			backn;
	size_t			bonds;
	int				t;
	size_t			vertical;
	size_t			horizontal;
	int				a[4];
	int				b[4];
}					t_struct;

t_str				*ft_str_struct_maker(size_t sq, size_t i);
size_t				ft_sqrt_tetra(size_t nb);
t_tetra				*ft_initial_move_tetra(t_tetra *list);
t_tetra				*ft_lst_tetra(int *a, int *b, char c, int nb);
t_tetra				*ft_tetra_coord(char *tab, t_tetra *list, char c, int nb);
char				ft_chartetra(char *tetra);
void				ft_ltetradd(t_tetra **list, t_tetra *new);
t_tetra				*ft_lstrev(t_tetra *list);
t_tetra				*ft_list(char **tetra, size_t i);
void				ft_backtracking(char **tab_tetra, size_t i);
void				ft_remove(char c, t_str *map);
void				ft_place(char c, t_str *map, t_tetra *list, int *tab);
int					ft_check_place(t_tetra *list, t_str *map, int x, int y);
int					ft_tetra_in_str(t_tetra *list, t_str *map);
int					ft_check(char *str, int tetra);
char				**ft_tetra_divider(char *str, size_t i);
int					ft_check_number_arg(int ac);
int					ft_open(char **av);
void				ft_read(int o_fd, char **tab_tetra);

#endif
