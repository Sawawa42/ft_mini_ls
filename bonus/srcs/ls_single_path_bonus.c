/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_single_path_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamasaw <syamasaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:48:02 by syamasaw          #+#    #+#             */
/*   Updated: 2024/02/12 19:25:42 by syamasaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_mini_ls_bonus.h"

static int		count_paths_in_dir(const char *path);
static DIR		*wrapper_opendir(const char *path);
static t_data	*set_dir_data(int num_of_paths, DIR *dir_ptr, char *path);
static bool		set_struct(DIR *dir_ptr, t_data *data, int i, char *path);

bool	ls_single_path(char *path, t_option option)
{
	int		num_of_paths;
	DIR		*dir_ptr;
	t_data	*data;

	num_of_paths = count_paths_in_dir(path);
	if (num_of_paths < 0)
		return (false);
	dir_ptr = wrapper_opendir(path);
	if (!dir_ptr)
		return (false);
	data = set_dir_data(num_of_paths, dir_ptr, path);
	if (!data)
		return (false);
	if (sort_t_data(data, num_of_paths, option) == false)
		return (close_and_free(data, dir_ptr));
	control_put_result(data, num_of_paths, option);
	closedir(dir_ptr);
	free(data);
	return (true);
}

static int	count_paths_in_dir(const char *path)
{
	DIR				*dir_ptr;
	struct dirent	*dp;
	int				num_of_paths;

	dir_ptr = wrapper_opendir(path);
	if (dir_ptr == NULL)
		return (-1);
	num_of_paths = 0;
	while (1)
	{
		dp = readdir(dir_ptr);
		if (dp == NULL)
			break ;
		num_of_paths++;
	}
	closedir(dir_ptr);
	return (num_of_paths);
}

static DIR	*wrapper_opendir(const char *path)
{
	DIR	*dir_ptr;

	dir_ptr = opendir(path);
	if (dir_ptr == NULL)
		return (puterror(OPENDIR_ERROR));
	return (dir_ptr);
}

static t_data	*set_dir_data(int num_of_paths, DIR *dir_ptr, char *path)
{
	t_data	*data;
	int		i;

	data = (t_data *)malloc(num_of_paths * sizeof(t_data));
	if (!data)
	{
		closedir(dir_ptr);
		return (puterror(MALLOC_ERROR));
	}
	i = -1;
	while (++i < num_of_paths)
		if (set_struct(dir_ptr, data, i, path) == false)
			return (NULL);
	return (data);
}

static bool	set_struct(DIR *dir_ptr, t_data *data, int i, char *path)
{
	struct dirent	*dp;
	char			*longpath;

	dp = readdir(dir_ptr);
	data[i].name = dp->d_name;
	longpath = pathjoin(path, dp->d_name);
	if (!longpath)
	{
		puterror(MALLOC_ERROR);
		return (false);
	}
	if (lstat(longpath, &data[i].info) == -1)
	{
		puterror(LSTAT_ERROR);
		free(longpath);
		return (false);
	}
	free(longpath);
	return (true);
}
