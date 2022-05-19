/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 12:26:21 by jvigneau          #+#    #+#             */
/*   Updated: 2022/05/19 14:58:05 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

int	sa(t_lists *lists, int i)
{
	if (lists->list_a.nbargs <= 1)
		return (0);
	lists->list_a.temp = lists->list_a.list[0];
	lists->list_a.list[0] = lists->list_a.list[1];
	lists->list_a.list[1] = lists->list_a.temp;
	if (i == 1)
		printf("sa\n");
	return (0);
}

int	sb(t_lists *lists, int i)
{
	if (lists->list_b.nbargs <= 1)
		return (0);
	lists->list_b.temp = lists->list_b.list[0];
	lists->list_b.list[0] = lists->list_b.list[1];
	lists->list_b.list[1] = lists->list_b.temp;
	if (i == 1)
		printf("sb\n");
	return (0);
}

int	ss(t_lists *lists, int i)
{
	if (lists->list_a.nbargs <= 1 || lists->list_b.nbargs <= 1)
		return (0);
	sa(lists, 0);
	sb(lists, 0);
	if (i == 1)
		printf("ss\n");
	return (0);
}
