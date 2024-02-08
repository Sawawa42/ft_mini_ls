/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_single_path_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamasaw <syamasaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:48:02 by syamasaw          #+#    #+#             */
/*   Updated: 2024/02/08 16:21:58 by syamasaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_mini_ls_bonus.h"

bool	ls_single_path(char *path, t_option option)
{
	int		num_of_files;
	DIR		*dir_ptr;
	t_data	*data;

	num_of_files = count_files_and_dirs(path);
	if (num_of_files < 0)
		return (false);
	dir_ptr = wrapper_opendir(path);
	if (!dir_ptr)
		return (false);
	data = set_dir_data(num_of_files, dir_ptr);
	if (!data)
		return (false);
	sort_files(data, num_of_files, option);
	control_put_result(data, num_of_files, option);
	closedir(dir_ptr);
	free(data);
	return (true);
}
