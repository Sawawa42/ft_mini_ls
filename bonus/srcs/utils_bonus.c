/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamasaw <syamasaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 15:01:58 by syamasaw          #+#    #+#             */
/*   Updated: 2024/02/09 19:40:00 by syamasaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_mini_ls_bonus.h"

/*
if fd=2,return 1. if fd=1,return 0.
*/
int	putstr_fd(const char *str, int fd)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(fd, &str[i], 1);
		i++;
	}
	return (fd - 1);
}

/*
Count the number of paths.
*/
int	count_paths(int argc, char *argv[])
{
	int	i;
	int	type;

	i = 1;
	while (i < argc)
	{
		type = is_valid_option(argv[i]);
		if (type == 0)
			return (argc - i);
		else if (type == -1)
			return (-1);
		i++;
	}	
	return (0);
}

/*
Returns 1 for a valid option, -1 for an invalid option, 
and 0 for a path.
*/
int	is_valid_option(char *arg)
{
	int	i;

	if (arg[0] == '-' && ft_strlen(arg) > 1)
	{
		i = 1;
		while (arg[i] != '\0')
		{
			if (ft_strchr(AVAILABLE_OPTIONS, arg[i]) == NULL)
				return (-1);
			i++;
		}
	}
	else
		return (0);
	return (1);
}

/*
Join two strings separated by "/".
*/
char	*pathjoin(char const *s1, char const *s2)
{
	size_t	lens1;
	size_t	lens2;
	char	*s1s2;

	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	s1s2 = (char *)malloc((lens1 + lens2 + 2) * sizeof(char));
	if (s1s2 == NULL)
		return (NULL);
	ft_memcpy(s1s2, s1, lens1);
	ft_memcpy(s1s2 + lens1, "/", 1);
	ft_memcpy(s1s2 + lens1 + 1, s2, lens2 + 1);
	return (s1s2);
}
