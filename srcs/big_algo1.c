/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_algo1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 10:25:39 by jvigneau          #+#    #+#             */
/*   Updated: 2022/05/18 12:21:41 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	prep_biggo(t_lists *lists)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < lists->list_a.nbargs)
	{
		while (j < lists->temp.nbargs)
		{
			if (lists->list_a.list[i] == lists->temp.list[j])
			{
				lists->list_a.list[i] = j;
				break ;
			}
			j++;
		}
		j = 0;
		i++;
	}
	copycat(lists);
	minecraft(lists);
	if (lists->list_a.list[1] < lists->list_a.list[0])
		sa(lists, 1);
	return (0);
}

int	copycat(t_lists *lists)
{
	int	i;

	i = 0;
	lists->list_b.list = calloc(lists->list_a.nbargs, sizeof(int));
	lists->list_b.nbargs = 0;
	while (i < lists->list_a.nbargs)
	{
		lists->list_b.list[i] = lists->list_a.list[i];
		i++;
		lists->list_b.nbargs++;
	}
	lists->temp.nbargs = 0;
	free(lists->temp.list);
	pos_wanted(lists);
	free(lists->list_b.list);
	lists->list_b.nbargs = 0;
	lists->list_b.list = calloc(lists->list_a.nbargs, sizeof(int));
	get_extreme(lists);
	return (0);
}

int	minecraft(t_lists *lists)
{
	int	v;
	int	w;

	v = 0;
	w = 0;
	v = lists->temp.median;
	w = lists->temp.median;
	minecraft_chunk_getter(lists);
	while (lists->list_a.nbargs > 0)
	{
		v = v + lists->list_a.chunk_piece;
		w = w - lists->list_a.chunk_piece;
		which_way(lists, v, w);
	}
	minecraft_sequel(lists);
	return (0);
}

void	which_way(t_lists *lists, int v, int w)
{
	int	j;

	j = 0;
	while (j <= lists->list_a.nbargs)
	{
		if (lists->list_b.list[0] > lists->temp.median)
			rb(lists, 1);
		else if (lists->list_b.list[lists->list_b.nbargs - 1]
			< lists->temp.median)
			rrb(lists, 1);
		if (lists->list_b.list[1] < lists->list_b.list[0])
		{
			if (lists->list_a.list[1] < lists->list_a.list[0])
				sa(lists, 1);
			sb(lists, 1);
		}
		if (lists->list_a.list[0] >= w && lists->list_a.list[0] < v)
			pb(lists, 1);
		else
			ra(lists, 1);
		j++;
	}
}

void	minecraft_chunk_getter(t_lists *lists)
{
	if (lists->list_a.nbargs <= 10)
		lists->list_a.chunk_piece = 2;
	else if (lists->list_a.nbargs <= 20)
		lists->list_a.chunk_piece = 5;
	else if (lists->list_a.nbargs <= 100)
		lists->list_a.chunk_piece = 9;
	else
		lists->list_a.chunk_piece = 27;
}
