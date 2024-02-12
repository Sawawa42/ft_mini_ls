/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_funcs_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamasaw <syamasaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:46:08 by syamasaw          #+#    #+#             */
/*   Updated: 2024/02/12 19:24:44 by syamasaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_mini_ls_bonus.h"

void	*puterror(char *error)
{
	putstr_fd(COMMAND_NAME, 2);
	putstr_fd(error, 2);
	return (NULL);
}

bool	free_paths(char **arg_paths, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(arg_paths[i]);
		i++;
	}
	free(arg_paths);
	return (false);
}

bool	free_all(char **arg_paths, int size, t_data *data, bool ret)
{
	free_paths(arg_paths, size);
	free(data);
	return (ret);
}

bool	close_and_free(t_data *data, DIR *dir_ptr)
{
	closedir(dir_ptr);
	free(data);
	return (false);
}
