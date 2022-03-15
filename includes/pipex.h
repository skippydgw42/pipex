/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegraeu <mdegraeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 13:24:44 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/03/15 13:01:49 by mdegraeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct s_struct
{
	int		ac;
	char	**files;
	char	**env;
	char	**f_cmd;
	char	**p_cmd;
	int		nb_pipe;
}	t_struct;

//========ADD==========//
//error//
int		err(void);
int		err_a(char *str, t_struct *vars);
int		err_split(char **str);
int		err_mess(char *str, char **dstr);
int		p_error(char *str);
//others//
void	free_doubleptr(char **str);
void	free_two_str(char *str1, char *str2);
void	free_struct(t_struct *vars);
int		hm_cmd(char **cmd);
char	*split_flags(char *av);
char	**get_flags(char *av);

//========INIT=========//
int		get_paths(char **env, t_struct *vars);
int		get_files(char **av, t_struct *vars);
int		init_struct(int ac, char **av, char **env, t_struct *vars);

//=======PARSING=======//
int		parsing(int ac, char **av);
int		check_files(char **av);

//========SRCS========//
int		pipex(t_struct *vars);

#endif
