/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_swap_04.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 19:23:15 by lusanche          #+#    #+#             */
/*   Updated: 2020/02/06 19:58:43 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ps_ingroup(int n, int *sort, int group)
{
	int		i;

	i = 0;
	while (i < group)
	{
		if (n == sort[i])
			return (1);
		++i;
	}
	return (0);
}

int		ps_findhelper(t_stack *a, int *sort, int group)
{
	int		i;
	int		right;

	i = a->top - 1;
	right = 0;
	while (i >= 0)
	{
		if (ps_ingroup(a->array[i], sort, group))
		{
			right = i;
			break ;
		}
		--i;
	}
	return (right);
}

int		ps_findcloser(t_stack *a, int *sort, int group)
{
	int		i;
	int		left;
	int		right;

	i = 0;
	while (i < a->top)
	{
		if (ps_ingroup(a->array[i], sort, group))
		{
			left = i;
			break ;
		}
		++i;
	}
	if (i == a->top)
		return (-1);
	right = ps_findhelper(a, sort, group);
	if (left < ((a->top - 1) - right))
		return (left);
	return (right);
}

void	ps_moveatop(t_doop *d, t_stack *a, t_stack *b)
{
	if (d->i == a->top - 2)
		ps_doop("sa", a, b, d);
	else if (d->i >= a->top / 2)
	{
		while (d->i < a->top - 1)
		{
			ps_doop("ra", a, b, d);
			++d->i;
		}
	}
	else
	{
		while (d->i + 1 > 0)
		{
			ps_doop("rra", a, b, d);
			--d->i;
		}
	}
}

void	ps_movebtop(t_doop *d, t_stack *a, t_stack *b)
{
	if (d->i >= b->top / 2)
	{
		while (d->i < b->top - 1)
		{
			ps_doop("rb", a, b, d);
			++d->i;
		}
	}
	else
	{
		while (d->i + 1 > 0)
		{
			ps_doop("rrb", a, b, d);
			--d->i;
		}
	}
}
