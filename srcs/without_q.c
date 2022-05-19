/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   without_q.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 10:58:32 by jvigneau          #+#    #+#             */
/*   Updated: 2022/05/04 14:36:46 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	keep_noq(t_lists *lists, int j, int *list)
{
	int	i;

	i = j + 1;
	while (i < lists->list_a.nbargs)
	{
		if (list[j] == lists->list_a.list[i])
		{	
			lists->list_a.culprit = list[j];
			free(list);
			free_n_exit(lists, list, 2);
			exit (1);
		}
		i++;
	}
}

int	free_n_exit(t_lists *lists, int *list, int err_no)
{
	char	*errorlog;

	errorlog = NULL;
	if (err_no == 2)
		errorlog = "There is a duplicate in the list!!";
	print_err(errorlog, err_no);
	if (err_no == 2)
		printf("Culprit : %d\n\n", lists->list_a.culprit);
	list = 0;
	free(list);
	free(lists->list_a.list);
	return (true);
}

void	print_err(char *errorlog, int err_no)
{
	printf("\n\nERROR!!\n\n%s\n\n", errorlog);
	write(STDERR_FILENO, &err_no, 1);
}

int	check_doubles_noq(t_lists *lists)
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
		keep_noq(lists, j, list);
		j++;
	}
	free(list);
	return (0);
}
