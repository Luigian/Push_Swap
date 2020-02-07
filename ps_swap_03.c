/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_swap_03.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 11:04:19 by lusanche          #+#    #+#             */
/*   Updated: 2020/02/07 08:57:14 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_fillsort(int *sort, t_stack *a)
{
	int		i;
	int		j;

	i = 0;
	while (i < a->top)
	{
		j = 0;
		while (i && a->array[j] <= sort[i - 1])
			++j;
		sort[i] = a->array[j];
		while (j < a->top)
		{
			if (a->array[j] < sort[i])
			{
				if (i == 0)
					sort[i] = a->array[j];
				else if (a->array[j] > sort[i - 1])
					sort[i] = a->array[j];
			}
			++j;
		}
		++i;
	}
}

void	ps_prepareb(t_stack *a, t_stack *b, t_doop *d)
{
	int		n;
	int		i;
	int		left;
	int		x;

	n = a->array[a->top - 1];
	i = 0;
	left = 0;
	x = 0;
	while (i < b->top)
	{
		if (b->array[i] < n && (((n - b->array[i]) <= (n - b->array[left]))\
		|| n - b->array[left] < 0))
		{
			left = i;
			x = 1;
		}
		++i;
	}
	if (x == 0)
		left = ps_findbigger(b);
	d->i = left;
	if (left != (b->top - 1))
		ps_movebtop(d, a, b);
}

void	ps_doop(char *s, t_stack *a, t_stack *b, t_doop *d)
{
	if (ft_strcmp(s, "ra") && ft_strcmp(s, "rb") && ft_strcmp(s, "rra") &&\
		ft_strcmp(s, "rrb"))
	{
		if (d->op == 1)
			d->fd ? ft_putendl_fd("ra", d->fd) : ft_printf("ra\n");
		else if (d->op == 2)
			d->fd ? ft_putendl_fd("rb", d->fd) : ft_printf("rb\n");
		else if (d->op == 3)
			d->fd ? ft_putendl_fd("rra", d->fd) : ft_printf("rra\n");
		else if (d->op == 4)
			d->fd ? ft_putendl_fd("rrb", d->fd) : ft_printf("rrb\n");
		d->op = 0;
		if (ft_strcmp(s, "sa") == 0)
			ps_sa(a, b);
		else if (ft_strcmp(s, "sb") == 0)
			ps_sb(a, b);
		else if (ft_strcmp(s, "pa") == 0)
			ps_pa(a, b);
		else if (ft_strcmp(s, "pb") == 0)
			ps_pb(a, b);
		d->fd ? ft_putendl_fd(s, d->fd) : ft_printf("%s\n", s);
	}
	else
		ps_doophelper(s, a, b, d);
}

int		ps_findbigger(t_stack *b)
{
	int		i;
	int		bigger;
	int		ret;

	i = 0;
	bigger = b->array[i];
	ret = 0;
	while (i < b->top)
	{
		if (b->array[i] > bigger)
		{
			ret = i;
			bigger = b->array[i];
		}
		++i;
	}
	return (ret);
}

void	ps_selection(t_stack *a, t_stack *b, int fd)
{
	int		sort[a->top];
	int		group;
	t_doop	d;

	d.fd = fd;
	ps_fillsort(sort, a);
	group = a->top > 100 ? 45 : 20;
	d.op = 0;
	while (a->top)
	{
		d.i = ps_findcloser(a, sort, group);
		if (d.i == -1)
			group += a->top > 100 ? 45 : 20;
		else
		{
			if (d.i != a->top - 1)
				ps_moveatop(&d, a, b);
			ps_prepareb(a, b, &d);
			ps_doop("pb", a, b, &d);
		}
	}
	if ((d.i = ps_findbigger(b)) != b->top - 1)
		ps_movebtop(&d, a, b);
	while (b->top)
		ps_doop("pa", a, b, &d);
}
