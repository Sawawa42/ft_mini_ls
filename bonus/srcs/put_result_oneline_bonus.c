/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_result_oneline_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamasaw <syamasaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 13:45:14 by syamasaw          #+#    #+#             */
/*   Updated: 2024/02/09 20:57:03 by syamasaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_mini_ls_bonus.h"

static void	put_result(t_data *data, t_option option, int i);

void	put_result_oneline(t_data *data, int num_of_files, t_option option)
{
	int	i;

	if (option.sort_rev == true)
	{
		i = num_of_files;
		while (--i >= 0)
			put_result(data, option, i);
	}
	else
	{
		i = -1;
		while (++i < num_of_files)
			put_result(data, option, i);
	}
}

static void	put_result(t_data *data, t_option option, int i)
{
	if (option.print_all == true)
	{
		putstr_color(data[i].name, i, data, option);
		putstr_fd("\n", 1);
	}
	else
	{
		if (data[i].name[0] != '.')
		{
			putstr_color(data[i].name, i, data, option);
			putstr_fd("\n", 1);
		}
	}
}
