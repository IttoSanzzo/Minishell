# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marcosv2 <marcosv2@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/19 20:09:05 by marcosv2          #+#    #+#              #
#    Updated: 2024/04/19 18:57:21 by marcosv2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Comamad Miscs

NAME	= libft.a
C_COMP	= cc
C_ARRC	= ar -rc
C_FLAG	= -Wall -Werror -Wextra
C_REMO	= rm -rf
C_PUTS	= printf

# Dirs

D_HDRS	= -I ./includes/
D_SRCS	= srcs/
D_OBJS	= objs/

# Sources & Objects

DS_ISX		= ft_isx/
N_ISX		=	ft_isalnum.c	\
				ft_isupp.c		\
				ft_islow.c		\
				ft_isalpha.c	\
				ft_isascii.c	\
				ft_isdigit.c	\
				ft_isprint.c	\
				ft_cquotesn.c	\
				ft_cquotes.c	\
				ft_squotesbl.c	\
				ft_squotes.c	\
				ft_cend.c
F_SRCS	+= $(addprefix $(D_SRCS)$(DS_ISX), $(N_ISX))

DS_TOX		= ft_tox/
N_TOX		=	ft_ttos.c		\
				ft_cltos.c		\
				ft_stocl.c		\
				ft_itoa.c		\
				ft_atoi.c		\
				ft_tolower.c	\
				ft_toupper.c	\
				ft_ftos.c		\
				ft_ftot.c
F_SRCS	+= $(addprefix $(D_SRCS)$(DS_TOX), $(N_TOX))

DS_MEM		= ft_mem/
N_MEM		=	ft_calloc.c		\
				ft_bzero.c		\
				ft_memchr.c		\
				ft_memcmp.c		\
				ft_memcpy.c		\
				ft_memdel.c		\
				ft_memmove.c	\
				ft_memset.c		\
				ft_free.c		\
				ft_nfree.c		\
				ft_nfreestr.c	\
				ft_nfreetab.c	\
				ft_nfreeclst.c	\
				ft_gptr.c		\
				ft_gint.c		\
				ft_nfreeitab.c
F_SRCS	+= $(addprefix $(D_SRCS)$(DS_MEM), $(N_MEM))

DS_PUT		= ft_put/
N_PUT		=	ft_putchar.c		\
				ft_putchar_fd.c		\
				ft_putstr.c			\
				ft_putstr_fd.c		\
				ft_putendl.c		\
				ft_putendl_fd.c		\
				ft_putnbr.c			\
				ft_putnbr_fd.c		\
				ft_puttab.c			\
				ft_putclstval.c		\
				ft_putclstpos.c		\
				ft_putnclst.c		\
				ft_putclst.c		\
				ft_putclst_xfory.c	\
				ft_putitab.c
F_SRCS	+= $(addprefix $(D_SRCS)$(DS_PUT), $(N_PUT))

DS_STR		= ft_str/
N_STR		=	ft_strlen.c			\
				ft_freejoin.c		\
				ft_prejoin.c		\
				ft_sujoin.c			\
				ft_split.c			\
				ft_splitq.c			\
				ft_strchr.c			\
				ft_strdup.c			\
				ft_striteri.c		\
				ft_strjoin.c		\
				ft_strlcat.c		\
				ft_strlcpy.c		\
				ft_strcpy.c			\
				ft_strlen.c			\
				ft_strmapi.c		\
				ft_strncmp.c		\
				ft_strnstr.c		\
				ft_strrchr.c		\
				ft_strrep.c			\
				ft_strdrep.c		\
				ft_strtrim.c		\
				ft_substr.c			\
				ft_strchp.c			\
				ft_strtrim_xtoy.c	\
				ft_strchrep.c		\
				ft_strchrem.c
F_SRCS	+= $(addprefix $(D_SRCS)$(DS_STR), $(N_STR))

DS_LST		= ft_lst/
N_LST		=	ft_lstadd_end.c	\
				ft_lstadd_bgn.c	\
				ft_lstfree.c	\
				ft_lstdelone.c	\
				ft_lstiter.c	\
				ft_lstlast.c	\
				ft_lstmap.c		\
				ft_lstnew.c		\
				ft_lstlen.c		\
				ft_lstdel.c
F_SRCS	+= $(addprefix $(D_SRCS)$(DS_LST), $(N_LST))

DS_CLST		= ft_clst/
N_CLST		=	ft_clstnew.c		\
				ft_freeclst.c		\
				ft_clstlen.c		\
				ft_clstpos.c		\
				ft_clstnval.c		\
				ft_clstadd_bgn.c	\
				ft_clstadd_end.c	\
				ft_clstadd_n.c		\
				ft_clstrem_bgn.c	\
				ft_clstrem_end.c	\
				ft_clstrem_n.c
F_SRCS	+= $(addprefix $(D_SRCS)$(DS_CLST), $(N_CLST))

DS_STRMAN	= ft_strman/
N_STRMAN	=	ft_strnew.c			\
				ft_stradd_bgn.c		\
				ft_stradd_end.c		\
				ft_stradd_n.c		\
				ft_strrem_bgn.c		\
				ft_strrem_end.c		\
				ft_strrem_n.c		\
				ft_strrem_qbl.c		\
				ft_strins_n.c		\
				ft_strrem_xtoy.c
F_SRCS	+= $(addprefix $(D_SRCS)$(DS_STRMAN), $(N_STRMAN))

DS_TAB		= ft_tab/
N_TAB		=	ft_freetab.c		\
				ft_tabdup.c			\
				ft_tablen.c			\
				ft_tabadd_bgn.c		\
				ft_tabadd_end.c		\
				ft_tabadd_n.c		\
				ft_tabrem_bgn.c		\
				ft_tabrem_end.c		\
				ft_tabrem_n.c		\
				ft_tabrem_qbl.c		\
				ft_tabsmove.c		\
				ft_tabchrep.c		\
				ft_tabchrem.c
F_SRCS	+= $(addprefix $(D_SRCS)$(DS_TAB), $(N_TAB))

DS_ANSI		= ft_ansi/
N_ANSI		=	ft_ansi_sc.c		\
				ft_ansi_lc.c		\
				ft_ansi_clear.c		\
				ft_ansi_resetl.c	\
				ft_ansi_dfd.c		\
				ft_ansi_drl.c		\
				ft_ansi_drd.c		\
				ft_ansi_getcp.c		\
				ft_ansi_go.c
F_SRCS	+= $(addprefix $(D_SRCS)$(DS_ANSI), $(N_ANSI))

DS_UTILS	= ft_utils/
N_UTILS		=	ft_stdout_off.c		\
				ft_stdout_on.c		\
				ft_getarg.c			\
				ft_getarg_p.c		\
				ft_getrstr_p.c		\
				ft_getstr_p.c		\
				ft_ungetchar.c		\
				ft_getchar_unb.c	\
				ft_getchar.c		\
				ft_trash_stdin.c	\
				ft_newfile.c		\
				ft_close.c			\
				ft_getcwd.c			\
				ft_endl.c			\
				ft_check_file.c		\
				ft_check_ext.c
F_SRCS	+= $(addprefix $(D_SRCS)$(DS_UTILS), $(N_UTILS))

DS_PRINTF	= ft_printf/
N_PRINTF	=	ft_printf.c			\
				ft_printc.c			\
				ft_ftypes.c			\
				ft_printpercent.c	\
				ft_printchar.c		\
				ft_printstr.c		\
				ft_printnbr.c		\
				ft_printunsigned.c	\
				ft_printhex.c		\
				ft_printpointer.c	\
				ft_printf_utils.c
F_SRCS	+= $(addprefix $(D_SRCS)$(DS_PRINTF), $(N_PRINTF))

DS_GNL		= ft_gnl/
N_GNL		= get_next_line.c
F_SRCS	+= $(addprefix $(D_SRCS)$(DS_GNL), $(N_GNL))

DS_READLINE	= ft_readline/
N_READLINE	=	ft_sreadline.c			\
				ft_readline.c			\
				ft_rlconfig.c			\
				ft_add_history.c		\
				ft_rl_clear_history.c	\
				rl_checks.c				\
				rl_save_cp.c			\
				rl_moviments.c			\
				rl_go.c					\
				rl_specials.c			\
				rl_addchar.c			\
				rl_utils.c
F_SRCS	+= $(addprefix $(D_SRCS)$(DS_READLINE), $(N_READLINE))

# Objects Finalization

N_OBJS	=	$(N_ISX:.c=.o)		\
			$(N_TOX:.c=.o)		\
			$(N_MEM:.c=.o)		\
			$(N_PUT:.c=.o)		\
			$(N_STR:.c=.o)		\
			$(N_STRMAN:.c=.o)	\
			$(N_LST:.c=.o)		\
			$(N_CLST:.c=.o)		\
			$(N_TAB:.c=.o)		\
			$(N_ANSI:.c=.o)		\
			$(N_UTILS:.c=.o)	\
			$(N_PRINTF:.c=.o)	\
			$(N_GNL:.c=.o)		\
			$(N_READLINE:.c=.o)
F_OBJS	= $(addprefix $(D_OBJS), $(N_OBJS))

# Colors
P_WHITE = \033[0m
P_LBLUE = \033[38;5;32m
P_PRPLE = \033[38;5;93m
P_DBLUE = \033[38;5;21m
P_NCYAN = \033[38;5;37m
P_GREEN = \033[38;5;40m
P_MAGEN	= \033[38;5;99m
P_NWINE	= \033[38;5;88m
P_LGREN = \033[38;5;42m

# Mandatory Rules

all		: $(NAME)

$(D_OBJS)%.o	: $(D_SRCS)*/%.c
	@$(C_PUTS) "\t$(P_PRPLE)Generating $(NAME)..: %-33.33s\r $(P_WHITE)" $@
	@$(C_COMP) $(C_FLAG) -c $< -o $@ $(D_HDRS)

$(D_OBJS)	:
	@$(C_PUTS) "$(P_LGREN)Starting $(NAME) compilation...$(P_WHITE)\n"
	@$(C_PUTS) "\t$(P_MAGEN)Creating $(NAME) objects directory...$(P_WHITE)\n"
	@mkdir $(D_OBJS)

$(NAME)		:  $(D_OBJS) $(F_OBJS)
	@$(C_PUTS) "\n\t$(P_NCYAN)Finishing $(NAME)..: $(P_LBLUE)$(NAME)$(P_WHITE)\n"
	@$(C_ARRC) $(NAME) $(F_OBJS)
	@$(C_PUTS) "$(P_GREEN)Done!$(P_WHITE)\n"

clean		:
	@$(C_PUTS) "$(P_NWINE)Cleaning $(NAME) objects...$(P_WHITE)\n"
	@$(C_REMO) $(D_OBJS)

fclean		: clean
	@$(C_PUTS) "$(P_NWINE)Deleting $(NAME)...$(P_WHITE)\n"
	@${C_REMO} $(NAME)
	@${C_REMO} COMPILADO.out

re		: fclean all

# Phony

.PHONY: all clean fclean re
