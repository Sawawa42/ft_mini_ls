/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putresult_oneline_rev.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamasaw <syamasaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 20:00:56 by syamasaw          #+#    #+#             */
/*   Updated: 2024/02/12 19:41:13 by syamasaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_mini_ls.h"

void	putresult_oneline_rev(t_data *data, int num_of_segments)
{
	int	i;

	i = num_of_segments;
	while (--i >= 0)
	{
		if (data[i].name[0] != '.')
		{
			ft_putstr_fd(data[i].name, 1);
			ft_putstr_fd("\n", 1);
		}
	}
}
