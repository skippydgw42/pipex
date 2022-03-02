/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegraeu <mdegraeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 13:20:38 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/03/02 15:53:49 by mdegraeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	**cpy_dstr(char **av, int i)
{
	int		j;
	char	**str;

	j = 0;
	while (av[j])
		j++;
	str = malloc(sizeof(char *) * (j));
	if (!str)
		return (NULL);
	j = 0;
	while (av[i])
	{
		str[j] = ft_strdup(av[i]);
		i++;
		j++;
	}
	str[j] = 0;
	return (str);
}

int	*init_pipe(int ac)
{
	int	*pip;

	pip = malloc(sizeof(int) * (ac - 4));
	if (!pip)
		return (0);
	return (pip);
}

int	get_files(int ac, char **av, t_struct *vars)
{
	int	i;

	i = 0;
	vars->files = malloc(sizeof(char *) * 3);
	if (!vars->files)
		return (0);
	vars->files[0] = ft_strdup(av[i]);
	while (i < ac)
		i++;
	vars->files[1] = ft_strdup(av[i]);
	vars->files[2] = 0;
	if (!vars->files[0] || !vars->files[1])
		return (0);
	return (1);
}

int	main_cmd(int ac, char **av, t_struct *vars)
{
	int	i;
	int	j;

	i = 2;
	j = 0;
	vars->m_cmd = malloc(sizeof(char *) * (ac - 2));
	if (!vars->m_cmd)
		return (0);
	while (i < ac -1)
	{
		vars->m_cmd[j] = split_flags(av[i]);
		i++;
		j++;
	}
	vars->m_cmd[j] = 0;
	return (1);
}

int	init_vars(t_struct *vars, int ac, char **av, char **env)
{
	vars->ac = ac - 1;
	vars->v_cmd = 0;
	if (!main_cmd(ac, av, vars))
		return (0);
	if (!get_files(ac, av, vars))
		return (0);
	vars->env = get_paths(env);
	if (!vars->env)
		return (0);
	vars->cmd = malloc(sizeof(char *) * vars->ac);
	if (!vars->cmd)
		return (0);
	vars->nb_pipe = hm_cmd(vars->cmd) - 1;
	// vars->pip = init_pipe(ac);
	// if (!vars->pip)
	// 	return (0);
	return (1);
}
