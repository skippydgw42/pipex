/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsinit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegraeu <mdegraeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 15:39:28 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/03/01 15:13:53 by mdegraeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	parsinit(int ac, char **av, char **env, t_struct *vars)
{
	int	i;
	int	j;

	i = 2;
	j = 0;
	if (!parsing(ac, av, env, vars))
		return (0);
	while (i < ac - 1)
	{
		if (ft_strlen(av[i]) > 0)
		{
			vars->cmd[j] = get_cmd(av[i], env);
			j++;
		}
		i++;
		// if (vars->cmd[j - 1][ft_strlen(vars->cmd[j - 1]) - 1] == '/')
		// {
		// 	j--;
		// 	free(vars->cmd[j]);
		// }
	}
	vars->cmd[j] = 0;
	return (1);
}