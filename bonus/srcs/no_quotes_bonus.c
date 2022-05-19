/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_no_quotes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 10:58:32 by jvigneau          #+#    #+#             */
/*   Updated: 2022/05/19 14:27:45 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

void	keep_noq_2(t_lists *lists, int j, int *list)
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

int	free_n_exit_2(t_lists *lists, int *list, int err_no)
{
	char	*errorlog;

	errorlog = NULL;
	if (err_no == 2)
		errorlog = "There is a duplicate in the list!!";
	print_err_2(errorlog, err_no);
	list = 0;
	free(list);
	free(lists->list_a.list);
	return (true);
}

void	print_err_2(char *errorlog, int err_no)
{
	printf("\n\nERROR!!\n\n%s\n\n", errorlog);
	write(STDERR_FILENO, &err_no, 1);
}

int	check_doubles_noq_2(t_lists *lists)
{
	int	j;
	int	*list;

	j = 0;
	list = ft_calloc(lists->list_a.nbargs, sizeof(int));
	while (j < lists->list_a.nbargs)
	{
		list[j] = lists->list_a.list[j];
		j++;
	}
	j = 0;
	while (j < lists->list_a.nbargs)
	{
		keep_noq_2(lists, j, list);
		j++;
	}
	free(list);
	return (0);
}
