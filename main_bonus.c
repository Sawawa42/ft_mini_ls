/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamasaw <syamasaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:37:48 by syamasaw          #+#    #+#             */
/*   Updated: 2024/01/25 15:49:12 by syamasaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mini_ls_bonus.h"

/*
ls: illegal option -- 2
usage: ls [-ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1] [file ...]
*/
//ls . -- -> . OK -- KO (存在しないディレクトリ)
//ls -- . -> . OK
//ls -2 -> KO (存在しないオプション)
//ls -l -l -> OK ls -ll -> OK
//ls --l -> KO
//ls . - -> . OK - KO
//ls - . -> . OK - KO
//ls - -> KO
//ls " -l" -> KO
//ls \ -l -> ls -l
//ls -l\ or ls -l \ -> 入力行ってls -l
//ls -l . -a だと、ls -l で.と-aをパスとする。. -l . だと、全てをパスとみなす。
//ls "-l ."はエラー
//./a.out \-lの場合、argv[1][0]は\ではなく-！

//1. argv[n]がオプションか確かめる。 2. argv[n]がオプションではない場合、argv[n]からargv[argc - 1]全てをパスとみなす。
//3. 
int	main(int argc, char *argv[])//ls -1trG / ls -l -t -r -G -のないものをパスと見なし、パスの数だけ実行する。
{
	t_args_data	*args_data;
	
	return (0);
}

static bool	validate_args_format(int argc, char *argv[], t_args_data *args_data)
{
	int	i;

	i = 1;
	while (i < argc)//argv[1]~argv[argc - 1]を確認
	{
		i++;
	}
}

static void	check_arg(char *arg, t_args_data *args_data)
{
	int	i;

	if (arg[0] != '-' || args_data->fin_use_option == true)
		;//パス配列に代入,このあとを全てパスとみなすフラグをtrueに, return
	i = 1;
	while (arg[i] != '\0')
	{
		// if (arg[i] == '1' || arg[i] == 't' || arg[i] == 'r' || arg[i] == 'G' || arg[i] == 'R' || arg[i] == 'U' || arg[i] == 'm')
		if (strstr("1trGRUm", arg[i]) == NULL)
			;//パス配列に代入,このあとを全てパスとみなすフラグをtrueに, return
		i++;
	}
	i = 1;
	while (arg[i] != '\0')
	{
		if (arg[i] == 'l')
		{
			if (args_data->separate_comma == true)
				args_data->separate_comma = false;
			args_data->oneline = true;
		}
		else if (arg[i] == 't')
		{
			if (args_data->unsort == true)
				args_data->unsort = false;
			args_data->sort_time = true;
		}
		else if (arg[i] == 'm')
		{
			if (args_data->oneline == true)
				args_data->oneline = false;
			args_data->separate_comma = true;
		}
		else if (arg[i] == 'U')
		{
			if (args_data->sort_time == true)
				args_data->sort_time = false;
			args_data->unsort = true;
		}
		else if (arg[i] == 'r')
			args_data->sort_rev = true;
		else if (arg[i] == 'G')
			args_data->add_color = true;
		else if (arg[i] == 'R')
			args_data->recursive = true;
		i++;
	}
}
