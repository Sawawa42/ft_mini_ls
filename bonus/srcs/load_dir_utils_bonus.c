/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_dir_utils_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamasaw <syamasaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:25:04 by syamasaw          #+#    #+#             */
/*   Updated: 2024/02/09 22:11:01 by syamasaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_mini_ls_bonus.h"

static void	set_struct(DIR *dir_ptr, t_data *data, int i, char *path);

int	count_paths_in_dir(const char *path)
{
	DIR				*dir_ptr;
	struct dirent	*dp;
	int				cnt_paths_in_dir;

	dir_ptr = wrapper_opendir(path);//パスがディレクトリではない場合、もしくはひらけなかった場合を考慮すべき
	if (dir_ptr == NULL)
		return (-1);
	cnt_paths_in_dir = 0;
	while (1)
	{
		dp = readdir(dir_ptr);
		if (dp == NULL)
			break ;
		cnt_paths_in_dir++;
	}
	closedir(dir_ptr);
	return (cnt_paths_in_dir);
}

DIR	*wrapper_opendir(const char *path)
{
	DIR	*ret_dir_ptr;

	ret_dir_ptr = opendir(path);
	if (ret_dir_ptr == NULL)
	{
		putstr_fd(OPENDIR_ERROR, 2);
		return (NULL);
	}
	return (ret_dir_ptr);
}

t_data	*set_dir_data(int cnt_paths_in_dir, DIR *dir_ptr, char *path)
{
	t_data	*data;
	int		i;

	data = (t_data *)malloc(cnt_paths_in_dir * sizeof(t_data));
	if (!data)
	{
		closedir(dir_ptr);
		putstr_fd(MALLOC_ERROR, 2);
		return (NULL);
	}
	i = 0;
	while (i < cnt_paths_in_dir)
	{
		set_struct(dir_ptr, data, i, path);
		i++;
	}
	return (data);
}

static void	set_struct(DIR *dir_ptr, t_data *data, int i, char *path)
{
	struct dirent	*dp;

	dp = readdir(dir_ptr);
	data[i].name = dp->d_name;
	if (lstat(pathjoin(path, dp->d_name), &data[i].info) == -1)// pathjoin内にmalloc
	{
		perror("lstat");
		exit(EXIT_FAILURE);
	}
}
