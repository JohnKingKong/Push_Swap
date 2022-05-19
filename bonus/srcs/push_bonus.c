/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 12:26:33 by jvigneau          #+#    #+#             */
/*   Updated: 2022/05/19 14:12:07 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

int	pb(t_lists *lists, int i)
{
	lists->list_b.temp = INT_MAX;
	if (lists->list_a.nbargs == 0)
		return (0);
	continue_pb(lists);
	lists->list_b.nbargs++;
	lists->list_a.nbargs--;
	lists->list_a.smallest = INT_MAX;
	lists->list_b.temp = INT_MAX;
	get_extreme(lists);
	if (i == 1)
		printf("pb\n");
	return (0);
}

void	continue_pb(t_lists *lists)
{
	int	i;

	i = 0;
	lists->list_a.temp = lists->list_b.list[i];
	lists->list_b.list[i] = lists->list_a.list[i];
	i++;
	while (i <= lists->temp.nbargs)
	{
		lists->list_b.temp = lists->list_b.list[i];
		lists->list_b.list[i] = lists->list_a.temp;
		lists->list_a.temp = lists->list_b.temp;
		i++;
	}
	lists->list_b.list[i] = lists->list_a.temp;
	i = 0;
	while (i < lists->list_a.nbargs)
	{
		lists->list_a.list[i] = lists->list_a.list[i + 1];
		i++;
	}
}

void	continue_pa(t_lists *lists)
{
	int	i;

	i = 0;
	lists->list_a.temp = lists->list_a.list[i];
	lists->list_a.list[i] = lists->list_b.list[i];
	i++;
	while (i <= lists->list_a.nbargs)
	{
		lists->list_b.temp = lists->list_a.list[i];
		lists->list_a.list[i] = lists->list_a.temp;
		lists->list_a.temp = lists->list_b.temp;
		i++;
	}
	i = 0;
	while (i <= lists->list_b.nbargs)
	{
		lists->list_b.list[i] = lists->list_b.list[i + 1];
		i++;
	}
}

int	pa(t_lists *lists, int i)
{
	if (lists->list_b.nbargs == 0)
		return (0);
	continue_pa(lists);
	lists->list_a.nbargs++;
	lists->list_b.nbargs--;
	lists->list_a.smallest = INT_MAX;
	get_extreme(lists);
	if (i == 1)
		printf("pa\n");
	return (0);
}
