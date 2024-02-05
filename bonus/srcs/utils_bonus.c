/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamasaw <syamasaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 15:01:58 by syamasaw          #+#    #+#             */
/*   Updated: 2024/02/05 15:17:47 by syamasaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_mini_ls_bonus.h"

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

//パスの後に書かれたオプションは有効無効関わらずパスとして扱う
//先頭が-であるものはパスとして扱い、無効ならusage error
//ls -l . -2 or ls -l -2 .(usage error)のように、最後のオプション

/*
Pass a string and return true if it is a valid option,
or false if it is a path.
*/
int	is_valid_option(char *arg)
{
	int	i;

	if (arg[0] == '-' && strlen(arg) > 1)
	{
		i = 1;
		while (arg[i] != '\0')
		{
			if (strchr(AVAILABLE_OPTIONS, arg[i]) == NULL)
				return (-1);//-かつ存在しないオプション, -1
			i++;
		}
	}
	else
		return (0);//-ではない、パスにあたる, 0
	return (1);//オプションである, 1
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
