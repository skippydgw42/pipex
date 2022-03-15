/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegraeu <mdegraeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 12:05:47 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/03/15 11:37:03 by mdegraeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	check_files(char **av)
{
	if (!av[1] || access(av[1], F_OK) == -1 || access(av[1], R_OK) == -1)
		return (p_error(av[1]));
	if (!av[4])
		return (0);
	return (1);
}

int	parsing(int ac, char **av)
{
	if (ac != 5)
		return (p_error("Bad Args Count"));
	if (!check_files(av))
		return (0);
	return (1);
}
