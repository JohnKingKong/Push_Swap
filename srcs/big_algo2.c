/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_algo2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 12:14:21 by jvigneau          #+#    #+#             */
/*   Updated: 2022/05/18 12:22:03 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	minecraft_sequel(t_lists *lists)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (j < lists->temp.nbargs)
	{
		if (lists->list_b.nbargs == 2)
		{
			pa(lists, 1);
			pa(lists, 1);
			return (0);
		}
		while (lists->list_b.list[i]
			!= lists->temp.list[lists->temp.nbargs - j])
			i++;
		killing_the_dragon(lists, i, j);
		pa(lists, 1);
		i = 0;
		j++;
		get_median(lists, 'b');
	}	
	return (0);
}

void	killing_the_dragon(t_lists *lists, int i, int j)
{
	if (i > lists->temp.median)
	{
		while (lists->list_b.list[0]
			!= lists->temp.list[lists->temp.nbargs - j])
			rrb(lists, 1);
	}
	else if (i <= lists->temp.median)
	{
		while (lists->list_b.list[0]
			!= lists->temp.list[lists->temp.nbargs - j])
			rb(lists, 1);
	}
}
