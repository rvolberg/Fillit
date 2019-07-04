#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rvolberg <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/07 11:00:28 by rvolberg          #+#    #+#              #
#    Updated: 2018/01/24 13:47:45 by rvolberg         ###   ########.fr        #
#                                                                              #
#******************************************************************************#


NAME = fillit

SRC_PATH = ./src/

SRC = ./src/main.c \
	  ./src/ft_check.c \
	  ./src/ft_backtracking.c \
	  ./src/ft_tetra_divider.c \
	  ./src/ft_backtracking_bis.c \
	  ./src/coord_struct.c \
	  ./src/str_maker.c \

OBJ = $(SRC:.c=.o)

INCLUDE = -I ./includes/

CFLAGS = -Wall -Werror -Wextra

CC = gcc

LIBFT_PATH = ./libft/

LIBFT_LINK = -L $(LIBFT_PATH) -lft

LIBFT = ./libft/libft.a

RM = rm -rf

all: $(NAME)

%.c.o :
	 $(CC) $(CFLAGS) -c $(SRC) $(INCLUDE)

$(NAME): $(OBJ)
	 make -C $(LIBFT_PATH)
	 $(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT_LINK)

clean:
	 $(RM) $(OBJ)
	 make -C $(LIBFT_PATH) clean

fclean:  clean
	 $(RM) $(NAME)
	 make -C $(LIBFT_PATH) fclean

re:  fclean all
	 make -C $(LIBFT_PATH) re






