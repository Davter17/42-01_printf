# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/20 15:51:55 by mpico-bu          #+#    #+#              #
#    Updated: 2025/01/22 12:50:54 by mpico-bu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS_DIR = src
OBJ_DIR = .obj
INC_DIR = inc

LIBFT_URL = https://github.com/Davter17/42-00_Libft.git
LIBFT_DIR = .deps/libft
LIBFT_INC = $(LIBFT_DIR)/inc
LIBFT_LIB = $(LIBFT_DIR)/libft.a

SRCS = $(SRCS_DIR)/ft_printf.c $(SRCS_DIR)/ft_printf_utils.c $(SRCS_DIR)/ft_printf_utils2.c

OBJS = $(patsubst $(SRCS_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))

CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(INC_DIR) -I$(LIBFT_INC)
AR = ar rcs

all: $(LIBFT_LIB) $(NAME)

$(OBJ_DIR)/%.o: $(SRCS_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@printf "  \033[33m⚙\033[0m  Compiling %d files...\n" $(words $(OBJS))
	@mkdir -p $(OBJ_DIR)

$(LIBFT_LIB):
	@if [ ! -d "$(LIBFT_DIR)" ]; then \
		printf "  \033[33m⚙\033[0m  Cloning libft...\n"; \
		git clone $(LIBFT_URL) $(LIBFT_DIR) > /dev/null 2>&1; \
	fi
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR)

$(NAME): $(OBJS)
	@printf "  \033[32m✓\033[0m Compiled %d files → $(NAME)\n" $(words $(OBJS))
	@cp $(LIBFT_LIB) $(NAME)
	@$(AR) $(NAME) $(OBJS)

clean:
	@printf "  \033[31m✗\033[0m  Removing object files...\n"
	@rm -rf $(OBJ_DIR)

fclean: clean
	@printf "  \033[31m✗\033[0m  Removing $(NAME)...\n"
	@rm -f $(NAME)
	@printf "  \033[31m✗\033[0m  Removing dependencies...\n"
	@rm -rf .deps

re: fclean all

test: all
	@bash test/run_tests.sh

.PHONY: all clean fclean re test
