/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   with_quotes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 11:23:35 by jvigneau          #+#    #+#             */
/*   Updated: 2022/05/13 11:39:26 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	quotes(t_lists *lists, char *av[])
{
	char	**list;
	int		listlen;
	int		i;

	listlen = 0;
	i = 0;
	list = ft_split(av[1], ' ');
	while (list[listlen])
		listlen++;
	lists->list_a.list = ft_calloc(listlen, sizeof(int));
	while (list[i])
	{
		check_char(list, i, lists);
		lists->list_a.list[i] = ft_atoi(list[i]);
		lists->list_a.nbargs++;
		i++;
	}
	check_doubles(lists);
	free_this_list(i, list);
	return (0);
}

int	free_this_list(int i, char **list)
{
	i--;
	while (i >= 0)
	{
		if (list[i] == NULL)
			break ;
		free(list[i]);
		i--;
	}
	free(list);
	return (0);
}

int	check_char(char **list, int i, t_lists *lists)
{
	int	j;

	j = 0;
	while (list[i][j])
	{
		if (list[i][j] == '-')
		{
			minus_nowhere(list, i, j, lists);
			j++;
		}
		if ((list[i][j] < 48) || (list[i][j] > 57))
		{
			lists->error.err_no = 1;
			free(list[i]);
			free(list);
			print_err("There is a char in the int list!", 1);
			free(lists->list_a.list);
			exit (2);
		}
		j++;
	}
	return (0);
}

int	minus_nowhere(char **list, int i, int j, t_lists *lists)
{
	if (list[i][j] == '-' && j != 0)
	{
		lists->error.err_no = 1;
		free(list[i]);
		free(list);
		print_err("There is a - in the middle of an int", 1);
		free(lists->list_a.list);
		exit (1);
	}
	return (0);
}

int	check_doubles(t_lists *lists)
{
	int	j;
	int	*list;

	j = 0;
	list = malloc(lists->list_a.nbargs * sizeof(int));
	while (j < lists->list_a.nbargs)
	{
		list[j] = lists->list_a.list[j];
		j++;
	}
	j = 0;
	while (j < lists->list_a.nbargs)
	{
		keep_check(lists, j, list);
		j++;
	}
	free(list);
	return (0);
}
