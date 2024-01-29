/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamasaw <syamasaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 15:01:58 by syamasaw          #+#    #+#             */
/*   Updated: 2024/01/29 19:20:00 by syamasaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mini_ls_bonus.h"

//if fd=2,return 1. if fd=1,return 0.
int	ft_putstr_fd(const char *str, int fd)
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

//Count the number of paths.
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

/*
Pass a string and return true if it is a valid option,
or false if it is a path.
*/
bool	is_valid_option(char *arg)
{
	int	i;

	if (arg[0] == '-' && strlen(arg) > 1)
	{
		i = 1;
		while (arg[i] != '\0')
		{
			if (strchr(AVAILABLE_OPTIONS, arg[i]) == NULL)
				return (false);
			i++;
		}
	}
	else
		return (false);
	return (true);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*de;
	const unsigned char	*sr;

	de = (unsigned char *)dest;
	sr = (unsigned char *)src;
	while (n--)
		*de++ = *sr++;
	return (dest);
}
