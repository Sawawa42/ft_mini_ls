/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamasaw <syamasaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:37:48 by syamasaw          #+#    #+#             */
/*   Updated: 2024/01/27 19:19:16 by syamasaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mini_ls_bonus.h"

int				count_paths(int argc, char *argv[]);
bool			is_valid_option(char *arg);
static t_args	*init_t_args(int argc, char *argv[]);

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

//再帰は実装しません！！！！！！！！

//1. argv[n]がオプションか確かめる。 2. argv[n]がオプションではない場合、argv[n]からargv[argc - 1]全てをパスとみなす。
//3. 
int	main(int argc, char *argv[])//ls -1trG / ls -l -t -r -G -のないものをパスと見なし、パスの数だけ実行する。
{
	t_args	*args_data;

	args_data = init_t_args(argc, argv);
	if (args_data == NULL)
		return (ft_putstr_fd(MALLOC_ERROR, 2));
	printf("%d\n", args_data->add_color);
	return (0);
}

static t_args	*init_t_args(int argc, char *argv[])
{
	t_args	*ret;
	int		cnt_paths;

	cnt_paths = count_paths(argc, argv);
	if (cnt_paths > 0)
	{
		ret->paths = (char **)malloc(cnt_paths * sizeof(char *));
		if (ret->paths == NULL)
			return (NULL);
		int i = 0;
		while (i < cnt_paths)
		{
			ret->paths[i] = (char *)malloc();
			i++;
		}
	}
	else if (cnt_paths == 0)
	{
		ret->paths = (char **)malloc(sizeof(char *));
		if (ret->paths == NULL)
			return (NULL);
		cnt_paths = 1;
	}
	ret->number_of_paths = cnt_paths;
	ret->oneline = false;
	ret->sort_time = false;
	ret->sort_rev = false;
	ret->add_color = false;
	ret->unsort = false;
	ret->separate_comma = false;
	ret->fin_use_option = false;
	return (ret);
}

//argv[i]を渡してそれがパスならパスの長さ、違うなら-1?
int	find_path_length(char *arg)
{
	if (is_valid_option(arg) == true)
		return (strlen(arg));
	return (-1);
}

//パスの個数を数える
int	count_paths(int argc, char *argv[])
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (is_valid_option(argv[i]) == false)
			return (argc - i);
		i++;
	}	
	return (0);
}

//argv[i]を渡して、それがオプションならtrue違うならfalse
bool	is_valid_option(char *arg)
{
	int	i;

	if (arg[0] == '-' && strlen(arg) > 1)
	{
		i = 1;
		while (arg[i] != '\0')
		{
			if (strstr("1trGUm", &arg[i]) == NULL)
				return (false);
			i++;
		}
	}
	else
		return (false);
	return (true);
}

// static void	check_arg(char *arg, t_args_data *args_data)
// {
// 	int	i;

// 	if (arg[0] != '-' || args_data->fin_use_option == true)
// 		;//パス配列に代入,このあとを全てパスとみなすフラグをtrueに, return
// 	i = 1;
// 	while (arg[i] != '\0')
// 	{
// 		if (strstr("1trGUm", arg[i]) == NULL)
// 			;//パス配列に代入,このあとを全てパスとみなすフラグをtrueに, return
// 		i++;
// 	}
// 	i = 1;
// 	while (arg[i] != '\0')
// 	{
// 		if (arg[i] == 'l')
// 		{
// 			if (args_data->separate_comma == true)
// 				args_data->separate_comma = false;
// 			args_data->oneline = true;
// 		}
// 		else if (arg[i] == 't')
// 		{
// 			if (args_data->unsort == true)
// 				args_data->unsort = false;
// 			args_data->sort_time = true;
// 		}
// 		else if (arg[i] == 'm')
// 		{
// 			if (args_data->oneline == true)
// 				args_data->oneline = false;
// 			args_data->separate_comma = true;
// 		}
// 		else if (arg[i] == 'U')
// 		{
// 			if (args_data->sort_time == true)
// 				args_data->sort_time = false;
// 			args_data->unsort = true;
// 		}
// 		else if (arg[i] == 'r')
// 			args_data->sort_rev = true;
// 		else if (arg[i] == 'G')
// 			args_data->add_color = true;
// 		else if (arg[i] == 'R')
// 			args_data->recursive = true;
// 		i++;
// 	}
// }
