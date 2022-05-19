/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 12:28:28 by jvigneau          #+#    #+#             */
/*   Updated: 2022/05/17 11:01:09 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	print_a(t_lists *lists)
{
	int	i;

	printf("LIST A :\n");
	i = 0;
	while (i < lists->list_a.nbargs)
	{
		printf("position %d : %d\n", i, lists->list_a.list[i]);
		i++;
	}
	return (0);
}

int	print_b(t_lists *lists)
{
	int	i;

	printf("LIST B :\n");
	i = 0;
	while (i < lists->list_b.nbargs)
	{
		printf("position %d : %d\n", i, lists->list_b.list[i]);
		i++;
	}
	return (0);
}

int	print_c(t_lists *lists)
{
	int	i;

	printf("LIST temp :\n");
	i = 0;
	while (i < lists->temp.nbargs)
	{
		printf("position %d : %d\n", i, lists->temp.list[i]);
		i++;
	}
	return (0);
}
