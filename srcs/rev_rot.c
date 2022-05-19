/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 12:26:46 by jvigneau          #+#    #+#             */
/*   Updated: 2022/05/18 12:16:39 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	rra(t_lists *lists, int c)
{
	int	i;

	if (lists->list_a.nbargs <= 2)
		return (0);
	i = lists->list_a.nbargs - 1;
	lists->list_a.temp = lists->list_a.list[i];
	while (i > 0)
	{
		lists->list_a.list[i] = lists->list_a.list[i - 1];
		i--;
	}
	lists->list_a.list[i] = lists->list_a.temp;
	if (c == 1)
		printf("rra\n");
	return (0);
}

int	rrb(t_lists *lists, int c)
{
	int	i;

	if (lists->list_b.nbargs <= 2)
		return (0);
	i = lists->list_b.nbargs - 1;
	lists->list_b.temp = lists->list_b.list[i];
	while (i > 0)
	{
		lists->list_b.list[i] = lists->list_b.list[i - 1];
		i--;
	}
	lists->list_b.list[i] = lists->list_b.temp;
	if (c == 1)
		printf("rrb\n");
	return (0);
}

int	rrr(t_lists *lists, int c)
{
	if (lists->list_a.nbargs <= 2 || lists->list_b.nbargs <= 2)
		return (0);
	rra(lists, 0);
	rrb(lists, 0);
	if (c == 1)
		printf("rrr\n");
	return (0);
}
