/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 19:03:41 by lusanche          #+#    #+#             */
/*   Updated: 2020/01/17 20:45:47 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_putstack(t_stack *s)
{
	int		i;

	i = 0;
	while (i < s->top)
		ft_printf("[%d]", s->array[i++]);
	ft_printf("\t%d\n", s->top);
}

void	ps_store(t_stack *a, int argc, char **argv)
{
	while (argc--)
		a->array[a->top++] = ft_atoi(argv[argc]);
}

void	sa(t_stack *a)
{
	if (a->top > 1)
		ft_swap(&a->array[a->top - 1], &a->array[a->top - 2]);
}

void	sb(t_stack *b)
{
	if (b->top > 1)
		ft_swap(&b->array[b->top - 1], &b->array[b->top - 2]);
}

void	ss(t_stack *a, t_stack *b)
{
	sa(a);
	sb(b);
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

void	ra(t_stack *a)
{
	int		i;
	int		save;
	int		temp;
	
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

void	rb(t_stack *b)
{
	int		i;
	int		save;
	int		temp;
	
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
	ra(a);
	rb(b);
}

void	rra(t_stack *a)
{
	int		i;
	int		save;
	
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

void	rrb(t_stack *b)
{
	int		i;
	int		save;
	
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
	rra(a);
	rrb(b);
}

int		main(int argc, char **argv)
{
	t_stack		a;
	t_stack		b;

	ps_store(&a, argc - 1, argv + 1);
	b.top = 0;
	ps_putstack(&a);
	ps_putstack(&b);
	sa(&a);
	sb(&b);
	ps_putstack(&a);
	ps_putstack(&b);
	ss(&a, &b);
	ps_putstack(&a);
	ps_putstack(&b);
	pb(&a, &b);
	ps_putstack(&a);
	ps_putstack(&b);
	pa(&a, &b);
	ps_putstack(&a);
	ps_putstack(&b);
	ra(&a);
	rb(&b);
	ps_putstack(&a);
	ps_putstack(&b);
	rr(&a, &b);
	ps_putstack(&a);
	ps_putstack(&b);
	rra(&a);
	rrb(&b);
	ps_putstack(&a);
	ps_putstack(&b);
	rrr(&a, &b);
	ps_putstack(&a);
	ps_putstack(&b);
	return (0);
}
