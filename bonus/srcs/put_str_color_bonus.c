/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_str_color_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamasaw <syamasaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 15:17:21 by syamasaw          #+#    #+#             */
/*   Updated: 2024/02/05 19:03:19 by syamasaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mini_ls_bonus.h"

static void	choice_color(t_data *data, t_options option, int i);

int	ft_putstr_color(const char *str, int i, t_data *data, t_options option)
{
	if (option.add_color == true)
		choice_color(data, option, i);
	ft_putstr_fd(str, 1);
	write(1, "\e[0m", 4);
	return (0);
}

static void	choice_color(t_data *data, t_options option, int i)
{
	(void)option;
	if (S_ISDIR(data[i].info.st_mode))
		write(1, "\x1b[34m", 5);
	else if (S_ISLNK(data[i].info.st_mode))
		write(1, "\e[35m", 5);
	else if (S_ISSOCK(data[i].info.st_mode))
		write(1, "\e[32m", 5);
	else if (S_ISFIFO(data[i].info.st_mode))
		write(1, "\e[38;2;143;101;82m", 19);
	else if (data[i].info.st_mode & S_IXUSR || data[i].info.st_mode & S_IXGRP \
		|| data[i].info.st_mode & S_IXOTH)
		write(1, "\x1b[31m", 5);
	else if (S_ISCHR(data[i].info.st_mode))
		write(1, "\x1b[34m\e[38;2;143;101;82m", 8);
	else if (S_ISBLK(data[i].info.st_mode))
		write(1, "\x1b[34;46m", 8);
	else
		write(1, "\e[0m", 4);
}
