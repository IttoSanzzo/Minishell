/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ms_builtin_cd.c                                    :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/12/12 19:50:01 by marcosv2	       #+#    #+#	      */
/*   Updated: 2024/01/16 22:26:14 by marcosv2         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "minishell.h"

static int	ms_cd_testpath(char *path, char *vexp)
{
	DIR	*dir;
	int	fd;

	(void)vexp;
	dir = opendir(path);
	if (dir)
	{
		closedir(dir);
		return (0);
	}
	fd = open(path, O_WRONLY);
	if (fd >= 0)
	{
		close(fd);
		ft_putstr_fd(CD_ERR_A, STDERR);
		ft_putstr_fd(vexp, STDERR);
		ft_putstr_fd(CD_ERR_B, STDERR);
	}
	else
	{
		ft_putstr_fd(CD_ERR_C, STDERR);
		ft_putstr_fd(vexp, STDERR);
		ft_putstr_fd(CD_ERR_D, STDERR);
	}
	return (1);
}

static char	*ms_cd_pathjoin(char *path)
{
	char	*newpath;

	if (path[0] == '/')
		newpath = ft_strdup(path);
	else if (!ft_strncmp(path, "~/", 2))
	{
		newpath = ft_strdup(ms_home());
		ft_sujoin(&newpath, &path[1]);
	}
	else if (!ft_strncmp(path, "./", 2))
	{
		newpath = ft_strdup(ms_pwd());
		ft_sujoin(&newpath, &path[1]);
	}
	else
	{
		newpath = ft_strdup(ms_pwd());
		ft_sujoin(&newpath, "/");
		ft_sujoin(&newpath, path);
	}
	return (newpath);
}

static char	*ms_cd_splitjoin(char ***split, char *path)
{
	int	i;

	i = -1;
	while (split[0][++i])
	{
		if (!ft_strncmp(split[0][i], ".", 2))
			ft_tabrem_n(split, i--);
		else if (!ft_strncmp(split[0][i], "..", 3))
		{
			if (i > 0)
				ft_tabrem_n(split, --i);
			ft_tabrem_n(split, i--);
		}
	}
	path = ft_strdup("/");
	i = -1;
	while (split[0][++i])
	{
		ft_sujoin(&path, split[0][i]);
		if (split[0][i + 1])
			ft_sujoin(&path, "/");
	}
	return (path);
}

static int	ms_cd_core(t_mini *ms, char *vexpath)
{
	char	*temp;
	char	*path;
	char	**split;

	path = ms_cd_pathjoin(vexpath);
	split = ft_split(path, '/');
	ft_nfreestr(&path);
	path = ms_cd_splitjoin(&split, path);
	ft_nfreetab(&split);
	if (ms_cd_testpath(path, vexpath))
		return (ft_nfreestr(&path), 1);
	chdir(path);
	ft_strdrep(&ms->pwd, path);
	temp = ft_strjoin("PWD=", path);
	ms_export_core(ms, temp);
	return (free(temp), 0);
}

int	ms_builtin_cd(t_vars *vex)
{
	int		ret;
	t_mini	*ms;

	ms = ms_get_mini(NULL);
	if (vex->ac > 2)
		return (ft_putendl_fd(CD_ERR_N, STDERR), ms_ret(1), 0);
	else if (vex->ac == 1)
		ft_tabadd_n(&vex->av, ft_strdup("~/"), 1);
	else if (vex->av[1][0] == '\0')
		return (ms_ret(0), 0);
	ret = ms_cd_core(ms, vex->av[1]);
	return (ms_ret(ret), 0);
}
