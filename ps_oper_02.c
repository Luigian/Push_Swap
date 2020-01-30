/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_oper_02.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 19:27:01 by lusanche          #+#    #+#             */
/*   Updated: 2020/01/29 19:27:31 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
