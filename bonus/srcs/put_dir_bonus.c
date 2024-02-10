/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_dir_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamasaw <syamasaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 18:56:27 by syamasaw          #+#    #+#             */
/*   Updated: 2024/02/10 19:00:19 by syamasaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_mini_ls_bonus.h"

static bool	put_dir_rev(int cnt, int avail, t_option option, t_data *data);
static bool	put_dir(int cnt, int avail, t_option option, t_data *data);

bool	control_put_dir(int cnt_paths, int num_of_dir, t_option option, \
		t_data *data)
{
	if (option.sort_rev == true)
	{
		if (put_dir_rev(cnt_paths, num_of_dir, option, data) == false)
			return (false);
	}
	else
	{
		if (put_dir(cnt_paths, num_of_dir, option, data) == false)
			return (false);
	}
	return (true);
}

static bool	put_dir(int cnt, int num_of_dir, t_option option, t_data *data)
{
	int	i;

	i = 0;
	while (i < num_of_dir)
	{
		if (cnt > 1)
		{
			putstr_fd(data[i].name, 1);
			putstr_fd(":\n", 1);
		}
		if (ls_single_path(data[i].name, option) == false)
		{
			return (false);
		}
		i++;
		if (i < num_of_dir)
			putstr_fd("\n", 1);
	}
	return (true);
}

static bool	put_dir_rev(int cnt, int num_of_dir, t_option option, t_data *data)
{
	int	i;

	i = num_of_dir - 1;
	while (i >= 0)
	{
		if (cnt > 1)
		{
			putstr_fd(data[i].name, 1);
			putstr_fd(":\n", 1);
		}
		if (ls_single_path(data[i].name, option) == false)
		{
			return (false);
		}
		i--;
		if (i >= 0)
			putstr_fd("\n", 1);
	}
	return (true);
}
