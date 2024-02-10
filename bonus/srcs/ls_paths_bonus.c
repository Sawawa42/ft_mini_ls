/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_paths_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamasaw <syamasaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:44:34 by syamasaw          #+#    #+#             */
/*   Updated: 2024/02/10 20:46:41 by syamasaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_mini_ls_bonus.h"

static int	count_dir(char **arg_paths, int cnt_paths);
static int	count_files(char **arg_paths, int cnt_paths);
static void	put_no_such(char *arg_path);
static bool	put_file(char **arg_paths, int num_of_files, t_option option);

bool	ls_paths(int argc, char *argv[], int cnt_paths, t_option option)
{
	char	**arg_paths;
	int		num_of_dir;
	int		num_of_files;
	t_data	*arg_dir_data;

	arg_dir_data = NULL;
	arg_paths = set_arg_paths(argc, argv, cnt_paths);
	if (!arg_paths)
		return (false);
	num_of_dir = count_dir(arg_paths, cnt_paths);
	num_of_files = count_files(arg_paths, cnt_paths);
	if (cnt_paths > num_of_dir)
		if (put_file(arg_paths, num_of_files, option) == false)
			return (free_paths(arg_paths, cnt_paths), false);
	arg_dir_data = set_avail_dir(arg_paths, num_of_dir, option);
	if (!arg_dir_data)
		return (free_paths(arg_paths, cnt_paths), false);
	if (control_put_dir(cnt_paths, num_of_dir, option, arg_dir_data) == false)
		return (free_paths(arg_paths, cnt_paths), free(arg_dir_data), false);
	return (free_paths(arg_paths, cnt_paths), free(arg_dir_data), true);
}

static int	count_dir(char **arg_paths, int cnt_paths)
{
	int				i;
	int				cnt;
	DIR				*dir;
	struct stat		info;

	i = -1;
	cnt = cnt_paths;
	while (++i < cnt_paths)
	{
		dir = opendir(arg_paths[i]);
		if (dir == NULL)
		{
			if (lstat(arg_paths[i], &info) == -1)
				put_no_such(arg_paths[i]);
			cnt--;
		}
		else
			closedir(dir);
	}
	return (cnt);
}

static int	count_files(char **arg_paths, int cnt_paths)
{
	int				i;
	int				cnt;
	DIR				*dir;
	struct stat		info;

	i = -1;
	cnt = 0;
	while (++i < cnt_paths)
	{
		dir = opendir(arg_paths[i]);
		if (dir == NULL)
		{
			if (lstat(arg_paths[i], &info) != -1)
				cnt++;
		}
		else
			closedir(dir);
	}
	return (cnt);
}

static void	put_no_such(char *arg_path)
{
	putstr_fd("ft_mini_ls_bonus: ", 1);
	putstr_fd(arg_path, 1);
	putstr_fd(": No such file or directory\n", 1);
}

static bool	put_file(char **arg_paths, int num_of_files, t_option option)
{
	t_data	*arg_file_data;

	arg_file_data = set_files_data(arg_paths, num_of_files, option);
	if (!arg_file_data)
		return (false);
	control_put_result(arg_file_data, num_of_files, option);
	free(arg_file_data);
	return (true);
}
