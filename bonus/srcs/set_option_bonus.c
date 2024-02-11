/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_option_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamasaw <syamasaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:02:46 by syamasaw          #+#    #+#             */
/*   Updated: 2024/02/11 14:56:03 by syamasaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_mini_ls_bonus.h"

static void	control_settings(char c, t_option *options);
static void	set_option_for_enum(char c, t_option *options);
static void	set_option_for_sort(char c, t_option *options);
static void	init_option(t_option *options);

void	set_option(char *argv[], t_option *option)
{
	int	i;
	int	j;

	i = 1;
	init_option(option);
	while (argv[i] != '\0' && is_valid_option(argv[i]) == 1)
	{
		j = 0;
		while (argv[i][j] != '\0')
			control_settings(argv[i][j++], option);
		i++;
	}
}

static void	init_option(t_option *option)
{
	option->oneline = false;
	option->sort_time = false;
	option->sort_rev = false;
	option->add_color = false;
	option->separate_comma = false;
	option->print_all = false;
	option->sort_size = false;
	option->exit_code = true;
}

static void	control_settings(char c, t_option *option)
{
	if (c == '1' || c == 'm')
		set_option_for_enum(c, option);
	else if (c == 't' || c == 'S')
		set_option_for_sort(c, option);
	else if (c == 'r')
		option->sort_rev = true;
	else if (c == 'G')
		option->add_color = true;
	else if (c == 'a')
		option->print_all = true;
}

static void	set_option_for_enum(char c, t_option *option)
{
	if (c == '1')
	{
		if (option->separate_comma == true)
			option->separate_comma = false;
		option->oneline = true;
	}
	else if (c == 'm')
	{
		if (option->oneline == true)
			option->oneline = false;
		option->separate_comma = true;
	}
}

static void	set_option_for_sort(char c, t_option *option)
{
	if (c == 't')
	{
		if (option->sort_size == false)
			option->sort_time = true;
	}
	else if (c == 'S')
	{
		if (option->sort_time == true)
			option->sort_time = false;
		option->sort_size = true;
	}
}
