/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_result_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamasaw <syamasaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 12:23:00 by syamasaw          #+#    #+#             */
/*   Updated: 2024/02/08 18:54:31 by syamasaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_mini_ls_bonus.h"

static bool	paths(int cnt, int avail, t_option option, t_pdata *pdata);
static bool	paths_rev(int cnt, int avail, t_option option, t_pdata *pdata);

void	control_put_result(t_data *data, int num_of_files, t_option option)
{
	if (option.oneline == true)
		put_result_oneline(data, num_of_files, option);
	else if (option.separate_comma == true)
		put_result_comma(data, num_of_files, option);
	else
		put_result_oneline(data, num_of_files, option);
}

bool	put_result_paths(int cnt_paths, int avail_paths, t_option option, \
		t_pdata *pdata)
{
	if (option.sort_rev == true)
	{
		if (paths_rev(cnt_paths, avail_paths, option, pdata) == false)
			return (false);
	}
	else
	{
		if (paths(cnt_paths, avail_paths, option, pdata) == false)
			return (false);
	}
	return (true);
}

static bool	paths(int cnt, int avail, t_option option, t_pdata *pdata)
{
	int	i;

	i = 0;
	while (i < avail)
	{
		if (cnt > 1)
		{
			putstr_fd(pdata[i].name, 1);
			putstr_fd(":\n", 1);
		}
		if (ls_single_path(pdata[i].name, option) == false)
		{
			return (false);
		}
		i++;
		if (i < avail)
			putstr_fd("\n", 1);
	}
	return (true);
}

static bool	paths_rev(int cnt, int avail, t_option option, t_pdata *pdata)
{
	int	i;

	i = avail - 1;
	while (i >= 0)
	{
		if (cnt > 1)
		{
			putstr_fd(pdata[i].name, 1);
			putstr_fd(":\n", 1);
		}
		if (ls_single_path(pdata[i].name, option) == false)
		{
			return (false);
		}
		i--;
		if (i >= 0)
			putstr_fd("\n", 1);
	}
	return (true);
}
