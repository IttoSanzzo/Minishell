/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ms_redirects_finish.c                              :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2024/01/17 14:54:51 by marcosv2	       #+#    #+#	      */
/*   Updated: 2024/01/17 18:36:11 by marcosv2         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "minishell.h"

static void	ms_pipe(t_mini *ms)
{
	if (pipe(ms->pip) == -1)
		ft_putendl_fd(PIPE_ERR, STDERR);
	else
		ms_dup2c(ms->pip[1], STDOUT);
}

static void	ms_intype(t_vars *vex)
{
	int	fd[2];

	ms_reset_fds(STDIN);
	if (vex->intp == 1)
	{
		if (pipe(fd) == -1)
		{
			ft_putendl_fd(PIPE_ERR, STDERR);
		}
		ft_putstr_fd(vex->hdoc, fd[1]);
		close(fd[1]);
		ms_dup2c(fd[0], STDIN);
		return ;
	}
	fd[0] = open(vex->infile, O_RDONLY);
	if (fd[0] == -1)
	{
		ft_putstr_fd(INFILE_ERR_A, STDERR);
		ft_putstr_fd(vex->infile, STDERR);
		ft_putendl_fd(INFILE_ERR_B, STDERR);
		ft_ungetchar(0);
		return ;
	}
	ms_dup2c(fd[0], STDIN);
}

static void	ms_outype(t_vars *vex)
{
	int		fd;
	char	c[1];

	ms_reset_fds(STDOUT);
	if (vex->outp == 2)
		unlink(vex->oufile);
	fd = open(vex->oufile, O_RDWR | O_CREAT, 0777);
	if (fd == -1)
	{
		ft_putstr_fd(OUFILE_ERR_A, STDERR);
		ft_putstr_fd(OUFILE_ERR_B, STDERR);
		ft_putstr_fd(vex->oufile, STDERR);
		ft_putendl_fd(OUFILE_ERR_C, STDERR);
		return ;
	}
	while (read(fd, c, 1) != 0)
		continue ;
	ms_dup2c(fd, STDOUT);
}

void	ms_redirects_finish(t_mini *ms, t_vars *vex, t_vars *avex)
{
	ms_reset_fds(2);
	if (avex && avex->tp == 0 && avex->outp == 0)
		ms_dup2c(ms->pip[0], STDIN);
	else if (avex && avex->tp == 0 && avex->outp != 0)
		ft_ungetchar(0);
	if (vex->tp == 0 && vex->outp == 0)
		ms_pipe(ms);
	if (vex->intp != 0)
		ms_intype(vex);
	else if (vex->outp != 0)
		ms_outype(vex);
}
