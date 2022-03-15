/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegraeu <mdegraeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 16:24:30 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/03/15 13:00:10 by mdegraeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	child_process(int pip[2], t_struct *vars)
{
	char	**cflags;
	int		fd;

	close(pip[0]);
	fd = open(vars->files[0], O_RDONLY);
	if (fd < 0)
		return (err());
	dup2(fd, STDIN_FILENO);
	close(fd);
	dup2(pip[1], STDOUT_FILENO);
	close(pip[1]);
	cflags = get_flags(vars->f_cmd[0]);
	if (!cflags)
		return (err_mess("cflags_c Error\n", cflags));
	if (execve(vars->p_cmd[0], cflags, vars->env) == -1)
		return (err_mess("Exec Child: Command not found\n", cflags));
	free_doubleptr(cflags);
	return (1);
}

int	parent_process(int pip[2], t_struct *vars)
{
	int		fd;
	char	**cflags;

	close(pip[1]);
	fd = open(vars->files[1], O_TRUNC | O_WRONLY | O_CREAT, 0666);
	if (fd < 0)
		return (err());
	dup2(fd, STDOUT_FILENO);
	close(fd);
	dup2(pip[0], STDIN_FILENO);
	close(pip[0]);
	cflags = get_flags(vars->f_cmd[1]);
	if (!cflags)
		return (err_mess("cflags_p Error\n", cflags));
	if (execve(vars->p_cmd[1], cflags, vars->env) == -1)
		return (err_mess("Exec Parent: Command not found\n", cflags));
	free_doubleptr(cflags);
	return (1);
}

int	pipex(t_struct *vars)
{
	int		pid;
	int		pip[2];

	if (pipe(pip) == -1)
		return (p_error("Pipe Construction Failed"));
	pid = fork();
	if (pid == 0)
		child_process(pip, vars);
	if (pid != 0)
		parent_process(pip, vars);
	if (pid != 0)
		waitpid(pid, NULL, 0);
	return (1);
}
