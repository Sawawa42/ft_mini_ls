/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamasaw <syamasaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:42:42 by syamasaw          #+#    #+#             */
/*   Updated: 2024/02/05 15:04:01 by syamasaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_mini_ls_bonus.h"

//-1trGUm
//-1 oneline, -m comma -> put時に操作
//-r rev -> ファイルディレクトリ、パスどちらも並べ替えが走る

//sort関数
//デフォでアルファベット順(オプションなしls)
//-tで最終変更時刻順(最近のものが上)
//-rで逆順にする

//putstr
//-Gで着色
//-aで隠しファイルも表示
//-1で1列にする or -mでカンマ区切りにする
//-1や-mでなければ、ファイルまたはディレクトリ名のうち最も長いものを基準にスペースを入れ、横5個ごとに整列
//この数は環境変数COLUMNS(横幅)を元に可能な限り多くのファイルを詰め込めるように計算される(らしい)
//mainに第三引数envpをつけて取得？
//この環境変数はない。ウィンドウサイズに応じて変わるっぽい
//許可された関数以外じゃなきゃウィンドゥサイズは取得できない。

//lsはデフォで-Cがついてる(マルチカラム表示)
//ls -lの結果が上から123...ならls -Cは
//1 3 5 7
//2 4 6 8
//となる。-xの場合
//1 2 3 4
//5 6 7 8
//となる
//man lsによれば、1行1エントリがデフォルトらしい。デフォ-C適用は特殊な仕様か？
//-Sと-tを同時使用する場合、順番に関わらずSが優先される。

static void	sort_ascii(t_data *data, int num_of_segments);
static void	sort_time(t_data *data, int num_of_segments);
static void	sort_size(t_data *data, int num_of_segments);
static void	swap_data(t_data *data, int j);

void	sort_files_and_dirs(t_data *data, int num_of_segments, t_options option)
{
	sort_ascii(data, num_of_segments);
	if (option.sort_time == true)
		sort_time(data, num_of_segments);
	else if (option.sort_size == true)
		sort_size(data, num_of_segments);
}

static void	sort_ascii(t_data *data, int num_of_segments)
{
	int	i;
	int	j;

	i = 0;
	while (i < num_of_segments - 1)
	{
		j = num_of_segments - 1;
		while (j > i)
		{
			if (ft_strcmp(data[j - 1].name, data[j].name) > 0)
				swap_data(data, j);
			j--;
		}
		i++;
	}
}

static void	sort_time(t_data *data, int num_of_segments)
{
	int	i;
	int	j;

	i = 0;
	while (i < num_of_segments - 1)
	{
		j = num_of_segments - 1;
		while (j > i)
		{
			if (data[j - 1].last_update < data[j].last_update)
				swap_data(data, j);
			else if (data[j - 1].last_update == data[j].last_update \
				&& ft_strcmp(data[j - 1].name, data[j].name) > 0)
				swap_data(data, j);
			j--;
		}
		i++;
	}
}

static void	sort_size(t_data *data, int num_of_segments)
{
	int	i;
	int	j;

	i = 0;
	while (i < num_of_segments - 1)
	{
		j = num_of_segments - 1;
		while (j > i)
		{
			if (data[j - 1].info.st_size < data[j].info.st_size)
				swap_data(data, j);
			j--;
		}
		i++;
	}
}

static void	swap_data(t_data *data, int j)
{
	t_data	tmp_data;

	tmp_data = data[j - 1];
	data[j - 1] = data[j];
	data[j] = tmp_data;
}
