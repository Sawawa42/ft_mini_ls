/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_ls_bonus.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamasaw <syamasaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:38:16 by syamasaw          #+#    #+#             */
/*   Updated: 2024/02/05 16:56:26 by syamasaw         ###   ########.fr       */
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

//プログラム名が同一なので、分けてもいいかも？

typedef struct s_dirs_data
{
	struct dirent	*dp;
	char			*name;
	struct stat		info;
	long			last_update;
	bool			dot_file;
}					t_data;

//相反する条件の場合、最後に指定したオプションが適用(t,U 1,m)
typedef struct s_options
{
	bool	oneline;        //== -1, 有効ならtrue
	bool	sort_time;      //== -t, 更新時間順、最近のが上　実装
	bool	sort_size;		//== -S, ファイルサイズ順、大きいのが上　実装
	bool	sort_rev;       //== -r, 表示順序を逆にするput時に変える
	bool	add_color;      //== -G, 色を付ける
	bool	separate_comma; //== -m, カンマ区切りにする 実装
	bool	print_all;//== -a, .から始まるものも表示
}			t_options;

/*control_for_current.c*/

bool	control_for_current(char *argv[]);

/*load_dir_utils.c*/

int		count_files_and_dirs(const char *path);
DIR		*wrapper_opendir(const char *path);
t_data	*set_dir_data(int num_of_segments, DIR *dir_ptr);

int					ft_putstr_fd(const char *str, int fd);
void				set_options(char *argv[], t_options *options);
int					count_paths(int argc, char *argv[]);
int					is_valid_option(char *arg);
void				*ft_memcpy(void *dest, const void *src, size_t n);
int					ft_strcmp(const char *s1, const char *s2);

void	sort_files_and_dirs(t_data *data, int num_of_segments, t_options option);

void	control_put_result(t_data *data, int num_of_segments, t_options option);
void	put_result_comma(t_data *data, int num_of_segments, t_options option);
void	put_result_oneline(t_data *data, int num_of_segments, t_options option);

int	ft_putstr_color(const char *str, int i, t_data *data, t_options option);
#endif