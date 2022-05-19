/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 15:29:34 by jvigneau          #+#    #+#             */
/*   Updated: 2022/05/19 14:04:14 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	init_vars(t_lists *lists, int ac, char *av[])
{
	lists->list_a.nbargs = 0;
	lists->list_b.nbargs = 0;
	lists->list_c.nbargs = 0;
	lists->temp.nbargs = 0;
	lists->list_a.chunk_piece = 0;
	lists->list_a.smallest = INT_MAX;
	lists->list_a.biggest = INT_MIN;
	if (ac == 1)
		return (0);
	if (ac == 2)
		quotes(lists, av);
	else if (ac > 2)
		no_quotes(lists, ac, av);
	get_extreme(lists);
	get_extreme(lists);
	return (true);
}

int	check_2(t_lists *lists)
{
	if (lists->list_a.nbargs == 2)
	{
		if (lists->list_a.smallest == lists->list_a.list[0])
		{
			free(lists->list_a.list);
			exit (0);
		}
		sa(lists, 1);
		free(lists->list_a.list);
		exit (0);
	}
	if (check_if_sorted(lists) == 0)
	{
		free(lists->list_a.list);
		exit (0);
	}
	return (0);
}
