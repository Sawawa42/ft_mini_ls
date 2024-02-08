/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_files_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamasaw <syamasaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:42:42 by syamasaw          #+#    #+#             */
/*   Updated: 2024/02/08 20:04:52 by syamasaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_mini_ls_bonus.h"

static void	sort_ascii(t_data *data, int num_of_files);
static void	sort_time(t_data *data, int num_of_files);
static void	sort_size(t_data *data, int num_of_files);
static void	swap_data(t_data *data, int j);

void	sort_files(t_data *data, int num_of_files, t_option option)
{
	sort_ascii(data, num_of_files);
	if (option.sort_time == true)
		sort_time(data, num_of_files);
	else if (option.sort_size == true)
		sort_size(data, num_of_files);
}

static void	sort_ascii(t_data *data, int num_of_files)
{
	int	i;
	int	j;

	i = 0;
	while (i < num_of_files - 1)
	{
		j = num_of_files - 1;
		while (j > i)
		{
			if (ft_strcmp(data[j - 1].name, data[j].name) > 0)
				swap_data(data, j);
			j--;
		}
		i++;
	}
}

static void	sort_time(t_data *data, int num_of_files)
{
	int	i;
	int	j;

	i = 0;
	while (i < num_of_files - 1)
	{
		j = num_of_files - 1;
		while (j > i)
		{
			if (data[j - 1].last_update < data[j].last_update)
				swap_data(data, j);
			else if (data[j - 1].last_update == data[j].last_update \
				&& ft_strcmp(data[j - 1].name, data[j].name) > 0)
				swap_data(data, j);
			j--;
		}
		i++;
	}
}

static void	sort_size(t_data *data, int num_of_files)
{
	int	i;
	int	j;

	i = 0;
	while (i < num_of_files - 1)
	{
		j = num_of_files - 1;
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
