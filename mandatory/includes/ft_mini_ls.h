/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_ls.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamasaw <syamasaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 12:43:58 by syamasaw          #+#    #+#             */
/*   Updated: 2024/02/12 19:44:15 by syamasaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINI_LS_H
# define FT_MINI_LS_H
# define COMMAND_NAME "ft_mini_ls"
# define ARG_ERROR ": Argument not allowed.\n"
# define OPENDIR_ERROR ": Failed to open directory.\n"
# define LSTAT_ERROR ": Failed to open file.\n"
# define MALLOC_ERROR ": Failed to allocate memory.\n"
# include <dirent.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <unistd.h>

typedef struct s_dirs_data
{
	char			*name;
	struct stat		info;
}					t_data;

typedef struct s_var
{
	int	right;
	int	left;
}		t_var;

/*ls_current.c*/
bool	ls_current(const char *path);

/*merge_time.c*/
bool	merge_sort_time(t_data *data, int len_of_data);

/*putresult_oneline_rev.c*/
void	putresult_oneline_rev(t_data *data, int num_of_segments);

/*utils.c*/
DIR		*wrapper_opendir(const char *path);
void	ft_putstr_fd(const char *str, int fd);
int		ft_strcmp(const char *s1, const char *s2);
void	puterror(char *error);

#endif