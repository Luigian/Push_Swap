/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_swap_03.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 11:04:19 by lusanche          #+#    #+#             */
/*   Updated: 2020/02/05 14:12:21 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_doop(char *s, t_stack *a, t_stack *b)
{
	if (ft_strcmp(s, "sa") == 0)
		sa(a, b);
	else if (ft_strcmp(s, "sb") == 0)
		sb(a, b);
	else if (ft_strcmp(s, "pa") == 0)
		pa(a, b);
	else if (ft_strcmp(s, "pb") == 0)
		pb(a, b);
	else if (ft_strcmp(s, "ra") == 0)
		ra(a, b);
	else if (ft_strcmp(s, "rb") == 0)
		rb(a, b);
	else if (ft_strcmp(s, "rra") == 0)
		rra(a, b);
	else if (ft_strcmp(s, "rrb") == 0)
		rrb(a, b);
	ft_printf("%s\n", s);
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

void	ps_movebtop(int i, t_stack *a, t_stack *b)
{
	if (i >= b->top / 2)
	{
		while (i < b->top - 1)
		{
			ps_doop("rb", a, b);
			++i;
		}
	}
	else
	{
		while (i + 1 > 0)
		{
			ps_doop("rrb", a, b);
			--i;
		}
	}
}

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

void	ps_moveatop(int i, t_stack *a, t_stack *b)
{
	if (i == a->top - 2)
		ps_doop("sa", a, b);
	else if (i >= a->top / 2)
	{
		while (i < a->top - 1)
		{
			ps_doop("ra", a, b);
			++i;
		}
	}
	else
	{
		while (i + 1 > 0)
		{
			ps_doop("rra", a, b);
			--i;
		}
	}
}

void	ps_prepareb(t_stack *a, t_stack *b)
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
		ps_movebtop(left, a, b);
}

void	ps_selection(t_stack *a, t_stack *b)
{
	int		sort[a->top];
	int		i;
	int		group;

	ps_fillsort(sort, a);
	group = 20;
	while (a->top)
	{
		i = ps_findcloser(a, sort, group);
		if (i == -1)
			group += 20;
		else
		{
			if (i != a->top - 1)
				ps_moveatop(i, a, b);
			ps_prepareb(a, b);
			ps_doop("pb", a, b);
		}
	}
	if ((i = ps_findbigger(b)) != b->top - 1)
		ps_movebtop(i, a, b);
	while (b->top)
		ps_doop("pa", a, b);
}
