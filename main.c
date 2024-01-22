/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamasaw <syamasaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:53:30 by syamasaw          #+#    #+#             */
/*   Updated: 2024/01/22 17:34:06 by syamasaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include <stdio.h>
#include <string.h>

int	main(int argc, char *argv[])
{
	if (argc != 1)
	{
		strerror(2);
		perror(strerror(2));
	}
	return (1);
}
