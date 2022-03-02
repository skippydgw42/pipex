/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegraeu <mdegraeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 11:35:44 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/03/02 15:35:52 by mdegraeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	print_dstr(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		dprintf(1, "%s\n", str[i]);
		i++;
	}
}

int	main(int ac, char **av, char **env)
{
	t_struct	*vars;
	
	vars = malloc(sizeof(t_struct) + 1);
	if (!vars)
		return (err());
	if (!init_vars(vars, ac, av, env))
		return (err_a("Struct Init Error\n", vars));
	cmd(vars);
	// if (!parsinit(ac, av, env, vars))
	// 	return (err_a("Parsing Error\n", vars));
	// if (!pipex(vars))
	// 	return (err_a("Pipex Error\n", vars));
	free_struct(vars);
	return (0);
}
