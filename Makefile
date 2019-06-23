# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ohelly <ohelly@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/26 19:03:58 by ohelly            #+#    #+#              #
#    Updated: 2019/04/28 17:16:26 by ohelly           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CC = gcc
MAKE = make
FLAGS = -Wall -Wextra -Werror
FRAMEWORKS = -framework OpenGL -framework AppKit
CFILES = \
		srcs/main.c \
		srcs/ft_checkvalid.c \
		srcs/ft_cloose.c \
		srcs/ft_free.c \
		srcs/ft_fullmap.c \
		srcs/ft_get_color.c \
		srcs/ft_hook.c \
		srcs/ft_init.c \
		srcs/ft_initall.c \
		srcs/ft_keys.c \
		srcs/ft_line.c \
		srcs/ft_output.c \
		srcs/ft_readcolor.c \
		srcs/ft_rotate.c \
		srcs/get_next_line.c
OFILES = $(CFILES:%.c=%.o)

LIBINC = libft/includes
LIBPATH = libft/
FT = ft
LFTPATH = $(LIBPATH)
LFT = $(addprefix lib, $(addsuffix .a, $(FT)))
LIBFT = -L$(LFTPATH) -l$(FT)
MKFT = $(MAKE) -C $(LFTPATH)

MLX = mlx
LMLXPATH = minilib/
LMLX = $(addprefix lib, $(addsuffix .a, $(MLX)))
LIBMLX = -L$(LMLXPATH) -l$(MLX)
MKMLX = $(MAKE) -C $(LMLXPATH)

SRC = $(CFILES)
OBJS = $(OFILES)

INC = includes/
INCLUDES = -I$(LIBINC) -I$(LMLXPATH) -I$(INC)
LIB = -lm $(LIBFT) $(LIBMLX)

all: $(NAME)

$(NAME) : $(LFT) $(LMLX) $(OBJS)
		$(CC) -o $(NAME) $(INCLUDES) $(LIB) $(FRAMEWORKS) $(OBJS)

%.o: %.c
		$(CC) $(FLAGS) -o $@ $(INCLUDES) -c $<

$(LFT):
		$(MKFT)

$(LMLX):
		$(MKMLX)

clean:
		$(MKFT) clean
		$(MKMLX) clean
		rm -rf $(OBJS)

fclean: clean
		$(MKFT) fclean
		rm -rf $(NAME)

re: fclean all