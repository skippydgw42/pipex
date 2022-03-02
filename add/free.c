/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegraeu <mdegraeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 15:23:15 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/03/01 12:16:19 by mdegraeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	free_check_cmd(char *str1, char *str2)
{
	if (str1)
		free(str1);
	if (str2)
		free(str2);
}
void	free_doubleptr(char **str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i])
		{
			if (str[i])
				free(str[i]);
			i++;
		}
		free(str);
	}
}

void	free_struct(t_struct *vars)
{
	if (vars->av)
		free_doubleptr(vars->av);
	if (vars->env)
		free_doubleptr(vars->env);
	if (vars->cmd)
		free_doubleptr(vars->cmd);
	if (vars->pip)
		free(vars->pip);
	free(vars);
}