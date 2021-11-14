NAME			= minishell

FLAGS			= -Wall -Wextra -Werror -g -fsanitize=address
OPT				= -O3 -flto -Ofast -ffast-math -march=native
LIBFT			= -L libft -lft

OBJS_DIR		= objects
INCLUDES		= includes
LIBFT_PATH		= libft

SRCS			= \
main.c create_env.c \
$(addprefix parsing/, parse_cmd.c get_command.c \
check_nb_cmd.c check_line_validity.c check_sp.c input_output.c  create_mask.c \
get_command_tools.c input_output_utils.c parse_cmd_utils.c parse_env.c) \
$(addprefix execution/, execution.c heredoc.c parse_env_cmd.c execute_builtin.c \
execution_utils.c heredoc_utils.c) \
$(addprefix builtin/, echo.c env.c exit.c export.c unset.c pwd.c cd.c) \
$(addprefix tools/, tools.c) \

HEADERS			= \
minishell.h mask.h \


FILES			= sources
FOLDERS			= objects parsing execution builtin tools
OBJS			= $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))

READLINE_L		= -ltermcap -lreadline -L /Users/$(USER)/.brew/opt/readline/lib
READLINE_I		= -I/Users/$(USER)/.brew/opt/readline/include

all:				libs $(NAME)

libs:
						@make -C ./libft

$(NAME):			$(OBJS)
						@gcc $(FLAGS) $^ -o $@ $(LIBFT_PATH)/libft.a $(READLINE_L)
						@printf "\033[2K\r$(BLUE)$(NAME)$(RESET)$(BLUE): $(GREEN)Compiled [√]$(RESET)$(NO_COLOR)\n"

$(OBJS_DIR)/%.o:	$(FILES)/%.c $(addprefix $(INCLUDES)/, $(HEADERS)) $(LIBFT_PATH)/libft.a
# @mkdir -p $(OBJS_DIR)
						@mkdir -p $(addprefix $(OBJS_DIR)/, $(FOLDERS))
						@gcc $(FLAGS) $(READLINE_I) -I $(INCLUDES) -I $(LIBFT_PATH)/$(INCLUDES) -c $< -o $@
						@printf "\033[2K\r$(BLUE)$(NAME)$(RESET)$(BLUE): $(PURPLE)$<$(RESET)$(NO_COLOR)"

clean:
						@rm -f $(OBJS)
# @rm -rf $(OBJS_DIR)
						@rm -rf $(addprefix ./, $(FOLDERS))
						@make -C $(LIBFT_PATH) clean

fclean:				clean
						@rm -f $(NAME)
						@make -C $(LIBFT_PATH) fclean

re:					fclean all

.PHONY:				all clean fclean re

BLACK			=	\033[0;30m
RED				=	\033[0;31m
GREEN			=	\033[0;32m
ORANGE			=	\033[0;33m
BLUE			=	\033[0;34m
PURPLE			=	\033[0;35m
CYAN			=	\033[0;36m
LIGHT_GRAY		=	\033[0;37m
DARK_GRAY		=	\033[1;30m
LIGHT_RED		=	\033[1;31m
LIGHT_GREEN		=	\033[1;32m
YELLOW			=	\033[1;33m
LIGHT_BLUE		=	\033[1;34m
LIGHT_PURPLE	=	\033[1;35m
LIGHT_CYAN		=	\033[1;36m
WHITE			=	\033[1;37m
NO_COLOR		=	\033[0m
