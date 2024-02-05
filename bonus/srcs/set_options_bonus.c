/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_options_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamasaw <syamasaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:02:46 by syamasaw          #+#    #+#             */
/*   Updated: 2024/02/05 13:16:24 by syamasaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_mini_ls_bonus.h"

static void	control_settings(char c, t_options *options);
static void	set_option_for_enum(char c, t_options *options);
static void	set_option_for_sort(char c, t_options *options);
static void	init_options(t_options *options);

void	set_options(char *argv[], t_options *options)
{
	int	i;
	int	j;

	i = 1;
	init_options(options);
	while (argv[i] != '\0' && is_valid_option(argv[i]) == 1)//パスではないなら
	{
		j = 0;
		while (argv[i][j] != '\0')
			control_settings(argv[i][j++], options);
		i++;
	}
}

static void	init_options(t_options *options)
{
	options->oneline = false;
	options->separate_comma = false;
	options->sort_time = false;
	options->print_all = false;
	options->sort_rev = false;
	options->add_color = false;
}

static void	control_settings(char c, t_options *options)
{
	if (c == '1' || c == 'm')
		set_option_for_enum(c, options);
	else if (c == 't' || c == 'S')
		set_option_for_sort(c, options);
	else if (c == 'r')
		options->sort_rev = true;
	else if (c == 'G')
		options->add_color = true;
	else if (c == 'a')
		options->print_all = true;
}

static void	set_option_for_enum(char c, t_options *options)
{
	if (c == '1')
	{
		if (options->separate_comma == true)
			options->separate_comma = false;
		options->oneline = true;
	}
	else if (c == 'm')
	{
		if (options->oneline == true)
			options->oneline = false;
		options->separate_comma = true;
	}
}

static void	set_option_for_sort(char c, t_options *options)
{
	if (c == 't')
	{
		if (options->sort_size == false)
			options->sort_time = true;
	}
	else if (c == 'S')
	{
		if (options->sort_time == true)
			options->sort_time = false;
		options->sort_size = true;
	}
}
