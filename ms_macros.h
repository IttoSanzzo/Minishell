/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ms_macros.h                                        :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2024/01/07 01:48:11 by marcosv2	       #+#    #+#	      */
/*   Updated: 2024/01/17 18:47:28 by marcosv2         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#ifndef MS_MACROS_H
# define MS_MACROS_H

// Readline version (0 - Mine ; 1 - Original)
# define READLINE 0

// Messages
# define EXIT_MSS "\033[38;5;43mExiting now...\n\033[0m"
# define CD_ERR_N "minishell: cd: too many arguments"
# define CD_ERR_A "minishell: cd: "
# define CD_ERR_B ": Not a directory\n"
# define CD_ERR_C "minishell: cd: "
# define CD_ERR_D ": No such file or directory\n"
# define XP_ERR_A "minishell: export: \'"
# define XP_ERR_B "\': not a valid identifier\n"
# define TOKEN_ERR_A "minishell: syntax error near unexpected token \'"
# define TOKEN_ERR_B "\'\n"
# define EXEC_C_FAIL "minishell: "
# define EXEC_FAIL_A ": command not found"
# define EXEC_FAIL_B ": No such file or directory"
# define EXEC_FAIL_C ": is a directory"
# define EXEC_FAIL_D ": Permission denied"
# define PIPE_ERR "minishell: pipe: An error has ocurred while opening a pipe!"
# define INFILE_ERR_A "minishell: warning: Path \'"
# define INFILE_ERR_B "\' does not exist"
# define OUFILE_ERR_A "minishell: warning: An error has "
# define OUFILE_ERR_B "ocurred while opening \'"
# define OUFILE_ERR_C "\'"
# define EXPORT_STDMSS "declare -x "

// Prompts
# define DEFAULT_PROMPT "minishell"
# define ERR_SQUO "squotes> "
# define ERR_DQUO "dquotes> "
# define ERR_CEND "opencmd> "
# define HDOC_A "heredoc "
# define HDOC_B "> "
# define HDOC_EOF_A "\nminishell: warning: here-document delimited "
# define HDOC_EOF_B "by end-of-file (wanted `"
# define HDOC_EOF_C "`)\n"

// Intypes
# define IN_HDOC 1
# define IN_FILE 2
# define OUT_AP 1
# define OUT_NP 2

// Misc
# define TOKENS ";|&<>"
# define DTOKENS "&"
# define EXPORT_ERR "\'\" $:/;|&<>"
# define EXP_CHAR "\'\"= $:/;|&<>"

// Rets
# define EXIT_UCMD 127
# define EXIT_IDIR 126

#endif
