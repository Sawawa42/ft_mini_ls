/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_ls_bonus.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamasaw <syamasaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:38:16 by syamasaw          #+#    #+#             */
/*   Updated: 2024/01/30 12:57:11 by syamasaw         ###   ########.fr       */
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
# define AVAILABLE_OPTIONS "1trGUm"

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
	bool oneline;        //== -1, 有効ならtrue
	bool sort_time;      //== -t, 更新時間順、最近のが上
	bool sort_rev;       //== -r, 表示順序を逆にする
	bool add_color;      //== -G, 色を付ける
	bool unsort;         //== -U, lsはデフォでアルファベット順にするが、ソートを一切しない。
	bool separate_comma; //== -m, カンマ区切りにする
}					t_options;

int					ft_putstr_fd(const char *str, int fd);
void				set_options(char *argv[], t_options *options);
int					count_paths(int argc, char *argv[]);
int					is_valid_option(char *arg);
void				*ft_memcpy(void *dest, const void *src, size_t n);

#endif