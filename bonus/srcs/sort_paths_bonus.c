/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_paths_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamasaw <syamasaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:46:48 by syamasaw          #+#    #+#             */
/*   Updated: 2024/02/09 22:08:52 by syamasaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_mini_ls_bonus.h"

// static t_data	*set_data(char **paths, int avail_paths);
static void		sort_paths_ascii(t_data *data, int avail_paths);
static void		sort_paths_time(t_data *data, int avail_paths);
static void		sort_paths_size(t_data *data, int avail_paths);
static void		swap_data(t_data *data, int j);

void	sort_paths(t_data *data, int avail_paths, t_option option)
{
	if (option.sort_time == true)
		sort_paths_time(data, avail_paths);
	else if (option.sort_size == true)
		sort_paths_size(data, avail_paths);
	else
		sort_paths_ascii(data, avail_paths);
}

static void	sort_paths_ascii(t_data *data, int avail_paths)
{
	int	i;
	int	j;

	i = 0;
	while (i < avail_paths - 1)
	{
		j = avail_paths - 1;
		while (j > i)
		{
			if (ft_strcmp(data[j - 1].name, data[j].name) > 0)
				swap_data(data, j);
			j--;
		}
		i++;
	}
}

static void	sort_paths_time(t_data *data, int avail_paths)
{
	int	i;
	int	j;

	i = 0;
	while (i < avail_paths - 1)
	{
		j = avail_paths - 1;
		while (j > i)
		{
			if (data[j - 1].info.st_mtime < data[j].info.st_mtime)
				swap_data(data, j);
			else if (data[j - 1].info.st_mtime == data[j].info.st_mtime)
				if (ft_strcmp(data[j - 1].name, data[j].name) > 0)
					swap_data(data, j);
			j--;
		}
		i++;
	}
}

static void	sort_paths_size(t_data *data, int avail_paths)
{
	int	i;
	int	j;

	i = 0;
	while (i < avail_paths - 1)
	{
		j = avail_paths - 1;
		while (j > i)
		{
			if (data[j - 1].info.st_size < data[j].info.st_size)
				swap_data(data, j);
			else if (data[j - 1].info.st_size == data[j].info.st_size)
				if (ft_strcmp(data[j - 1].name, data[j].name) > 0)
					swap_data(data, j);
			j--;
		}
		i++;
	}
}

static void	swap_data(t_data *data, int j)
{
	t_data	tmp_data;

	tmp_data = data[j - 1];
	data[j - 1] = data[j];
	data[j] = tmp_data;
}
