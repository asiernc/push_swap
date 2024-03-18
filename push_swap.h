/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 15:14:07 by anovio-c          #+#    #+#             */
/*   Updated: 2024/03/05 11:33:44 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>

typedef struct t_stack
{
	int				content;
	int				to_up;
	int				cheapest;
	int				sign;
	struct t_stack	*previous;
	struct t_stack	*next;
}				t_stack;

// Formatter y check args

char		**ft_formatter(int argc, char **argv);
char		**ft_parse(int argc, char **argv);
int			ft_check_args(char **argv);
int			ft_check_num(char **str);
int			ft_check_order(t_stack *stack);

// Controls

t_stack		*ft_start(char **str);
int			ft_size(int argc, t_stack **sta);

// Utils

t_stack		*new_node(int num);
void		lst_front(t_stack **sw, t_stack *new);
t_stack		*get_last(t_stack *sw);
void		ft_lstclear(t_stack **lst, void (*del)(int));
long int	atoi_sw(char *str);
int			ft_strlen_double(char **str);
int			lstsize(t_stack *st);
t_stack		*search_node(int num, t_stack *st);
int			max_find(t_stack *stack);
int			min_find(t_stack *stack);
int			index_pos(t_stack *sw);
void		ft_free(char **str);
void		ft_free_stacks(t_stack **sta, t_stack **stb);

// Sort algorithm

void		ft_size3(t_stack **sta);
void		init_sort(t_stack **sta, t_stack **stb);
void		init_moves(t_stack *sta);
void		put_total_moves(t_stack *sta, t_stack *stb);
int			get_target(int num, t_stack **stb);
void		get_index(t_stack *st);
void		do_moves(t_stack **sta, t_stack **stb);

// Movements

void		sa(t_stack *sta);
void		sb(t_stack *stb);
void		ss(t_stack *sta, t_stack *stb);
void		pa(t_stack **sta, t_stack **stb);
void		pb(t_stack **sta, t_stack **stb);
void		ra(t_stack **sta, t_stack **stb);
void		rb(t_stack **sta, t_stack **stb);
void		rr(t_stack **sta, t_stack **stb);
void		rra(t_stack **sta, t_stack **stb);
void		rrb(t_stack **sta, t_stack **stb);
void		rrr(t_stack **sta, t_stack **stb);

#endif
