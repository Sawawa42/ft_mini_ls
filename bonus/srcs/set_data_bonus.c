/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_data_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamasaw <syamasaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 21:34:29 by syamasaw          #+#    #+#             */
/*   Updated: 2024/02/10 19:02:50 by syamasaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_mini_ls_bonus.h"

t_data	*set_avail_dir(char **arg_paths, int num_of_dir, t_option option)
{
	int		i;
	int		j;
	DIR		*dir;
	t_data	*ret_data;

	ret_data = (t_data *)malloc(num_of_dir * sizeof(t_data));
	if (!ret_data)
		return (NULL);
	i = 0;
	j = 0;
	while (i < num_of_dir)
	{
		dir = opendir(arg_paths[j]);
		if (dir != NULL)
		{
			ret_data[i].name = arg_paths[j];
			lstat(arg_paths[j], &ret_data[i].info);
			i++;
			closedir(dir);
		}
		j++;
	}
	sort_t_data(ret_data, num_of_dir, option);
	return (ret_data);
}

t_data	*set_files_data(char **arg_paths, int num_of_files, t_option option)
{
	int		i;
	int		j;
	DIR		*dir;
	t_data	*ret_data;

	ret_data = (t_data *)malloc(num_of_files * sizeof(t_data));
	if (!ret_data)
		return (NULL);
	i = 0;
	j = 0;
	while (i < num_of_files)
	{
		dir = opendir(arg_paths[j]);
		if (dir != NULL)
			closedir(dir);
		else
			if (lstat(arg_paths[j], &ret_data[i].info) == 0)
				ret_data[i++].name = arg_paths[j];
		j++;
	}
	sort_t_data(ret_data, num_of_files, option);
	return (ret_data);
}
