/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_ls_bonus.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamasaw <syamasaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:38:16 by syamasaw          #+#    #+#             */
/*   Updated: 2024/02/08 19:20:39 by syamasaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINI_LS_BONUS_H
# define FT_MINI_LS_BONUS_H
# include <dirent.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <unistd.h>
# define ILIGAL_OPTION "ft_mini_ls_bonus: illegal option\n\
usage : ./ft_mini_ls_bonus [-1trGUm] [file ...]\n"
# define OPENDIR_ERROR "ft_mini_ls_bonus: Failed to open directory.\n"
# define MALLOC_ERROR "ft_mini_ls_bonus: Failed to allocate memory.\n"
# define AVAILABLE_OPTIONS "1trGmaS"

//Struct for data of files in a directory.
typedef struct s_dirs_data
{
	struct dirent	*dp;
	char			*name;
	struct stat		info;
	long			last_update;
	bool			dot_file;
}					t_data;

//Struct for directory data.
typedef struct s_pdata
{
	char			*name;
	struct stat		info;
}					t_pdata;

//Struct for ls command options.
typedef struct s_option
{
	bool	oneline;
	bool	sort_time;
	bool	sort_size;
	bool	sort_rev;
	bool	add_color;
	bool	separate_comma;
	bool	print_all;
}			t_option;

/*ls_single_path_bonus.c*/
bool	ls_single_path(char *path, t_option option);

/*ls_paths_bonus.c*/
bool	ls_paths(int argc, char *argv[], int cnt_paths, t_option option);

/*set_option_bonus.c*/
void	set_option(char *argv[], t_option *option);

/*sort_files_bonus.c*/
void	sort_files(t_data *data, int num_of_segments, t_option option);

/*load_dir_utils.c*/

int		count_files_and_dirs(const char *path);
DIR		*wrapper_opendir(const char *path);
t_data	*set_dir_data(int num_of_segments, DIR *dir_ptr);

int		putstr_fd(const char *str, int fd);
void	set_option(char *argv[], t_option *option);
int		count_paths(int argc, char *argv[]);
int		is_valid_option(char *arg);

void	control_put_result(t_data *data, int num_of_segments, t_option option);
bool	put_result_paths(int cnt_paths, int avail_paths, t_option option, \
		t_pdata *pdata);
void	put_result_comma(t_data *data, int num_of_segments, t_option option);
void	put_result_oneline(t_data *data, int num_of_segments, t_option option);

int		putstr_color(const char *str, int i, t_data *data, t_option option);
t_pdata	*sort_paths(char **paths, int cnt_paths, t_option option);

/*ft_funcs_bonus.c*/
int		ft_strcmp(const char *s1, const char *s2);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *str);
#endif