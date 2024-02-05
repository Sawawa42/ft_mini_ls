/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_dir_utils_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamasaw <syamasaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:25:04 by syamasaw          #+#    #+#             */
/*   Updated: 2024/01/30 16:26:01 by syamasaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_mini_ls_bonus.h"

static void	set_struct(DIR *dir_ptr, t_data *data, int i);

int	count_files_and_dirs(const char *path)
{
	DIR				*dir_ptr;
	struct dirent	*dp;
	int				num_of_segments;

	dir_ptr = wrapper_opendir(path);
	if (dir_ptr == NULL)
		return (-1);
	num_of_segments = 0;
	while (1)
	{
		dp = readdir(dir_ptr);
		if (dp == NULL)
			break ;
		num_of_segments++;
	}
	closedir(dir_ptr);
	return (num_of_segments);
}

DIR	*wrapper_opendir(const char *path)
{
	DIR	*ret_dir_ptr;

	ret_dir_ptr = opendir(path);
	if (ret_dir_ptr == NULL)
	{
		ft_putstr_fd(OPENDIR_ERROR, 2);
		return (NULL);
	}
	return (ret_dir_ptr);
}

t_data	*set_dir_data(int num_of_segments, DIR *dir_ptr)
{
	t_data	*data;
	int		i;

	data = (t_data *)malloc(num_of_segments * sizeof(t_data));
	if (!data)
	{
		closedir(dir_ptr);
		ft_putstr_fd(MALLOC_ERROR, 2);
		return (NULL);
	}
	i = 0;
	while (i < num_of_segments)
	{
		set_struct(dir_ptr, data, i);
		i++;
	}
	return (data);
}

static void	set_struct(DIR *dir_ptr, t_data *data, int i)
{
	data[i].dp = readdir(dir_ptr);
	data[i].name = data[i].dp->d_name;
	lstat(data[i].name, &data[i].info);
	data[i].last_update = data[i].info.st_ctime;
	if (data[i].name[0] == '.')
		data[i].dot_file = true;
	else
		data[i].dot_file = false;
}
