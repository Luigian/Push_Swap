/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 19:12:42 by lusanche          #+#    #+#             */
/*   Updated: 2020/01/27 19:53:48 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ulibft/libft.h"
# define MAXCAP 100

typedef struct	s_stack
{
	int				array[MAXCAP];
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
	int				nko;
}					t_node;	

typedef void	(*t_funpa)(t_stack *a, t_stack *b);

void			ps_putstack(t_stack *a);
void			ps_storestacks(t_stack *a, t_stack *b, int argc, char **argv);
void			ps_storebuff(char buff[MAXCAP][MAXCAP]);
void			ps_putbuff(char buff[MAXCAP][MAXCAP]);
void			ps_funfill(t_funpa f[]);
int				ps_hash(char *s);
void			ps_runbuff(char buff[MAXCAP][MAXCAP], t_stack *a, t_stack *b);
void			ps_check(t_stack *a, t_stack *b);
int				ps_validarg(char *s);
int				ps_uniquearg(t_stack *a);
int				ps_atoi(const char *str);
void			ps_error(void);
int				ps_validop(char *s);


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
