/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_paths_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamasaw <syamasaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:44:34 by syamasaw          #+#    #+#             */
/*   Updated: 2024/02/08 18:40:47 by syamasaw         ###   ########.fr       */
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
	t_pdata	*pdata;

	paths = set_paths(argc, argv, cnt_paths);
	if (paths == NULL)
		return (putstr_fd(MALLOC_ERROR, 2));
	avail_paths = check_paths(paths, cnt_paths);
	pdata = sort_paths(paths, avail_paths, option);
	if (pdata == NULL)
	{
		free_paths(paths, cnt_paths);
		return (putstr_fd(MALLOC_ERROR, 2));
	}
	if (put_result_paths(cnt_paths, avail_paths, option, pdata) == false)
	{
		free_paths(paths, cnt_paths);
		free(pdata);
		return (false);
	}
	free_paths(paths, cnt_paths);
	free(pdata);
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

static int	check_paths(char **paths, int cnt_paths)
{
	int	i;
	int	cnt;
	DIR	*dir;

	i = -1;
	cnt = cnt_paths;
	while (++i < cnt_paths)
	{
		dir = opendir(paths[i]);
		if (dir == NULL)
		{
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
