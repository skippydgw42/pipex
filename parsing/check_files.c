/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegraeu <mdegraeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 13:39:31 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/03/02 15:41:04 by mdegraeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*split_flags(char *av)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	while (av[i] == ' ' && av[i])
		i++;
	j = i;
	while (av[i] != ' ' && av[i])
		i++;
	str = malloc(sizeof(char) * (i - j + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (av[j] != ' ' && av[j])
	{
		str[i] = av[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}

int	check_cmd(char **env, char *av, t_struct *vars)
{
	char	**str;
	char	*cmd;
	char	*join;
	int		i;

	str = get_paths(env);
	i = 0;
	if (ft_strlen(av) > 0)
	{
		while (str[i])
		{
			cmd = split_flags(av);
			join = ft_strjoin(str[i], cmd);
			i++;
			if (access(join, F_OK) == 0)
			{
				vars->v_cmd += 1;
				free_check_cmd(join, cmd);
				free_doubleptr(str);
				return (1);
			}
			free_check_cmd(join, cmd);
		}
	}
	free_doubleptr(str);
	return (0);
}

int	check_files(char **av)
{
	if (!av[1] || access(av[1], F_OK) == -1)
		return (0);
	if (!av[4])//|| access(av[4], R_OK) == -1)
		return (0);
	return (1);
}

int	parsing(int ac, char **av, char **env, t_struct *vars)
{
	int		i;

	i = 2;
	if (ac < 5)
		return (0);
	if (!check_files(av))
		return (0);
	while (i < ac - 1)
	{
		check_cmd(env, av[i], vars);
		i++;
	}
	if (vars->v_cmd < 1)
		return (0);
	return (1);
}