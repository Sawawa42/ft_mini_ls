/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_paths_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamasaw <syamasaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:46:48 by syamasaw          #+#    #+#             */
/*   Updated: 2024/02/08 19:53:09 by syamasaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_mini_ls_bonus.h"

static t_pdata	*set_pdata(char **paths, int avail_paths);
static void		sort_paths_ascii(t_pdata *pdata, int avail_paths);
static void		sort_paths_time(t_pdata *pdata, int avail_paths);
static void		sort_paths_size(t_pdata *pdata, int avail_paths);
static void		swap_pdata(t_pdata *pdata, int j);

t_pdata	*sort_paths(char **paths, int avail_paths, t_option option)
{
	t_pdata	*pdata;

	pdata = set_pdata(paths, avail_paths);
	if (!pdata)
		return (NULL);
	sort_paths_ascii(pdata, avail_paths);
	if (option.sort_time == true)
		sort_paths_time(pdata, avail_paths);
	else if (option.sort_size == true)
		sort_paths_size(pdata, avail_paths);
	return (pdata);
}

static t_pdata	*set_pdata(char **paths, int avail_paths)
{
	int		i;
	int		j;
	DIR		*dir;
	t_pdata	*pdata;

	pdata = (t_pdata *)malloc(avail_paths * sizeof(t_pdata));
	if (!pdata)
		return (NULL);
	i = 0;
	j = 0;
	while (i < avail_paths)
	{
		dir = opendir(paths[j]);
		if (dir != NULL)
		{
			pdata[i].name = paths[j];
			lstat(paths[j], &pdata[i].info);
			i++;
			closedir(dir);
		}
		j++;
	}
	return (pdata);
}

static void	sort_paths_ascii(t_pdata *pdata, int avail_paths)
{
	int	i;
	int	j;

	i = 0;
	while (i < avail_paths - 1)
	{
		j = avail_paths - 1;
		while (j > i)
		{
			if (ft_strcmp(pdata[j - 1].name, pdata[j].name) > 0)
				swap_pdata(pdata, j);
			j--;
		}
		i++;
	}
}

static void	sort_paths_time(t_pdata *pdata, int avail_paths)
{
	int	i;
	int	j;

	i = 0;
	while (i < avail_paths - 1)
	{
		j = avail_paths - 1;
		while (j > i)
		{
			if (pdata[j - 1].info.st_ctime < pdata[j].info.st_ctime)
				swap_pdata(pdata, j);
			else if (pdata[j - 1].info.st_ctime == pdata[j].info.st_ctime \
				&& ft_strcmp(pdata[j - 1].name, pdata[j].name) > 0)
				swap_pdata(pdata, j);
			j--;
		}
		i++;
	}
}

static void	sort_paths_size(t_pdata *pdata, int avail_paths)
{
	int	i;
	int	j;

	i = 0;
	while (i < avail_paths - 1)
	{
		j = avail_paths - 1;
		while (j > i)
		{
			if (pdata[j - 1].info.st_size < pdata[j].info.st_size)
				swap_pdata(pdata, j);
			else if (pdata[j - 1].info.st_size == pdata[j].info.st_size)
				if (ft_strcmp(pdata[j - 1].name, pdata[j].name) > 0)
					swap_pdata(pdata, j);
			j--;
		}
		i++;
	}
}

static void	swap_pdata(t_pdata *pdata, int j)
{
	t_pdata	tmp_pdata;

	tmp_pdata = pdata[j - 1];
	pdata[j - 1] = pdata[j];
	pdata[j] = tmp_pdata;
}
