/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamasaw <syamasaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:53:30 by syamasaw          #+#    #+#             */
/*   Updated: 2024/02/11 15:53:34 by syamasaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_mini_ls.h"

int	main(int argc, char *argv[])
{
	(void)argv;
	if (argc != 1)
	{
		puterror(ARG_ERROR);
		return (1);
	}
	else
		if (!ls_current("."))
			return (1);
	return (0);
}
