/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 11:01:04 by lusanche          #+#    #+#             */
/*   Updated: 2020/01/20 12:20:00 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *a, t_stack *b)
{
	(void)b;
	if (a->top > 1)
		ft_swap(&a->array[a->top - 1], &a->array[a->top - 2]);
}

void	sb(t_stack *a, t_stack *b)
{
	(void)a;
	if (b->top > 1)
		ft_swap(&b->array[b->top - 1], &b->array[b->top - 2]);
}

void	ss(t_stack *a, t_stack *b)
{
	sa(a, b);
	sb(a, b);
}

void	pa(t_stack *a, t_stack *b)
{
	if (b->top > 0)
		a->array[a->top++] = b->array[--b->top];
}

void	pb(t_stack *a, t_stack *b)
{
	if (a->top > 0)
		b->array[b->top++] = a->array[--a->top];
}

void	ra(t_stack *a, t_stack *b)
{
	int		i;
	int		save;
	int		temp;

	(void)b;
	i = 0;
	if (a->top > 1)
	{
		save = a->array[i];
		a->array[i++] = a->array[a->top - 1];
		while (i < a->top)
		{
			temp = a->array[i];
			a->array[i++] = save;
			save = temp;
		}
	}
}

void	rb(t_stack *a, t_stack *b)
{
	int		i;
	int		save;
	int		temp;

	(void)a;
	i = 0;
	if (b->top > 1)
	{
		save = b->array[i];
		b->array[i++] = b->array[b->top - 1];
		while (i < b->top)
		{
			temp = b->array[i];
			b->array[i++] = save;
			save = temp;
		}
	}
}

void	rr(t_stack *a, t_stack *b)
{
	ra(a, b);
	rb(a, b);
}

void	rra(t_stack *a, t_stack *b)
{
	int		i;
	int		save;

	(void)b;
	i = 0;
	if (a->top > 1)
	{
		save = a->array[i];
		while (i + 1 < a->top)
		{
			a->array[i] = a->array[i + 1];
			++i;
		}
		a->array[i] = save;
	}
}

void	rrb(t_stack *a, t_stack *b)
{
	int		i;
	int		save;

	(void)a;
	i = 0;
	if (b->top > 1)
	{
		save = b->array[i];
		while (i + 1 < b->top)
		{
			b->array[i] = b->array[i + 1];
			++i;
		}
		b->array[i] = save;
	}
}

void	rrr(t_stack *a, t_stack *b)
{
	rra(a, b);
	rrb(a, b);
}
