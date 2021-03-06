/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_oper_03.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 19:27:39 by lusanche          #+#    #+#             */
/*   Updated: 2020/02/07 08:47:29 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_rra(t_stack *a, t_stack *b)
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

void	ps_rrb(t_stack *a, t_stack *b)
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

void	ps_rrr(t_stack *a, t_stack *b)
{
	ps_rra(a, b);
	ps_rrb(a, b);
}
