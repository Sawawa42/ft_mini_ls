/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opendir_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamasaw <syamasaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:23:58 by syamasaw          #+#    #+#             */
/*   Updated: 2024/01/22 17:21:03 by syamasaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include <stdio.h>

// ./a.outだけだと、カレントディレクトリ、引数でパスを渡すとそのディレクトリ、のようにしている。
int	main(int argc, char *argv[])
{
	DIR				*dir;
	struct dirent	*dp;
	char			path[512];

	if (argc <= 1)
	{
		strcpy(path, ".");
	}
	else
	{
		strcpy(path, argv[1]);
	}
	if ((dir = opendir(path)) == NULL)
	{
		perror("opendir");
		exit(-1);
	}
	for (dp = readdir(dir); dp != NULL; dp = readdir(dir))
	{
		printf("%s\n", dp->d_name);
	}
	closedir(dir);
	return (0);
}