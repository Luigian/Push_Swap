/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 19:12:42 by lusanche          #+#    #+#             */
/*   Updated: 2020/01/29 21:22:20 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# define MAX 100

typedef struct		s_stack
{
	int				array[MAX];
	int				top;
}					t_stack;

typedef struct		s_node
{
	char			*name;
	t_stack			*a;
	t_stack			*b;
	t_stack			*p;
	struct s_node	*br[8];
	struct s_node	*hd;
	int				*lv;
	int				*hko;
	int				pko;
	int				nko;
}					t_node;

typedef void		(*t_funpa)(t_stack *a, t_stack *b);

/*
** ps_oper_01.c
*/

void				sa(t_stack *a, t_stack *b);
void				sb(t_stack *a, t_stack *b);
void				ss(t_stack *a, t_stack *b);
void				pa(t_stack *a, t_stack *b);
void				pb(t_stack *a, t_stack *b);

/*
** ps_oper_02.c
*/

void				ra(t_stack *a, t_stack *b);
void				rb(t_stack *a, t_stack *b);
void				rr(t_stack *a, t_stack *b);

/*
** ps_oper_03.c
*/

void				rra(t_stack *a, t_stack *b);
void				rrb(t_stack *a, t_stack *b);
void				rrr(t_stack *a, t_stack *b);

/*
** ps_tools_01.c
*/

void				ps_putstack(t_stack *a);
int					ps_validarg(char *s);
int					ps_uniquearg(t_stack *a);

/*
** ps_tools_02.c
*/

void				ps_error(void);
int					ps_atoi(const char *str);
void				ps_storestacks(t_stack *a, t_stack *b, int ac, char **av);

/*
** ps_buff.c
*/

int					ps_validop(char *s);
void				ps_storebuff(char buff[MAX][MAX]);
int					ps_hash(char *s);
void				ps_runbuff(char buff[MAX][MAX], t_stack *a, t_stack *b);
void				ps_putbuff(char buff[MAX][MAX]);

#endif
