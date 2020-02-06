/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_swap_03.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 11:04:19 by lusanche          #+#    #+#             */
/*   Updated: 2020/02/05 19:33:59 by lusanche         ###   ########.fr       */
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

void	ps_prepareb(t_stack *a, t_stack *b, int *ops)
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
	if (left != (b->top - 1))
		ps_movebtop(left, a, b, ops);
}

void	ps_doop(char *s, t_stack *a, t_stack *b, int *ops)
{
	if (ft_strcmp(s, "ra") && ft_strcmp(s, "rb") && ft_strcmp(s, "rra") &&\
		ft_strcmp(s, "rrb"))
	{
		if (*ops == 1)
			ft_printf("ra\n");
		else if (*ops == 2)
			ft_printf("rb\n");
		else if (*ops == 3)
			ft_printf("rra\n");
		else if (*ops == 4)
			ft_printf("rrb\n");
		*ops = 0;
		if (ft_strcmp(s, "sa") == 0)
			sa(a, b);
		else if (ft_strcmp(s, "sb") == 0)
			sb(a, b);
		else if (ft_strcmp(s, "pa") == 0)
			pa(a, b);
		else if (ft_strcmp(s, "pb") == 0)
			pb(a, b);
		ft_printf("%s\n", s);
	}
	else
		ps_doophelper(s, a, b, ops);
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

void	ps_selection(t_stack *a, t_stack *b)
{
	int		sort[a->top];
	int		i;
	int		group;
	int		ops;

	ps_fillsort(sort, a);
	group = a->top > 100 ? 45 : 20;
	ops = 0;
	while (a->top)
	{
		i = ps_findcloser(a, sort, group);
		if (i == -1)
			group += a->top > 100 ? 45 : 20;
		else
		{
			if (i != a->top - 1)
				ps_moveatop(i, a, b, &ops);
			ps_prepareb(a, b, &ops);
			ps_doop("pb", a, b, &ops);
		}
	}
	if ((i = ps_findbigger(b)) != b->top - 1)
		ps_movebtop(i, a, b, &ops);
	while (b->top)
		ps_doop("pa", a, b, &ops);
}
