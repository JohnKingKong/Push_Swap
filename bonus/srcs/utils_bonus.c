/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 13:09:41 by jvigneau          #+#    #+#             */
/*   Updated: 2022/05/19 15:33:24 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

void	operation_bing_bong(t_lists *lists, char *bing)
{
	while (bing != NULL && bing[0] != '\n')
	{
		if (!ft_strncmp(bing, "rra", 3))
			rra(lists, 0);
		else if (!ft_strncmp(bing, "rrb", 3))
			rrb(lists, 0);
		else if (!ft_strncmp(bing, "rrr", 3))
			rrr(lists, 0);
		else if (!ft_strncmp(bing, "ra", 2))
			ra(lists, 0);
		else if (!ft_strncmp(bing, "rb", 2))
			rb(lists, 0);
		else if (!ft_strncmp(bing, "rr", 2))
			rr(lists, 0);
		else
			s_n_ps(lists, bing);
		free(bing);
		bing = get_next_line(0);
	}
}

void	s_n_ps(t_lists *lists, char *bing)
{
	if (!ft_strncmp(bing, "sa", 2))
		sa(lists, 0);
	else if (!ft_strncmp(bing, "sb", 2))
		sb(lists, 0);
	else if (!ft_strncmp(bing, "ss", 2))
		ss(lists, 0);
	else if (!ft_strncmp(bing, "pa", 2))
		pa(lists, 0);
	else if (!ft_strncmp(bing, "pb", 2))
		pb (lists, 0);
}
