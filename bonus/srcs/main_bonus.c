/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamasaw <syamasaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:37:48 by syamasaw          #+#    #+#             */
/*   Updated: 2024/02/08 16:54:04 by syamasaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_mini_ls_bonus.h"

int	main(int argc, char *argv[])
{
	int			cnt_paths;
	t_option	option;

	cnt_paths = count_paths(argc, argv);
	set_option(argv, &option);
	if (cnt_paths == -1)
		return (putstr_fd(ILIGAL_OPTION, 2));
	else if (cnt_paths == 0)
	{
		if (ls_single_path(".", option) == false)
			return (1);
	}
	else
	{
		if (ls_paths(argc, argv, cnt_paths, option) == false)
			return (1);
	}
	return (0);
}
