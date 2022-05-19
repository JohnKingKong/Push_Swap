/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 12:26:38 by jvigneau          #+#    #+#             */
/*   Updated: 2022/05/19 14:58:08 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

int	ra(t_lists *lists, int c)
{
	int	i;

	i = 0;
	if (lists->list_a.nbargs <= 2)
		return (0);
	lists->list_b.temp = lists->list_a.list[i];
	while (i < lists->list_a.nbargs)
	{
		lists->list_a.list[i] = lists->list_a.list[i + 1];
		i++;
	}
	lists->list_a.list[i - 1] = lists->list_b.temp;
	if (c == 1)
		printf("ra\n");
	return (0);
}

int	rb(t_lists *lists, int c)
{
	int	i;

	i = 0;
	if (lists->list_b.nbargs <= 2)
		return (0);
	lists->list_b.temp = lists->list_b.list[i];
	while (i < lists->list_b.nbargs)
	{
		lists->list_b.list[i] = lists->list_b.list[i + 1];
		i++;
	}
	lists->list_b.list[i - 1] = lists->list_b.temp;
	if (c == 1)
		printf("rb\n");
	return (0);
}

int	rr(t_lists *lists, int c)
{
	if (lists->list_a.nbargs <= 2 || lists->list_b.nbargs <= 2)
		return (0);
	ra(lists, 0);
	rb(lists, 0);
	if (c == 1)
		printf("rr\n");
	return (0);
}
