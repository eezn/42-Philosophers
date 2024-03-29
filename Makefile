# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jin-lee <jin-lee@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/05 20:06:42 by jin-lee           #+#    #+#              #
#    Updated: 2021/12/21 17:16:50 by jin-lee          ###   ########.fr        #
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
			  ./srcs/atoi \
			  ./srcs/utils \

SRCS		= ./srcs/main.c \
			  ./srcs/check_args.c \
			  ./srcs/init_data.c \
			  ./srcs/philosophers.c \
			  ./srcs/actions.c \
			  ./srcs/get_interval.c \
			  ./srcs/check_status.c \
			  ./srcs/print_status.c \
			  \
			  ./srcs/atoi/ft_atoi.c \
			  ./srcs/atoi/ft_isdigit.c \
			  ./srcs/atoi/ft_isspace.c \
			  ./srcs/atoi/ft_strlen.c \
			  \
			  ./srcs/utils/pass.c \
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
