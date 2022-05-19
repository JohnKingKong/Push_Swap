/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 15:41:38 by jvigneau          #+#    #+#             */
/*   Updated: 2022/05/19 15:00:42 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

int	pos_wanted(t_lists *lists)
{
	int	i;

	i = 0;
	start_the_wanted(lists);
	while (i < lists->list_a.nbargs)
	{	
		lists->list_a.list[i] = lists->list_c.list[i];
		i++;
		lists->list_c.nbargs--;
	}
	free(lists->list_c.list);
	lists->list_c.list = ft_calloc(lists->list_a.nbargs, sizeof(t_lists));
	if (!lists->list_c.list)
		return (1);
	lists->list_c.nbargs = 0;
	return (0);
}

int	keep_pos_want(t_lists *lists)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	lists->temp.list = ft_calloc(lists->list_a.nbargs, sizeof(t_lists));
	while (lists->temp.nbargs < lists->list_a.nbargs)
	{
		get_extreme(lists);
		if (lists->list_a.list[i] == lists->list_a.smallest)
		{
			lists->temp.list[j] = lists->list_a.list[i];
			lists->list_a.list[i] = INT_MAX;
			lists->list_a.smallest = INT_MAX;
			lists->list_a.biggest = INT_MIN;
			lists->temp.nbargs++;
			j++;
			i = 0;
			continue ;
		}
		i++;
	}
	get_median(lists, 'a');
	return (0);
}

int	get_median(t_lists *lists, char c)
{
	int	i;

	i = 0;
	if (c == 'a')
	{
		if (lists->list_a.nbargs % 2 == 0)
			lists->temp.median = lists->list_a.nbargs / 2 - 1;
		else
			lists->temp.median = lists->list_a.nbargs / 2;
	}
	else if (c == 'b')
	{
		if (lists->list_b.nbargs <= 0)
			return (0);
		if (lists->list_b.nbargs % 2 == 0)
			lists->temp.median = lists->list_b.nbargs / 2 - 1;
		else
			lists->temp.median = lists->list_b.nbargs / 2;
	}
	return (0);
}

int	start_the_wanted(t_lists *lists)
{
	int	i;

	i = 0;
	if (!lists->list_c.list)
	{
		lists->list_c.list = ft_calloc(lists->list_a.nbargs, sizeof(int));
		if (!lists->list_c.list)
			return (1);
	}
	while (i < lists->list_a.nbargs)
	{
		lists->list_c.list[i] = lists->list_a.list[i];
		i++;
		lists->list_c.nbargs++;
	}
	keep_pos_want(lists);
	return (0);
}
