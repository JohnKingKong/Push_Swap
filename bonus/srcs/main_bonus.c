/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 13:09:36 by jvigneau          #+#    #+#             */
/*   Updated: 2022/05/19 14:59:49 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

int	main(int ac, char *av[])
{
	t_lists	lists;
	char	*bing;
	int		i;

	i = 0;
	init_vars_2(&lists, ac, av);
	pos_wanted(&lists);
	prep_biggo_2(&lists);
	bing = get_next_line(0);
	operation_bing_bong(&lists, bing);
	if (check_if_sorted(&lists) == 0)
	{
		if (lists.list_b.nbargs == 0)
			printf("Ok\n");
	}
	else
		printf("KO\n");
	free(lists.list_a.list);
	free(lists.list_b.list);
	free(lists.list_c.list);
	free(lists.temp.list);
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

int	prep_biggo_2(t_lists *lists)
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
	copycat_2(lists);
	return (0);
}

int	copycat_2(t_lists *lists)
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
