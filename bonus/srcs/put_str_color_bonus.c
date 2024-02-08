/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_str_color_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamasaw <syamasaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 15:17:21 by syamasaw          #+#    #+#             */
/*   Updated: 2024/02/08 16:51:39 by syamasaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_mini_ls_bonus.h"

static void	choice_color(t_data *data, int i);
static void	branch_dir(t_data *data, int i);
static void	branch_executable_type(t_data *data, int i);

int	putstr_color(const char *str, int i, t_data *data, t_option option)
{
	if (option.add_color == true)
		choice_color(data, i);
	putstr_fd(str, 1);
	putstr_fd("\x1b[0;49m", 1);
	return (0);
}

static void	choice_color(t_data *data, int i)
{
	if (S_ISDIR(data[i].info.st_mode))
		branch_dir(data, i);
	else if (S_ISLNK(data[i].info.st_mode))
		putstr_fd("\x1b[35;49m", 1);
	else if (S_ISSOCK(data[i].info.st_mode))
		putstr_fd("\x1b[32;49m", 1);
	else if (S_ISFIFO(data[i].info.st_mode))
		putstr_fd("\x1b[33;49m", 1);
	else if (data[i].info.st_mode & S_IXUSR || data[i].info.st_mode & S_IXGRP \
		|| data[i].info.st_mode & S_IXOTH)
		branch_executable_type(data, i);
	else if (S_ISCHR(data[i].info.st_mode))
		putstr_fd("\x1b[34;43m", 1);
	else if (S_ISBLK(data[i].info.st_mode))
		putstr_fd("\x1b[34;46m", 1);
	else
		putstr_fd("\x1b[0;49m", 1);
}

static void	branch_executable_type(t_data *data, int i)
{
	if (data[i].info.st_mode & S_ISUID)
		putstr_fd("\x1b[0;41m", 1);
	else if (data[i].info.st_mode & S_ISGID)
		putstr_fd("\x1b[0;43m", 1);
	else
		putstr_fd("\x1b[31;49m", 1);
}

static void	branch_dir(t_data *data, int i)
{
	if (data[i].info.st_mode & S_IWOTH)
	{
		if (data[i].info.st_mode & S_ISVTX)
			putstr_fd("\x1b[30;42m", 1);
		else
			putstr_fd("\x1b[30;43m", 1);
	}
	else
		putstr_fd("\x1b[34;49m", 1);
}
