/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_data_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamasaw <syamasaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 21:34:29 by syamasaw          #+#    #+#             */
/*   Updated: 2024/02/09 22:12:56 by syamasaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_mini_ls_bonus.h"

t_data	*set_avail_dir(char **paths, int avail_dirs)
{
	int		i;
	int		j;
	DIR		*dir;
	t_data	*ret;

	ret = (t_data *)malloc(avail_dirs * sizeof(t_data));
	if (!ret)
		return (NULL);
	i = 0;
	j = 0;
	while (i < avail_dirs)
	{
		dir = opendir(paths[j]);
		if (dir != NULL)
		{
			ret[i].name = paths[j];
			lstat(paths[j], &ret[i].info);
			i++;
			closedir(dir);
		}
		j++;
	}
	return (ret);
}

t_data	*set_files_data(char **paths, int files)
{
	int		i;
	int		j;
	DIR		*dir;
	t_data	*ret;

	ret = (t_data *)malloc(files * sizeof(t_data));
	if (!ret)
		return (NULL);
	i = 0;
	j = 0;
	while (i < files)
	{
		dir = opendir(paths[j]);
		if (dir != NULL)
		{
			if (lstat(paths[j], &ret[i].info) == 0)
			{
				ret[i].name = paths[j];
				i++;
			}
			closedir(dir);
		}
		j++;
	}
	return (ret);
}
