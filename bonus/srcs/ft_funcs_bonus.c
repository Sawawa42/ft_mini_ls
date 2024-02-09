/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_funcs_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamasaw <syamasaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:24:36 by syamasaw          #+#    #+#             */
/*   Updated: 2024/02/09 13:20:15 by syamasaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_mini_ls_bonus.h"

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

char	*ft_strchr(const char *s, int c)
{
	while (*s != (char)c)
	{
		if ((*s == '\0') && ((char)c == '\0'))
			return ((char *)s);
		if (*s == '\0')
			return (NULL);
		s++;
	}
	return ((char *)s);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
