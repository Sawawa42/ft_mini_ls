/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_ls.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamasaw <syamasaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 12:43:58 by syamasaw          #+#    #+#             */
/*   Updated: 2024/02/11 16:04:42 by syamasaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINI_LS_H
# define FT_MINI_LS_H
# include <unistd.h>
# include <sys/stat.h>
# include <stdbool.h>
# include <dirent.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# define COMMAND_NAME "ft_mini_ls"
# define ARG_ERROR ": Argument not allowed.\n"
# define OPENDIR_ERROR ": Failed to open directory.\n"
# define LSTAT_ERROR ": Failed to open file.\n"
# define MALLOC_ERROR ": Failed to allocate memory.\n"

typedef struct s_dirs_data
{
	char			*name;
	struct stat		info;
}					t_data;

/*ls_current.c*/
bool	ls_current(const char *path);

/*sorts.c*/
void	sort_time_rev(t_data *data, int num_of_segments);

/*putstrs_oneline.c*/
void	putstrs_oneline(t_data *data, int num_of_segments);

/*utils.c*/
DIR		*wrapper_opendir(const char *path);
void	ft_putstr_fd(const char *str, int fd);
int		ft_strcmp(const char *s1, const char *s2);
void	puterror(char *error);

#endif