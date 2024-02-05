/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_for_current_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamasaw <syamasaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:48:02 by syamasaw          #+#    #+#             */
/*   Updated: 2024/02/05 12:58:52 by syamasaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_mini_ls_bonus.h"

bool	control_for_current(char *argv[])
{
	t_options	options;
	int			num_of_segments;
	DIR			*dir_ptr;
	t_data		*data;

	num_of_segments = count_files_and_dirs(".");
	if (num_of_segments < 0)
		return (false);
	set_options(argv, &options);
	dir_ptr = wrapper_opendir(".");
	if (!dir_ptr)
		return (false);
	data = set_dir_data(num_of_segments, dir_ptr);
	if (!data)
		return (false);
	sort_files_and_dirs(data, num_of_segments, options);
	control_put_result(data, num_of_segments, options);
	closedir(dir_ptr);
	free(data);
	return (true);
}
