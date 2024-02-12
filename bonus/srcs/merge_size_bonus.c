/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_size_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamasaw <syamasaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 17:34:24 by syamasaw          #+#    #+#             */
/*   Updated: 2024/02/12 19:20:51 by syamasaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_mini_ls_bonus.h"

static void	merge_sort(t_data *data, t_data *work, t_var vars);
static void	push_data(t_data *data, t_data *work, t_var vars);

bool	merge_sort_size(t_data *data, int len_of_data)
{
	t_data	*work;
	t_var	vars;

	work = (t_data *)malloc(len_of_data * sizeof(t_data));
	if (!work)
	{
		puterror(MALLOC_ERROR);
		return (false);
	}
	vars.right = len_of_data - 1;
	vars.left = 0;
	merge_sort(data, work, vars);
	free(work);
	return (true);
}

static void	merge_sort(t_data *data, t_data *work, t_var vars)
{
	int	i;
	int	j;
	int	mid;
	int	tmp;

	if (vars.left < vars.right)
	{
		mid = (vars.left + vars.right) / 2;
		tmp = vars.right;
		vars.right = mid;
		merge_sort(data, work, vars);
		vars.right = tmp;
		tmp = vars.left;
		vars.left = mid + 1;
		merge_sort(data, work, vars);
		vars.left = tmp;
		i = mid + 1;
		while (--i >= vars.left)
			work[i] = data[i];
		j = mid;
		while (++j <= vars.right)
			work[vars.right - (j - (mid + 1))] = data[j];
		push_data(data, work, vars);
	}
}

static void	push_data(t_data *data, t_data *work, t_var vars)
{
	int	i;
	int	j;
	int	k;

	i = vars.left;
	j = vars.right;
	k = vars.left - 1;
	while (++k <= vars.right)
	{
		if (work[i].info.st_size < work[j].info.st_size)
			data[k] = work[j--];
		else if (work[i].info.st_size == work[j].info.st_size)
		{
			if (ft_strcmp(work[i].name, work[j].name) < 0)
				data[k] = work[i++];
			else
				data[k] = work[j--];
		}
		else
			data[k] = work[i++];
	}
}
