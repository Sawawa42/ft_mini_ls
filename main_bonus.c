/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamasaw <syamasaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:37:48 by syamasaw          #+#    #+#             */
/*   Updated: 2024/01/29 19:33:21 by syamasaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mini_ls_bonus.h"

static char	**set_paths(int argc, char *argv[], int cnt_paths);
static void	free_paths(char **paths, int size);

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

int	main(int argc, char *argv[])
{
	char		**paths;
	int			cnt_paths;
	t_options	options;

	//ls -2 -lやls -2としたとき、エラーにするようにしたい
	cnt_paths = count_paths(argc, argv);
	if (cnt_paths == 0)
	{
		set_options(argv, &options);
	}
	else
	{
		paths = set_paths(argc, argv, cnt_paths);//pathを配列に確保
		if (paths == NULL)
			return (ft_putstr_fd(MALLOC_ERROR, 2));
		set_options(argv, &options);//オプションを構造体に記載
		//処理をここでやる
		int i = -1;
		while (++i < cnt_paths)
			printf("%s\n", paths[i]);
		free_paths(paths, cnt_paths);
	}
	return (0);
}

static char	**set_paths(int argc, char *argv[], int cnt_paths)
{
	char	**paths;
	int		i;
	int		j;

	paths = (char **)malloc(cnt_paths * sizeof(char *));
	if (paths == NULL)
		return (NULL);
	i = 1;
	while (is_valid_option(argv[i]) == true)
		i++;
	j = 0;
	while (i < argc)
	{
		paths[j] = (char *)malloc((strlen(argv[i]) + 1) * sizeof(char));
		if (paths[j] == NULL)
		{
			free_paths(paths, j);
			return (NULL);
		}
		ft_memcpy(paths[j], argv[i], strlen(argv[i]) + 1);
		i++;
		j++;
	}
	return (paths);
}

static void	free_paths(char **paths, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(paths[i]);
		i++;
	}
	free(paths);
}
