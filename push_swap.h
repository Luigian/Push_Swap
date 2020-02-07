/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 19:12:42 by lusanche          #+#    #+#             */
/*   Updated: 2020/02/06 20:51:59 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <fcntl.h>
# define MAX 10000

typedef struct		s_stack
{
	int				array[MAX];
	int				top;
}					t_stack;

typedef struct		s_checker
{
	int				v;
	int				fd;
	int				ac;
	char			**av;
}					t_checker;

typedef struct		s_doop
{
	int				op;
	int				fd;
	int				i;
}					t_doop;

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

void				ps_checkpa(t_stack *a, t_stack *b, int *nko);
int					ps_checksort(t_stack *a, t_stack *b, int *nko);
int					ps_validarg(char *s, int *mult);
int					ps_uniquearg(t_stack *a);

/*
** ps_tools_02.c
*/

void				ps_error(int code);
int					ps_atoi(const char *str);
int					ps_splitlen(char **m);
void				ps_storehelper(char *s, t_stack *a);
void				ps_storestacks(t_stack *a, t_stack *b, int ac, char **av);

/*
** ps_main_checker.c
*/

void				ps_putstacks(t_stack *a, t_stack *b);
void				ps_putstatus(t_stack *a, t_stack *b, int v);
void				ps_check(t_stack *a, t_stack *b);
void				ps_initchecker(t_checker *c, t_stack *a, t_stack *b);

/*
** ps_checker_01.c
*/

int					ps_validop(char *s);
int					ps_storebuff(char buffer[MAX], int fd);
int					ps_hash(char *s);
void				ps_runbuff(char buffer[MAX], t_stack *a, t_stack *b);
void				ps_putbuff(char buff[MAX][MAX]);

/*
** ps_main_swap.c
*/

int					ps_hdassign(t_node *head, t_stack *a, t_stack *b, int *lv);
int					ps_inithead(t_node *head, t_stack *a, t_stack *b, int fd);
void				ps_writeflag(int *fd);

/*
** ps_swap_01.c
*/

int					ps_notviable(t_node *node, int ix);
t_stack				*ps_stackdup(t_stack *src);
void				ps_nodeassign(t_node *node, int ix);
int					ps_progress(t_node *node);
int					ps_initnode(t_node *node, int ix, int fd);

/*
** ps_swap_02.c
*/

void				ps_runhelper(t_node *node, int ix);
void				ps_runoper(t_node *node, int ix);
void				ps_putnodes(t_node *node);
void				ps_printsol(t_node *node, t_stack *p, int fd);
void				ps_freenodes(t_node *node);

/*
** ps_swap_03.c
*/

void				ps_fillsort(int *sort, t_stack *a);
void				ps_prepareb(t_stack *a, t_stack *b, t_doop *d);
void				ps_doop(char *s, t_stack *a, t_stack *b, t_doop *d);
int					ps_findbigger(t_stack *b);
void				ps_selection(t_stack *a, t_stack *b, int fd);

/*
** ps_swap_04.c
*/

int					ps_ingroup(int n, int *sort, int group);
int					ps_findhelper(t_stack *a, int *sort, int group);
int					ps_findcloser(t_stack *a, int *sort, int group);
void				ps_moveatop(t_doop *d, t_stack *a, t_stack *b);
void				ps_movebtop(t_doop *d, t_stack *a, t_stack *b);

/*
** ps_swap_05.c
*/

void				ps_dora(char *s, t_stack *a, t_stack *b, t_doop *d);
void				ps_dorb(char *s, t_stack *a, t_stack *b, t_doop *d);
void				ps_dorra(char *s, t_stack *a, t_stack *b, t_doop *d);
void				ps_dorrb(char *s, t_stack *a, t_stack *b, t_doop *d);
void				ps_doophelper(char *s, t_stack *a, t_stack *b, t_doop *d);

#endif
