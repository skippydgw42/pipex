/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegraeu <mdegraeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 10:50:16 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/02/25 14:39:00 by mdegraeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	child_process_b(int pip[1][2], char *av, char **env, char *cmd)
{
	char	**cflags;
	int		fd;

	close(pip[0][0]);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return (err());
	dup2(fd, STDIN_FILENO);
	close(fd);
	dup2(pip[0][1], STDOUT_FILENO);
	close(pip[0][1]);
	cflags = get_flags(av[?]);
	if (!cflags)
		return (err_mess("Split Error\n", cflags));
	if (execve(cmd[0], cflags, env) == -1)
		return (err_mess("Exec Child Error\n", cflags));
	free_doubleptr(cflags);
	return (1);
}

int	pipex_bonus(t_struct *vars)
{
	int	pip[vars->nb_pipe][2];
	int	pid;
	int	i;

	i = 0;
	while (i < vars->nb_pipe + 1)
	{
		if (pipe(pip[i]) < 0)
			return (err());
		i++;
	}
	i = 0;
	while (i < vars->nb_pipe)
	{
		pid = fork();
		if (pid < 0)
			return (err());
		if (pid == 0)
			child_process_b(pip[i], av, env, cmd[i]);
	}
}