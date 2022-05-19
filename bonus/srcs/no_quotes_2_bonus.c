/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_quotes_2_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 12:18:53 by jvigneau          #+#    #+#             */
/*   Updated: 2022/05/19 14:57:28 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

int	no_quotes_2(t_lists *lists, int ac, char **av)
{
	int	i;

	i = 1;
	lists->list_a.list = ft_calloc((ac - 1), sizeof(int));
	if (!lists->list_a.list)
		return (1);
	lists->list_a.nbargs = ac - 1;
	while (i < ac)
	{
		check_char_no_q_2(lists, av, i);
		lists->list_a.list[i - 1] = ft_atoi(av[i]);
		i++;
	}
	check_doubles_noq_2(lists);
	return (0);
}

int	check_char_no_q_2(t_lists *lists, char **av, int i)
{
	int	j;

	j = 0;
	while (av[i][j])
	{
		while (av[i][j] == '\t' || av[i][j] == '\n' || av[i][j] == '\v'
			|| av[i][j] == '\f' || av[i][j] == '\r' || av[i][j] == ' ')
			j++;
		if (av[i][j] == '-')
		{
			minus_nowhere_no_q_2(av, i, j, lists);
			j++;
		}
		if (av[i][j] >= 48 && av[i][j] <= 57)
			j++;
		else
		{
			print_err_2("There is a char in the int list!", 1);
			free(lists->list_a.list);
			exit (1);
		}
	}
	return (0);
}

int	minus_nowhere_no_q_2(char **list, int i, int j, t_lists *lists)
{
	if (list[i][j] == '-' && j != 0)
	{
		print_err_2("There is a - in the middle of an int", 1);
		free(lists->list_a.list);
		exit (1);
	}
	return (0);
}
