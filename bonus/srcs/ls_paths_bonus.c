/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_paths_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamasaw <syamasaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:44:34 by syamasaw          #+#    #+#             */
/*   Updated: 2024/02/09 22:08:04 by syamasaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_mini_ls_bonus.h"

static char	**set_paths(int argc, char *argv[], int cnt_paths);
static int	check_paths(char **paths, int cnt_paths);
static void	put_no_such(char *path);
static void	free_paths(char **paths, int size);

bool	ls_paths(int argc, char *argv[], int cnt_paths, t_option option)
{
	char	**paths;
	int		avail_paths;
	t_data	*avail_dir_data;
	t_data	*files_data;

	avail_dir_data = NULL;
	files_data = NULL;
	avail_paths = 0;
	paths = set_paths(argc, argv, cnt_paths);//ここで有効無効関わらずオプション以外の引数を全部配列に
	if (paths == NULL)
		return (putstr_fd(MALLOC_ERROR, 2));
	avail_paths = check_paths(paths, cnt_paths);//ディレクトリの数を返し、非ディレクトリかつ存在しないファイルをエラー出力
	avail_dir_data = set_avail_dir(paths, avail_paths);
	sort_paths(avail_dir_data, avail_paths, option);
	if (avail_paths != cnt_paths)
	{
		files_data = set_files_data(paths, cnt_paths - avail_paths);
		sort_paths(files_data, cnt_paths - avail_paths, option);
		//putresult
	}
	if (put_result_paths(cnt_paths, avail_paths, option, avail_dir_data) == false)
	{
		free_paths(paths, cnt_paths);
		free(avail_dir_data);
		return (false);
	}
	free_paths(paths, cnt_paths);
	free(avail_dir_data);
	if (files_data != NULL)
		free(files_data);
	return (true);
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
	while (is_valid_option(argv[i]) == 1)
		i++;
	j = 0;
	while (i < argc)
	{
		paths[j] = (char *)malloc((ft_strlen(argv[i]) + 1) * sizeof(char));
		if (paths[j] == NULL)
		{
			free_paths(paths, j);
			return (NULL);
		}
		ft_memcpy(paths[j], argv[i], ft_strlen(argv[i]) + 1);
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

static int	check_paths(char **paths, int cnt_paths)
{
	int				i;
	int				cnt;
	DIR				*dir;
	struct stat		info;

	i = -1;
	cnt = cnt_paths;
	while (++i < cnt_paths)
	{
		dir = opendir(paths[i]);
		if (dir == NULL)
		{
			if (lstat(paths[i], &info) == -1)
				put_no_such(paths[i]);
			cnt--;
		}
		else
			closedir(dir);
	}
	return (cnt);
}

static void	put_no_such(char *path)
{
	putstr_fd("ft_mini_ls_bonus: ", 1);
	putstr_fd(path, 1);
	putstr_fd(": No such file or directory\n", 1);
}
