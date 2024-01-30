/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_work.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamasaw <syamasaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 21:21:53 by syamasaw          #+#    #+#             */
/*   Updated: 2024/01/29 15:50:19 by syamasaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mini_ls.h"

static int		word_count_lines(const char *path);
static t_data	*set_dir_data(int num_of_segments, DIR *dir_ptr);
static void		set_struct(DIR *dir_ptr, t_data *data, int i);

bool	ls_work(const char *path)
{
	int		num_of_segments;
	DIR		*dir_ptr;
	t_data	*data;

	num_of_segments = word_count_lines(path);
	if (num_of_segments < 0)
		return (false);
	dir_ptr = wrapper_opendir(path);
	if (!dir_ptr)
		return (false);
	data = set_dir_data(num_of_segments, dir_ptr);
	if (!data)
		return (false);
	sort_time_rev(data, num_of_segments);
	putstrs_oneline(data, num_of_segments);
	closedir(dir_ptr);
	free(data);
	return (true);
}

static int	word_count_lines(const char *path)
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

static t_data	*set_dir_data(int num_of_segments, DIR *dir_ptr)
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
