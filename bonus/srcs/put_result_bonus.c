/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_result_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamasaw <syamasaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 12:23:00 by syamasaw          #+#    #+#             */
/*   Updated: 2024/02/05 14:55:56 by syamasaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mini_ls_bonus.h"

void	control_put_result(t_data *data, int num_of_segments, t_options option)
{
	if (option.oneline == true)
		put_result_oneline(data, num_of_segments, option);
	else if (option.separate_comma == true)
		put_result_comma(data, num_of_segments, option);
	else
		put_result_oneline(data, num_of_segments, option);
}
