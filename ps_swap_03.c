/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_swap_03.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 11:04:19 by lusanche          #+#    #+#             */
/*   Updated: 2020/01/31 14:03:20 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ps_unorder(int	left, int right)
{
	if (right > left)
		return (1);
	return (0);
}

void	ps_foo(t_stack *a, t_stack *b)
{
	if (ps_unorder(a->array[a->top - 2], a->array[a->top - 1]))
	{	
		sa(a, b);
		ft_printf("sa\n");
	}
	if (ps_unorder(a->array[0], a->array[1]))
	{	
		rra(a, b);
		ft_printf("rra\n");
		if (ps_unorder(a->array[a->top - 2], a->array[a->top - 1]))
		{	
			sa(a, b);
			ft_printf("sa\n");
		}
	}
	if (a->top > 4)
	{
		pb(a, b);
		ft_printf("pb\n");
	}

	ps_putstack(a);
	ps_putstack(b);

}
