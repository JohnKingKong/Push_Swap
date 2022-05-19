/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 14:55:19 by jvigneau          #+#    #+#             */
/*   Updated: 2022/05/19 14:28:35 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <string.h>
# include <limits.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include "../libs/libft/libft.h"

typedef struct s_vars
{
	int	temp;
	int	biggest;
	int	smallest;
	int	*list;
	int	nbargs;
	int	culprit;
	int	median;
	int	median_pos;
	int	chunk_piece;
}				t_vars;

typedef struct s_error
{
	char	*errorlog;
	int		err_no;
}				t_error;

typedef struct s_lists
{
	t_vars	list_a;
	t_vars	list_b;
	t_vars	list_c;
	t_vars	temp;
	t_error	error;
}				t_lists;

void	print_err(char *errorlog, int err_no);
int		check_doubles(t_lists *lists);
int		check_doubles_noq(t_lists *lists);
int		init_vars(t_lists *lists, int ac, char *av[]);
int		free_n_exit(t_lists *lists, int *list, int err_no);
void	keep_noq(t_lists *lists, int j, int *list);
void	keep_check(t_lists *lists, int j, int *list);
int		check_char(char **list, int i, t_lists *lists);
int		quotes(t_lists *lists, char *av[]);
int		free_this_list(int i, char **list);
int		minus_nowhere(char **list, int i, int j, t_lists *lists);
int		no_quotes(t_lists *lists, int ac, char **av);
int		check_char_no_q(t_lists *lists, char **av, int i);
int		minus_nowhere_no_q(char **av, int i, int j, t_lists *lists);
int		pa(t_lists *lists, int i);
int		pb(t_lists *lists, int i);
int		print_a(t_lists *lists);
int		print_b(t_lists *lists);
int		print_c(t_lists *lists);
int		print_real_c(t_lists *lists);
int		sa(t_lists *lists, int i);
int		sb(t_lists *lists, int i);
int		ss(t_lists *lists, int i);
int		ra(t_lists *lists, int c);
int		rb(t_lists *lists, int c);
int		rr(t_lists *lists, int c);
int		rra(t_lists *lists, int c);
int		rrb(t_lists *lists, int c);
int		rrr(t_lists *lists, int c);
int		get_extreme(t_lists *lists);
int		pos_wanted(t_lists *lists);
int		check_if_sorted(t_lists *lists);
int		three_num(t_lists *lists);
int		five_num(t_lists *lists);
int		keep_fiving(t_lists *lists);
int		keep_pos_want(t_lists *lists);
int		get_median(t_lists *lists, char c);
int		prep_biggo(t_lists *lists);
int		copycat(t_lists *lists);
void	continue_pb(t_lists *lists);
void	continue_pa(t_lists *lists);
int		minecraft(t_lists *lists);
int		minecraft_sequel(t_lists *lists);
int		minecraft_chunk_verfifier(t_lists *lists);
void	which_way(t_lists *lists, int v, int w);
void	minecraft_chunk_getter(t_lists *lists);
void	killing_the_dragon(t_lists *lists, int i, int j);
int		start_the_small(t_lists *lists);
int		start_the_wanted(t_lists *lists);
int		check_2(t_lists *lists);
int		five_and_less(t_lists *lists);

//bonus
void	operation_bing_bong(t_lists *lists, char *bing);
void	s_n_ps(t_lists *lists, char *bing);
int		init_vars_2(t_lists *lists, int ac, char *av[]);
void	keep_noq_2(t_lists *lists, int j, int *list);
int		free_n_exit_2(t_lists *lists, int *list, int err_no);
int		check_doubles_noq_2(t_lists *lists);
int		no_quotes_2(t_lists *lists, int ac, char **av);
int		check_char_no_q_2(t_lists *lists, char **av, int i);
int		minus_nowhere_no_q_2(char **list, int i, int j, t_lists *lists);
int		quotes_2(t_lists *lists, char *av[]);
int		free_this_list_2(int i, char **list);
int		check_char_2(char **list, int i, t_lists *lists);
int		minus_nowhere_2(char **list, int i, int j, t_lists *lists);
int		check_doubles_2(t_lists *lists);
void	keep_check_2(t_lists *lists, int j, int *list);
int		prep_biggo_2(t_lists *lists);
int		copycat_2(t_lists *lists);
void	print_err_2(char *errorlog, int err_no);

#endif