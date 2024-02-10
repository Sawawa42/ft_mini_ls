/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_result_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamasaw <syamasaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 12:23:00 by syamasaw          #+#    #+#             */
/*   Updated: 2024/02/10 18:57:53 by syamasaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_mini_ls_bonus.h"

void	control_put_result(t_data *data, int num_of_files, t_option option)
{
	if (option.oneline == true)
		put_result_oneline(data, num_of_files, option);
	else if (option.separate_comma == true)
		put_result_comma(data, num_of_files, option);
	else
		put_result_oneline(data, num_of_files, option);
}
