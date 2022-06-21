# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anmande <anmande@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/07 11:41:09 by anmande           #+#    #+#              #
#    Updated: 2022/06/21 16:48:08 by anmande          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT = ./libft/libft.a

NAME = libprintf.a

CC = gcc 

CFLAGS = -Wall -Wextra -Werror

SRC =	ft_printf.c \
		ft_flagx.c \
		ft_flagp.c \
		ft_putnbr_u.c

#BONUS_SRC = 
			
OBJ = ${SRC:.c=.o}

OBJ_BONUS = ${BONUS_SRC:.c=.o}


$(NAME): ${OBJ} $(LIBFT)
#	cp libft/libft.a $(NAME)
	ar -rcs ${NAME} ${OBJ}

$(LIBFT):
	make -C ./libft

all: $(NAME)


bonus: ${OBJ_BONUS}
	ar -rcs ${NAME} ${OBJ_BONUS}

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

clean: 
	/bin/rm -f *.o
	/bin/rm -f */*.o

fclean: clean
	/bin/rm -f $(NAME)
	/bin/rm -f $(LIBFT)

re: fclean all

tclean:
	rm exec

.PHONY: all clean fclean bonus re
