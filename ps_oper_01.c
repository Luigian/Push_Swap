/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_oper_01.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 11:01:04 by lusanche          #+#    #+#             */
/*   Updated: 2020/01/29 19:30:09 by lusanche         ###   ########.fr       */
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
