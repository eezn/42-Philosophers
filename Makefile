# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jin-lee <jin-lee@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/05 20:06:42 by jin-lee           #+#    #+#              #
#    Updated: 2021/12/17 11:17:59 by jin-lee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= philo

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra

ifeq ($(DEBUG),true)
	CDEBUG = -g
endif

INCS_DIR	= ./includes
SRCS_DIR	= ./srcs \
			  ./srcs/mini_libft \
			  ./srcs/utils

SRCS		= ./srcs/main.c \
			  ./srcs/check_args.c \
			  ./srcs/init_data.c \
			  \
			  ./srcs/mini_libft/ft_atoi.c \
			  ./srcs/mini_libft/ft_isdigit.c \
			  ./srcs/mini_libft/ft_isspace.c \
			  ./srcs/mini_libft/ft_strlen.c \
			  \
			  ./srcs/utils/tools.c \
			  ./srcs/utils/print_error.c

OBJS_DIR	= ./objects
OBJS		= $(addprefix $(OBJS_DIR)/, $(notdir $(SRCS:.c=.o)))
vpath %.c $(SRCS_DIR)

RM			= rm -f


all: $(NAME)


# philo
$(NAME): $(OBJS)
	@$(CC) $(CDEBUG) $^ -o $@
	@echo "\033[32m"$(NAME) built successfully."\033[0m"

$(OBJS_DIR)/%.o: %.c | $(OBJS_DIR)
	@$(CC) $(CDEBUG) $(CFLAGS) -pthread -I $(INCS_DIR) -c $^ -o $@

$(OBJS_DIR):
	@mkdir -p $@


# clean, fclean, re
clean:
	@$(RM) -r $(OBJS_DIR)

fclean: clean
	@$(RM) $(NAME)

re: fclean all


.PHONY: all, $(NAME), clean, fclean, re
