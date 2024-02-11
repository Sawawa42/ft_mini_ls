/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamasaw <syamasaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:28:54 by syamasaw          #+#    #+#             */
/*   Updated: 2024/02/11 15:58:43 by syamasaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_mini_ls.h"

static void	swap_data(t_data *data, int j);

/*
Put the oldest update times at the top of the array.
If the last update times are the same, sort in ASCII order.
*/
void	sort_time_rev(t_data *data, int num_of_segments)
{
	int		i;
	int		j;

	i = 0;
	while (i < num_of_segments - 1)
	{
		j = num_of_segments - 1;
		while (j > i)
		{
			if (data[j - 1].info.st_mtime > data[j].info.st_mtime)
				swap_data(data, j);
			else if (data[j - 1].info.st_mtime == data[j].info.st_mtime)
				if (ft_strcmp(data[j - 1].name, data[j].name) < 0)
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
