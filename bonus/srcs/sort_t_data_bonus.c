/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_t_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamasaw <syamasaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:42:42 by syamasaw          #+#    #+#             */
/*   Updated: 2024/02/10 17:23:01 by syamasaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_mini_ls_bonus.h"

static void	sort_ascii(t_data *data, int len_of_data);
static void	sort_time(t_data *data, int len_of_data);
static void	sort_size(t_data *data, int len_of_data);
static void	swap_data(t_data *data, int j);

void	sort_t_data(t_data *data, int len_of_data, t_option option)
{
	if (option.sort_time == true)
		sort_time(data, len_of_data);
	else if (option.sort_size == true)
		sort_size(data, len_of_data);
	else
		sort_ascii(data, len_of_data);
}

static void	sort_ascii(t_data *data, int len_of_data)
{
	int	i;
	int	j;

	i = 0;
	while (i < len_of_data - 1)
	{
		j = len_of_data - 1;
		while (j > i)
		{
			if (ft_strcmp(data[j - 1].name, data[j].name) > 0)
				swap_data(data, j);
			j--;
		}
		i++;
	}
}

static void	sort_time(t_data *data, int len_of_data)
{
	int	i;
	int	j;

	i = 0;
	while (i < len_of_data - 1)
	{
		j = len_of_data - 1;
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

static void	sort_size(t_data *data, int len_of_data)
{
	int	i;
	int	j;

	i = 0;
	while (i < len_of_data - 1)
	{
		j = len_of_data - 1;
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
