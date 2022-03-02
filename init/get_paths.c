/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_paths.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegraeu <mdegraeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:41:12 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/03/02 15:35:35 by mdegraeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	**get_paths(char **env)
{
	int	i;

	i = 0;
	while (env[i] && ft_strncmp(env[i], "PATH=", 5))
		i++;
	return (ft_split(&env[i][5], ':'));
}

char	*init_strs(char *cmd, char *str, char *av)
{
	char	*temp;
	
	temp = split_flags(av);
	cmd = ft_strjoin(str, temp);
	return (temp);
}

char	*get_cmd(char *av, char **env)
{
	char	**str;
	char	*cmd;
	char	*temp;
	int		i;

	str = get_paths(env);
	i = 0;
	while (str[i])
	{
		temp = split_flags(av);
		cmd = ft_strjoin(str[i], temp);
		if (access(cmd, F_OK) == 0)
		{
			free(temp);
			free_doubleptr(str);
			return (cmd);
		}
		else
			free_check_cmd(cmd, temp);
		i++;
	}
	free_doubleptr(str);
	return (NULL);
}

void	cmd(t_struct *vars)
{
	int		i;
	int		j;
	char	*temp;
	char	*cmd;

	i = 1;
	j = 0;
	while (i < vars->nb_pipe)
	{
		if (!ft_strlen(vars->av[i]))
			i++;
		while (vars->env[j])
		{
			temp = split_flags(vars->av[i]);
			cmd = ft_strjoin(vars->env[j], temp);
			if (access(cmd, F_OK) == 0)
			{
				printf("%s\n", cmd);
				break ;
			}
			else
				free_check_cmd(temp, cmd);
			j++;
		}
		i++;
	}
}
