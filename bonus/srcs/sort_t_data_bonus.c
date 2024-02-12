/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_t_data_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamasaw <syamasaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:42:42 by syamasaw          #+#    #+#             */
/*   Updated: 2024/02/12 19:21:39 by syamasaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_mini_ls_bonus.h"

bool	sort_t_data(t_data *data, int len_of_data, t_option option)
{
	if (option.sort_time == true)
	{
		if (merge_sort_time(data, len_of_data) == false)
			return (false);
	}
	else if (option.sort_size == true)
	{
		if (merge_sort_size(data, len_of_data) == false)
			return (false);
	}
	else
	{
		if (merge_sort_ascii(data, len_of_data) == false)
			return (false);
	}
	return (true);
}
