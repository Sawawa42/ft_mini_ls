/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_result_comma_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamasaw <syamasaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 14:02:59 by syamasaw          #+#    #+#             */
/*   Updated: 2024/02/09 20:56:29 by syamasaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_mini_ls_bonus.h"

static void	put_result(t_data *data, int num, t_option option, int i);
static void	put_result_rev(t_data *data, t_option option, int i);

void	put_result_comma(t_data *data, int num_of_files, t_option option)
{
	int	i;

	if (option.sort_rev == true)
	{
		i = num_of_files;
		while (--i >= 0)
			put_result_rev(data, option, i);
	}
	else
	{
		i = -1;
		while (++i < num_of_files)
			put_result(data, num_of_files, option, i);
	}
}

static void	put_result(t_data *data, int num_of_files, t_option option, int i)
{
	if (option.print_all == true)
	{
		putstr_color(data[i].name, i, data, option);
		if (i + 1 < num_of_files)
			putstr_fd(", ", 1);
		else
			putstr_fd("\n", 1);
	}
	else
	{
		if (data[i].name[0] != '.')
		{
			putstr_color(data[i].name, i, data, option);
			if (i + 1 < num_of_files)
				putstr_fd(", ", 1);
		}
		if (i + 1 == num_of_files)
			putstr_fd("\n", 1);
	}
}

static void	put_result_rev(t_data *data, t_option option, int i)
{
	if (option.print_all == true)
	{
		putstr_color(data[i].name, i, data, option);
		if (i - 1 >= 0)
			putstr_fd(", ", 1);
		else
			putstr_fd("\n", 1);
	}
	else
	{
		if (data[i].name[0] != '.')
		{
			putstr_color(data[i].name, i, data, option);
			if (i - 1 > 0)
				putstr_fd(", ", 1);
		}
		if (i - 1 == 0)
			putstr_fd("\n", 1);
	}
}
