/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_ls.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamasaw <syamasaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 12:43:58 by syamasaw          #+#    #+#             */
/*   Updated: 2024/01/24 13:28:04 by syamasaw         ###   ########.fr       */
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
# define ARG_ERROR "ft_mini_ls: Argument not allowed.\n"
# define OPENDIR_ERROR "ft_mini_ls: Failed to open directory.\n"
# define MALLOC_ERROR "ft_mini_ls: Failed to allocate memory.\n"

typedef struct s_dirs_data
{
	struct dirent	*dp;
	char			*name;
	struct stat		info;
	long			last_update;
	bool			dot_file;
}					t_data;

void	ft_putstr_fd(const char *str, int fd);
bool	ls_work(const char *path);
DIR		*wrapper_opendir(const char *path);
void	sort_time_rev(t_data *data, int num_of_segments);
int		ft_strcmp(const char *s1, const char *s2);
void	putstrs_oneline(t_data *data, int num_of_segments);

#endif