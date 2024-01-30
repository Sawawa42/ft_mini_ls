/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamasaw <syamasaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 20:55:49 by syamasaw          #+#    #+#             */
/*   Updated: 2024/01/24 13:29:17 by syamasaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mini_ls.h"

DIR	*wrapper_opendir(const char *path)
{
	DIR	*ret_dir_ptr;

	ret_dir_ptr = opendir(path);
	if (ret_dir_ptr == NULL)
	{
		ft_putstr_fd(OPENDIR_ERROR, 2);
		return (NULL);
	}
	return (ret_dir_ptr);
}

void	ft_putstr_fd(const char *str, int fd)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(fd, &str[i], 1);
		i++;
	}
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;
	unsigned char	*cast_s1;
	unsigned char	*cast_s2;

	i = 0;
	cast_s1 = (unsigned char *)s1;
	cast_s2 = (unsigned char *)s2;
	while (cast_s1[i] == cast_s2[i] && cast_s1[i] != '\0' && cast_s2[i] != '\0')
	{
		i++;
	}
	return (cast_s1[i] - cast_s2[i]);
}
