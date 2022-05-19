/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 15:24:30 by jvigneau          #+#    #+#             */
/*   Updated: 2022/05/18 12:20:48 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	three_num(t_lists *lists)
{
	if (lists->list_a.list[0] == lists->list_a.biggest)
		ra(lists, 1);
	else if (lists->list_a.list[1] == lists->list_a.biggest)
		rra(lists, 1);
	if (check_if_sorted(lists) == 1)
		sa(lists, 1);
	return (0);
}

int	five_num(t_lists *lists)
{
	start_the_small(lists);
	if (check_if_sorted(lists) == 0)
		return (0);
	if (lists->list_a.nbargs == 3)
	{
		three_num(lists);
		pa(lists, 1);
		pa(lists, 1);
		return (0);
	}
	if (lists->list_a.list[0] == lists->list_a.smallest)
	{
		pb(lists, 1);
		five_num(lists);
	}
	else
		keep_fiving(lists);
	if (lists->list_a.nbargs < 5)
		pa(lists, 1);
	return (0);
}

int	keep_fiving(t_lists *lists)
{
	int	i;

	i = 0;
	while (i < lists->list_a.nbargs)
		i++;
	if (lists->list_a.list[i] == lists->list_a.smallest
		|| lists->list_a.list[i - 1] == lists->list_a.smallest
		|| lists->list_a.list[i - 2] == lists->list_a.smallest)
	{
		rra(lists, 1);
		five_num(lists);
	}
	else
	{
		ra(lists, 1);
		five_num(lists);
	}
	return (0);
}

int	start_the_small(t_lists *lists)
{
	if (!lists->list_b.list)
	{
		lists->list_b.list = ft_calloc(lists->list_a.nbargs, sizeof(int));
		if (!lists->list_b.list)
			return (1);
	}
	lists->list_a.smallest = INT_MAX;
	get_extreme(lists);
	return (0);
}
