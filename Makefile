# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: anonymous <anonymous@student.codam.nl>       +#+                      #
#                                                    +#+                       #
#    Created: 2022/10/14 18:27:31 by anonymous     #+#    #+#                  #
#    Updated: 2022/11/08 16:10:04 by faru          ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME := libftprintf.a
DIR_LIB := include
BASE_SRCS := ft_printf.c \
			printer.c \
			utils.c
BASE_OBJS := $(BASE_SRCS:.c=.o)
BONUS_SRCS := $(BASE_SRCS:.c=_bonus.c)
BONUS_OBJS := $(BONUS_SRCS:.c=.o)
CC  := gcc
CFLAGS  := -Wall -Wextra -Werror
LFLAGS  := -rcs
IFLAGS := -I $(DIR_LIB)
HEADER  := $(DIR_LIB)/ft_printf.h
HEADER_BONUS  := $(DIR_LIB)/ft_printf_bonus.h

all: $(NAME)

$(NAME): $(BASE_OBJS) 
	ar $(LFLAGS) $@ $^

$(BASE_OBJS): $(BASE_SRCS) $(HEADER)
	$(CC) $(CFLAGS) $(IFLAGS) -c $(BASE_SRCS)

clean:
	-rm -f $(BASE_OBJS) $(BONUS_OBJS)

fclean: clean
	-rm -f $(NAME)
	
re: fclean all

bonus: $(BONUS_OBJS) 
	ar $(LFLAGS) $(NAME) $^

$(BONUS_OBJS): $(BONUS_SRCS) $(HEADER_BONUS)
	$(CC) $(CFLAGS) $(IFLAGS) -c $(BONUS_SRCS)

.PHONY: all clean fclean re bonus
