/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamasaw <syamasaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:53:30 by syamasaw          #+#    #+#             */
/*   Updated: 2024/01/30 15:29:44 by syamasaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_mini_ls.h"

int	main(int argc, char *argv[])
{
	(void)argv;
	if (argc != 1)
	{
		ft_putstr_fd(ARG_ERROR, 2);
		return (1);
	}
	else
		if (!ls_work("."))
			return (1);
	return (0);
}
