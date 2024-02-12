/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_arg_paths_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamasaw <syamasaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 17:46:47 by syamasaw          #+#    #+#             */
/*   Updated: 2024/02/12 14:50:30 by syamasaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_mini_ls_bonus.h"

char	**set_arg_paths(int argc, char *argv[], int cnt_paths)
{
	char	**ret_paths;
	int		i;
	int		j;

	ret_paths = (char **)malloc(cnt_paths * sizeof(char *));
	if (ret_paths == NULL)
		return (puterror(MALLOC_ERROR));
	i = 1;
	while (is_valid_option(argv[i]) == 1)
		i++;
	j = 0;
	while (i < argc)
	{
		ret_paths[j] = (char *)malloc((ft_strlen(argv[i]) + 1) * sizeof(char));
		if (ret_paths[j] == NULL)
		{
			free_paths(ret_paths, j);
			return (NULL);
		}
		ft_memcpy(ret_paths[j], argv[i], ft_strlen(argv[i]) + 1);
		i++;
		j++;
	}
	return (ret_paths);
}
