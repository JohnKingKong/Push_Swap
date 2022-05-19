/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 11:59:55 by jvigneau          #+#    #+#             */
/*   Updated: 2022/05/18 15:58:38 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int ac, char *av[])
{
	t_lists	lists;
	int		i;

	i = 0;
	init_vars(&lists, ac, av);
	check_2(&lists);
	five_and_less(&lists);
	pos_wanted(&lists);
	prep_biggo(&lists);
	free(lists.list_b.list);
	free(lists.list_a.list);
	free(lists.list_c.list);
	free(lists.temp.list);
	return (0);
}

int	five_and_less(t_lists *lists)
{
	if (lists->list_a.nbargs == 3)
	{
		three_num(lists);
		free(lists->list_a.list);
		exit (0);
	}	
	if (lists->list_a.nbargs <= 5)
	{
		five_num(lists);
		free(lists->list_a.list);
		free(lists->list_b.list);
		exit (0);
	}
	return (0);
}

int	check_if_sorted(t_lists *lists)
{
	int	i;

	i = 1;
	while (i < lists->list_a.nbargs - 1)
	{
		if (lists->list_a.list[i] < lists->list_a.list[i + 1]
			&& lists->list_a.list[i] > lists->list_a.list[i - 1])
			i++;
		else
			return (1);
	}
	return (0);
}

int	get_extreme(t_lists *lists)
{
	int	i;

	i = 0;
	while (i < lists->list_a.nbargs)
	{
		if (lists->list_a.smallest > lists->list_a.list[i])
			lists->list_a.smallest = lists->list_a.list[i];
		else if (lists->list_a.biggest < lists->list_a.list[i])
			lists->list_a.biggest = lists->list_a.list[i];
		i++;
	}
	return (0);
}
