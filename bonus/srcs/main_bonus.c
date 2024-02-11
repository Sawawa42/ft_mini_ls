/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamasaw <syamasaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:37:48 by syamasaw          #+#    #+#             */
/*   Updated: 2024/02/11 15:18:51 by syamasaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_mini_ls_bonus.h"

static int	puterror_illegal(void);

int	main(int argc, char *argv[])
{
	int			cnt_paths;
	t_option	option;

	set_option(argv, &option);
	cnt_paths = count_paths(argc, argv);
	if (cnt_paths == -1)
		return (puterror_illegal());
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

static int	puterror_illegal(void)
{
	putstr_fd(COMMAND_NAME, 2);
	putstr_fd(": illegal option\nusage : ./", 2);
	putstr_fd(COMMAND_NAME, 2);
	putstr_fd(" [-", 2);
	putstr_fd(AVAILABLE_OPTIONS, 2);
	putstr_fd("] [file ...]\n", 2);
	return (1);
}
