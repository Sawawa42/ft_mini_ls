/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamasaw <syamasaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:37:48 by syamasaw          #+#    #+#             */
/*   Updated: 2024/01/30 13:00:24 by syamasaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mini_ls_bonus.h"

static char	**set_paths(int argc, char *argv[], int cnt_paths);
static void	free_paths(char **paths, int size);

int	main(int argc, char *argv[])
{
	char		**paths;
	int			cnt_paths;
	t_options	options;

	cnt_paths = count_paths(argc, argv);
	if (cnt_paths == -1)
		return (ft_putstr_fd(ILIGAL_OPTION, 2));
	else if (cnt_paths == 0)
	{
		set_options(argv, &options);
	}
	else
	{
		set_options(argv, &options);//オプションを構造体に記載
		paths = set_paths(argc, argv, cnt_paths);//pathを配列に確保
		if (paths == NULL)
			return (ft_putstr_fd(MALLOC_ERROR, 2));
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
	while (is_valid_option(argv[i]) == 1)//存在するオプションがある間
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
