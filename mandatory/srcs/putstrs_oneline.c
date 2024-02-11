/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putstrs_oneline.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamasaw <syamasaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 20:00:56 by syamasaw          #+#    #+#             */
/*   Updated: 2024/02/11 15:59:31 by syamasaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_mini_ls.h"

void	putstrs_oneline(t_data *data, int num_of_segments)
{
	int	i;

	i = 0;
	while (i < num_of_segments)
	{
		if (data[i].name[0] != '.')
		{
			ft_putstr_fd(data[i].name, 1);
			ft_putstr_fd("\n", 1);
		}
		i++;
	}
}
