/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 19:12:42 by lusanche          #+#    #+#             */
/*   Updated: 2020/01/20 13:37:52 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ulibft/libft.h"
# define MAX_CAPACITY 10

typedef struct	s_stack
{
	int			array[MAX_CAPACITY];
	int			top;
}				t_stack;

typedef void	(*t_funpa)(t_stack *a, t_stack *b);

void			ps_putstack(t_stack *a);
void			ps_storestacks(t_stack *a, t_stack *b, int argc, char **argv);

void			sa(t_stack *a, t_stack *b);
void			sb(t_stack *a, t_stack *b);
void			ss(t_stack *a, t_stack *b);
void			pa(t_stack *a, t_stack *b);
void			pb(t_stack *a, t_stack *b);
void			ra(t_stack *a, t_stack *b);
void			rb(t_stack *a, t_stack *b);
void			rr(t_stack *a, t_stack *b);
void			rra(t_stack *a, t_stack *b);
void			rrb(t_stack *a, t_stack *b);
void			rrr(t_stack *a, t_stack *b);






#endif
