/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_single_path_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamasaw <syamasaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:48:02 by syamasaw          #+#    #+#             */
/*   Updated: 2024/02/09 19:13:20 by syamasaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_mini_ls_bonus.h"

bool	ls_single_path(char *path, t_option option)
{
	int		cnt_paths_in_dir;
	DIR		*dir_ptr;
	t_data	*data;

	cnt_paths_in_dir = count_paths_in_dir(path);
	if (cnt_paths_in_dir < 0)
		return (false);
	dir_ptr = wrapper_opendir(path);
	if (!dir_ptr)
		return (false);
	data = set_dir_data(cnt_paths_in_dir, dir_ptr, path);
	if (!data)
		return (false);
	sort_paths_in_dir(data, cnt_paths_in_dir, option);
	control_put_result(data, cnt_paths_in_dir, option);
	closedir(dir_ptr);
	free(data);
	return (true);
}
