/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2024/01/08 02:11:47 by marcosv2	       #+#    #+#	      */
/*   Updated: 2024/01/17 22:31:47 by marcosv2         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

// Includes
# include "./libft/includes/libft.h"
# include "ms_macros.h"
# include "ms_structs.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <dirent.h>
# include <signal.h>
# include <sys/wait.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>

//// Functions per Archive
// main.c
int		main(int argc, char **argv, char **ep);
// signals.c
void	ms_sig_init(t_mini *ms);
void	ms_sigint(int signum);
void	ms_sigquit(int signum);

/// Builtins
int		ms_builtins_switch(t_vars *vex);
int		ms_builtin_echo(t_vars *vex);
int		ms_builtin_cd(t_vars *vex);
int		ms_builtin_pwd(t_vars *vex);
int		ms_builtin_export(t_vars *vex);
int		ms_builtin_unset(t_vars *vex);
int		ms_builtin_env(t_vars *vex);
int		ms_builtin_exit(t_vars *vex);
int		ms_export_core(t_mini *ms, char *arg);
void	ms_endlexit(void);
void	ms_exec_exit(int ret);
void	ms_free_cmd(t_mini *ms);
void	ms_free_vex(t_mini *ms);

/// ms_parse.c
void	ms_parse(t_mini *ms);
int		ms_check_tokens(t_mini *ms);

// ms_format_line.c
void	ms_format_line(t_mini *ms);

// ms_gen_vex.c
void	ms_gen_vex(t_mini *ms);

// ms_redirects
int		ms_redirects(t_mini *ms);
void	ms_found_hdoc(t_mini *ms, t_vars *vex, int i);

// ms_vex_finish
void	ms_vex_finish(t_mini *ms, t_vars *vex);

// ms_redirects_finish.c
void	ms_redirects_finish(t_mini *ms, t_vars *vex, t_vars *avex);

// ms_expand.c
void	ms_expand(t_vars *vex);

// ms_exec_vex.c
void	ms_exec_vex(t_mini *ms, t_vars *vex);

// ms_gets.c
int		ms_ret(int ret);
char	*ms_home(void);
char	*ms_pwd(void);

// ms_fd_changers.c
void	ms_dup2(int new, int target);
void	ms_dup2c(int new, int target);
void	ms_reset_fds(int fd);

/// ms_utils
int		ms_is_token(char *cmd);
t_mini	*ms_get_mini(t_mini *ms);
void	ms_waitret(int pid, int *status, int options);
void	ms_freeall(void);

/// ms_prompt.c
void	ms_gen_prompt(t_mini *ms);

/// ms_readline.c
char	*ms_readline(char *prompt);
void	ms_add_history(char *line);
void	ms_rl_clear_history(void);

#endif
