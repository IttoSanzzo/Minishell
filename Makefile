# **************************************************************************** #
#									       #
#							  :::	   ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#						      +:+ +:+	      +:+      #
#    By: marcosv2 <marcosv2@student.42.rio>	    +#+  +:+	   +#+	       #
#						  +#+#+#+#+#+	+#+	       #
#    Created: 2023/11/26 19:20:16 by marcosv2	       #+#    #+#	       #
#    Updated: 2024/01/17 22:31:24 by marcosv2         ###   ########.fr        #
#									       #
# **************************************************************************** #

# Comamad Miscs

NAME	= minishell
LIBFT	= libft
MAKE	= make
C_COMP	= cc
C_FLAG	= -Wall -Werror -Wextra
C_RDLN	= -lreadline
C_REMO	= rm -rf
C_PUTS	= printf

# Dirs

D_HDRS	= -I ./includes/
D_LBFT	= ./libft/
D_SRCS	= ./srcs/
D_OBJS	= objs/

# Sources & Objects

N_MAIN	= main.c		\
	  ms_builtin_cd.c	\
	  ms_builtin_echo.c	\
	  ms_builtin_env.c	\
	  ms_builtin_exit.c	\
	  ms_builtin_export.c	\
	  ms_builtin_pwd.c	\
	  ms_builtin_unset.c	\
	  ms_builtins_switch.c	\
	  ms_check_tokens.c	\
	  ms_exec_vex.c		\
	  ms_expand.c		\
	  ms_fd_changers.c	\
	  ms_format_line.c	\
	  ms_found_hdoc.c	\
	  ms_gen_vex.c		\
	  ms_gets.c		\
	  ms_parse.c		\
	  ms_prompt.c		\
	  ms_readline.c		\
	  ms_redirects.c	\
	  ms_redirects_finish.c	\
	  ms_split.c		\
	  ms_utils.c		\
	  ms_vex_finish.c	\
	  signal.c

F_SRCS	= $(addprefix $(D_SRCS)/$(N_MAIN))
N_OBJS	= $(N_MAIN:.c=.o)
F_OBJS	= $(addprefix $(D_OBJS), $(N_OBJS))

# Libft

N_LBFT	= libft.a
F_LBFT	= $(addprefix $(D_LBFT), $(N_LBFT))

# Colors
P_WHITE	= \033[0m
P_LBLUE = \033[38;5;32m
P_DBLUE = \033[38;5;21m
P_PRPLE	= \033[38;5;93m
P_NCYAN	= \033[38;5;37m
P_MAGEN = \033[38;5;99m
P_GREEN	= \033[38;5;40m
P_LGREN	= \033[38;5;42m
P_NWINE = \033[38;5;88m

# Mandatory Rules

all		: $(NAME) 

$(NAME)		: $(F_LBFT) $(D_OBJS) $(F_OBJS)
	@$(C_PUTS) "\n\t$(P_NCYAN)Finishing binary..: $(P_LBLUE)$(NAME)$(P_WHITE)\n"
	@$(C_COMP) $(C_FLAG) -o $@ $(F_OBJS) $(F_LBFT) $(C_RDLN)
	@$(C_PUTS) "$(P_GREEN)Done!$(P_WHITE)\n"

$(D_OBJS)%.o	: $(D_SRCS)/%.c
	@$(C_PUTS) "\t$(P_PRPLE)Generating $(NAME)..: %-33.33s\r $(P_WHITE)" $@
	@$(C_COMP) $(C_FLAG) $(D_HDRS) -c $< -o $@ $(C_RDLN)

$(D_OBJS)	:
	@$(C_PUTS) "$(P_LGREN)Starting $(NAME) compilation...$(P_WHITE)"
	@$(C_PUTS) "\n\t$(P_MAGEN)Creating $(NAME) objects directory...$(P_WHITE)\n"
	@mkdir $(D_OBJS)

$(F_LBFT)	:
	@clear
	@$(MAKE) --no-print-directory -C $(D_LBFT)

clean		:
	@$(MAKE) clean --no-print-directory -C $(D_LBFT)
	@$(C_PUTS) "$(P_NWINE)Cleaning $(NAME) objects...$(P_WHITE)\n"
	@${C_REMO} $(D_OBJS)

fclean		:
	@$(MAKE) fclean --no-print-directory -C $(D_LBFT)
	@$(C_PUTS) "$(P_NWINE)Cleaning $(NAME) objects...$(P_WHITE)\n"
	@${C_REMO} $(D_OBJS)
	@$(C_PUTS) "$(P_NWINE)Deleting $(NAME)...$(P_WHITE)\n"
	@${C_REMO} $(NAME)

re		: fclean all

# Test

val		:
	@valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)

# Phony

.PHONY: all clean fclean re val
