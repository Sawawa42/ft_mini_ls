/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamasaw <syamasaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 20:55:49 by syamasaw          #+#    #+#             */
/*   Updated: 2024/01/23 21:19:41 by syamasaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mini_ls.h"

DIR	*wrapper_opendir(const char *path)
{
	DIR	*ret_dir_ptr;

	ret_dir_ptr = opendir(path);
	if (ret_dir_ptr == NULL)
	{
		ft_putstr_fd(OPENDIR_ERROR, 2);
		return (NULL);
	}
	return (ret_dir_ptr);
}

void	ft_putstr_fd(const char *str, int fd)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(fd, &str[i], 1);
		i++;
	}
}

//小<- UNIX秒 ->大の並べ替え
void	sort_last_update(t_data *data, int num_of_segments)
{
	int		j;
	int		i;
	t_data	tmp_data;

	i = 0;
	while (i < num_of_segments - 1)
	{
		j = num_of_segments - 1;
		while (j > i)
		{
			if (data[j - 1].last_update > data[j].last_update)
			{
				tmp_data = data[j - 1];
				data[j - 1] = data[j];
				data[j] = tmp_data;
			}
			j--;
		}
		i++;
	}
}
