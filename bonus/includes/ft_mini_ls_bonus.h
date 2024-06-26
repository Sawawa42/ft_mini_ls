/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_ls_bonus.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamasaw <syamasaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:38:16 by syamasaw          #+#    #+#             */
/*   Updated: 2024/02/12 19:30:51 by syamasaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINI_LS_BONUS_H
# define FT_MINI_LS_BONUS_H
# define COMMAND_NAME "ft_mini_ls_bonus"
# define LSTAT_ERROR ": Failed to open path.\n"
# define OPENDIR_ERROR ": Failed to open directory.\n"
# define MALLOC_ERROR ": Failed to allocate memory.\n"
# define AVAILABLE_OPTIONS "1trGmaS"
# include <dirent.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <unistd.h>

typedef struct s_data
{
	char			*name;
	struct stat		info;
}					t_data;

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
	bool	exit_code;
}			t_option;

typedef struct s_var
{
	int	right;
	int	left;
}		t_var;

/*ls_single_path_bonus.c*/
bool	ls_single_path(char *path, t_option option);

/*ls_paths_bonus.c*/
bool	ls_paths(int argc, char *argv[], int cnt_paths, t_option option);

/*set_option_bonus.c*/
void	set_option(char *argv[], t_option *option);

/*set_arg_paths_bonus.c*/
char	**set_arg_paths(int argc, char *argv[], int cnt_paths);

/*set_data_bonus.c*/
t_data	*set_avail_dir(char **arg_paths, int num_of_dir, t_option option);
t_data	*set_files_data(char **arg_paths, int num_of_files, t_option option);

/*sort_t_data_bonus.c*/
bool	sort_t_data(t_data *data, int len_of_data, t_option option);

/*merge_ascii_bonus.c*/
bool	merge_sort_ascii(t_data *data, int len_of_data);

/*merge_size_bonus.c*/
bool	merge_sort_size(t_data *data, int len_of_data);

/*merge_time_bonus.c*/
bool	merge_sort_time(t_data *data, int len_of_data);

/*put_dir_bonus.c*/
bool	control_put_dir(int cnt_paths, int num_of_dir, t_option option, \
		t_data *data);

/*put_result_bonus.c*/
void	control_put_result(t_data *data, int num_of_files, t_option option);

/*put_result_comma.c*/
void	put_result_comma(t_data *data, int num_of_files, t_option option);

/*put_result_oneline.c*/
void	put_result_oneline(t_data *data, int num_of_files, t_option option);

/*put_str_color_bonus.c*/
int		putstr_color(const char *str, int i, t_data *data, t_option option);

/*utils_bonus.c*/
int		putstr_fd(const char *str, int fd);
int		count_paths(int argc, char *argv[]);
int		is_valid_option(char *arg);
char	*pathjoin(char const *s1, char const *s2);

/*ft_funcs_bonus.c*/
int		ft_strcmp(const char *s1, const char *s2);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *str);

/*exit_funcs_bonus.c*/
void	*puterror(char *error);
bool	free_paths(char **arg_paths, int size);
bool	free_all(char **arg_paths, int size, t_data *data, bool ret);
bool	close_and_free(t_data *data, DIR *dir_ptr);
#endif