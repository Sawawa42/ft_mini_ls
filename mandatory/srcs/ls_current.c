/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_current.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamasaw <syamasaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 21:21:53 by syamasaw          #+#    #+#             */
/*   Updated: 2024/02/12 19:47:28 by syamasaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_mini_ls.h"

static int		word_count_lines(const char *path);
static t_data	*set_dir_data(int num_of_segments, DIR *dir_ptr);
static bool		set_struct(DIR *dir_ptr, t_data *data, int i);
static bool		close_and_free(t_data *data, DIR *dir_ptr);

bool	ls_current(const char *path)
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
	if (merge_sort_time(data, num_of_segments) == false)
		return (close_and_free(data, dir_ptr));
	putresult_oneline_rev(data, num_of_segments);
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
		puterror(MALLOC_ERROR);
		return (NULL);
	}
	i = 0;
	while (i < num_of_segments)
	{
		if (set_struct(dir_ptr, data, i) == false)
		{
			closedir(dir_ptr);
			free(data);
			return (NULL);
		}
		i++;
	}
	return (data);
}

static bool	set_struct(DIR *dir_ptr, t_data *data, int i)
{
	struct dirent	*dp;

	dp = readdir(dir_ptr);
	data[i].name = dp->d_name;
	if (lstat(data[i].name, &data[i].info) == -1)
	{
		puterror(LSTAT_ERROR);
		return (false);
	}
	return (true);
}

static bool	close_and_free(t_data *data, DIR *dir_ptr)
{
	closedir(dir_ptr);
	free(data);
	return (false);
}
