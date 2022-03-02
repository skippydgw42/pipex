/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegraeu <mdegraeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 13:24:44 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/03/02 15:41:46 by mdegraeu         ###   ########.fr       */
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
	char	**m_cmd;
	char	**files;
	char	**env;
	char	**cmd;
	int		*pip;
	int		pid;
	int		nb_pipe;
	int		v_cmd;
}	t_struct;

//========ADD==========//
//error//
int		err(void);
int		err_a(char *str, t_struct *vars);
int		err_split(char **str);
int		err_mess(char *str, char **dstr);
//others//
void	free_doubleptr(char **str);
void	free_check_cmd(char *str1, char *str2);
void	free_struct(t_struct *vars);
char	**get_flags(char *av);

//========INIT=========//
char	**get_paths(char **env);
char	*get_cmd(char *av, char **env);
int		init_vars(t_struct *vars, int ac, char **av, char **env);

//=======PARSING=======//
int		parsing(int ac, char **av, char **env, t_struct *vars);
int		parsinit(int ac, char **av, char **env, t_struct *vars);
int		check_files(char **av);
int		check_cmd(char **env, char *av, t_struct *vars);
char	*split_flags(char *av);

//========SRCS========//
int		pipex(t_struct *vars);

//=========BONUS======//
int		pipex_bonus(t_struct *vars);
int		hm_cmd(char **cmd);

void	cmd(t_struct *vars);
void	print_dstr(char **str);

#endif
