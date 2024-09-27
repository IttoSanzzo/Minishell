/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ms_exec_vex.c                                      :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2024/01/11 21:49:26 by marcosv2	       #+#    #+#	      */
/*   Updated: 2024/01/16 12:21:20 by marcosv2         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "minishell.h"

static void	ms_exec_fail(char *cmd, int *ret)
{
	DIR	*dir;
	int	fd;

	fd = open(cmd, O_WRONLY);
	dir = opendir(cmd);
	ft_putstr_fd(EXEC_C_FAIL, STDERR);
	ft_putstr_fd(cmd, STDERR);
	if (ft_strchr(cmd, '/') == NULL)
		ft_putendl_fd(EXEC_FAIL_A, STDERR);
	else if (fd == -1 && dir == NULL)
		ft_putendl_fd(EXEC_FAIL_B, STDERR);
	else if (fd == -1 && dir != NULL)
		ft_putendl_fd(EXEC_FAIL_C, STDERR);
	else if (fd != -1 && dir == NULL)
		ft_putendl_fd(EXEC_FAIL_D, STDERR);
	if (ft_strchr(cmd, '/') == NULL || (fd == -1 && dir == NULL))
		*ret = EXIT_UCMD;
	else
		*ret = EXIT_IDIR;
	if (dir)
		closedir(dir);
	ft_close(fd);
}

static void	ms_try_envpaths(t_vars *vex)
{
	int		i;
	char	**paths;

	i = -1;
	paths = ft_split(ft_getarg(vex->ep, "PATH="), ':');
	if (!paths)
		return ;
	while (paths[++i])
	{
		vex->path = ft_strjoin(paths[i], "/");
		ft_sujoin(&vex->path, vex->cmd);
		execve(vex->path, vex->av, vex->ep);
		ft_nfreestr(&vex->path);
	}
	if (paths)
		ft_nfreetab(&paths);
}

static void	ms_gen_exec_path(t_vars *vex)
{
	if (!ft_strncmp("/", vex->cmd, 1))
		vex->path = ft_strdup(vex->cmd);
	else if (!ft_strncmp("./", vex->cmd, 2))
		vex->path = ft_strjoin(ms_pwd(), (char *)(vex->cmd + 1));
	else if (!ft_strncmp("~/", vex->cmd, 2))
		vex->path = ft_strjoin(ms_home(), (char *)(vex->cmd + 1));
	else
		ms_try_envpaths(vex);
}

void	ms_exec_vex(t_mini *ms, t_vars *vex)
{
	ms->ret = 0;
	ms->sig.pid = fork();
	if (ms->sig.pid == 0)
	{
		ms_gen_exec_path(vex);
		if (vex->path)
			execve(vex->path, vex->av, vex->ep);
		ms_exec_fail(vex->cmd, &ms->ret);
		ms_exec_exit(ms->ret);
	}
	ms_waitret(ms->sig.pid, &ms->ret, 0);
}
