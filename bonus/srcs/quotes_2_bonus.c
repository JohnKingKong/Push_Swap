/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_quotes_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 12:18:41 by jvigneau          #+#    #+#             */
/*   Updated: 2022/05/19 13:09:08 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

void	keep_check_2(t_lists *lists, int j, int *list)
{
	int	i;

	i = j + 1;
	while (i < lists->list_a.nbargs)
	{
		if (list[j] == lists->list_a.list[i])
		{	
			free(list);
			free_n_exit_2(lists, list, 2);
			exit (1);
		}
		i++;
	}
}
