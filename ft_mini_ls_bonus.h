/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_ls_bonus.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamasaw <syamasaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:38:16 by syamasaw          #+#    #+#             */
/*   Updated: 2024/01/25 15:06:49 by syamasaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINI_LS_BONUS_H
# define FT_MINI_LS_BONUS_H
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

//相反する条件の場合、最後に指定したオプションが適用(t,U 1,m)
typedef struct s_args_data
{
	int		number_of_paths;//パスの個数
	bool	oneline;//== -1, 有効ならtrue
	bool	sort_time;//== -t, 更新時間順、最近のが上
	bool	sort_rev;//== -r, 表示順序を逆にする
	bool	add_color;//== -G, 色を付ける
	bool	recursive;//== -R, 再帰的に表示、ディレクトリがあったらその中を出す 他のソートと合わせるとだいぶめんどう
	bool	unsort;//== -U, lsはデフォでアルファベット順にするが、ソートを一切しない。
	bool	separate_comma;//== -m, カンマ区切りにする
	bool	fin_use_option;//trueならパスとみなす
}		t_args_data;

#endif