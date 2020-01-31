/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_swap_01.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 19:39:31 by lusanche          #+#    #+#             */
/*   Updated: 2020/01/30 20:39:23 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ps_notviable(t_node *node, int ix)
{
	if (ix == 0 && node->a->top < 2)
		return (1);
	if (ix == 1 && node->b->top < 2)
		return (1);
	if (ix == 2 && node->b->top < 1)
		return (1);
	if (ix == 3 && node->a->top < 1)
		return (1);
	if (ix == 4 && node->a->top < 3)
		return (1);
	if (ix == 5 && node->b->top < 3)
		return (1);
	if (ix == 6 && node->a->top < 3)
		return (1);
	if (ix == 7 && node->b->top < 3)
		return (1);
	return (0);
}

t_stack		*ps_stackdup(t_stack *src)
{
	t_stack		*new;
	int			i;

	if (!(new = malloc(sizeof(t_stack))))
		ps_error(-2);
	i = 0;
	while (i < src->top)
	{
		new->array[i] = src->array[i];
		++i;
	}
	new->top = src->top;
	return (new);
}

void		ps_nodeassign(t_node *node, int ix)
{
	if (!(node->br[ix] = malloc(sizeof(t_node))))
		ps_error(-2);
	node->br[ix]->a = ps_stackdup(node->a);
	node->br[ix]->b = ps_stackdup(node->b);
	ps_runoper(node->br[ix], ix);
	node->br[ix]->p = ps_stackdup(node->p);
	node->br[ix]->p->array[node->p->top] = ix;
	node->br[ix]->p->top += 1;
	node->br[ix]->hd = node->hd;
	node->br[ix]->lv = node->lv;
	node->br[ix]->hko = node->hko;
	node->br[ix]->pko = node->nko;
	node->br[ix]->nko = 0;
}

int			ps_progress(t_node *node)
{
	int		flex;

	flex = 2;
	if ((*node->lv - 1) % flex == 0)
		if ((*node->hko - ((*node->lv - 1) / flex)) < node->nko)
			return (0);
	if (node->p->top <= *node->lv && (node->nko <= node->pko))
		return (1);
	return (0);
}

int			ps_initnode(t_node *node, int ix)
{
	int		i;

	if (ps_notviable(node, ix))
		return (0);
	if (node->br[ix] == NULL)
	{
		ps_nodeassign(node, ix);
		i = 0;
		while (i < 8)
			node->br[ix]->br[i++] = NULL;
		if (ps_checksort(node->br[ix]->a, node->br[ix]->b, &node->br[ix]->nko))
		{
			ps_printsol(node->br[ix]->hd, node->br[ix]->p);
			ps_putstack(node->br[ix]->a);
			return (1);
		}
	}
	i = 0;
	while (i < 8 && ps_progress(node->br[ix]))
	{
		if (ps_initnode(node->br[ix], i))
			return (1);
		++i;
	}
	return (0);
}
