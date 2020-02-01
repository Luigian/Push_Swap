/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_swap_03.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 11:04:19 by lusanche          #+#    #+#             */
/*   Updated: 2020/02/01 10:16:28 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ps_checksort02(t_stack *a, t_stack *b, int *nko)
{
	int		prev;
	int		i;

	i = 0;
	prev = a->array[i];
	while (i < a->top)
	{
		if (a->array[i] > prev)
			*nko += 1;
		prev = a->array[i];
		++i;
	}
	if (*nko == 0 && b->top == 0)
		return (1);
	return (0);
}

void	ps_doop(char *s, t_stack *a, t_stack *b)
{
	if (ft_strcmp(s, "sa") == 0)
	{
		sa(a, b);
		ft_printf("sa\n");
	}
	else if (ft_strcmp(s, "pa") == 0)
	{
		pa(a, b);
		ft_printf("pa\n");
	}
	else if (ft_strcmp(s, "pb") == 0)
	{
		pb(a, b);
		ft_printf("pb\n");
	}
	else if (ft_strcmp(s, "ra") == 0)
	{
		ra(a, b);
		ft_printf("ra\n");
	}
	else if (ft_strcmp(s, "rra") == 0)
	{
		rra(a, b);
		ft_printf("rra\n");
	}
}

int		ps_findsmall(t_stack *a)
{
	int		i;
	int		small;
	int		ret;

	i = 0;
	small = a->array[i];
	ret = 0;
	while (i < a->top)
	{
		if (a->array[i] < small)
		{
			ret = i;
			small = a->array[i];
		}
		++i;
	}
	return (ret);
}

void	ps_movesmall(int i, t_stack *a, t_stack *b)
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

void	ps_selection(t_stack *a, t_stack *b)
{
	int		ko;
	int		i;

	ko = 0;
	i = 0;
	while (ps_checksort02(a, b, &ko) == 0)
	{
		if (ko == 0)
			ps_doop("pa", a, b);
		else if ((i = ps_findsmall(a)) != a->top - 1)
			ps_movesmall(i, a, b);
		else
			ps_doop("pb", a, b);
		ko = 0;
	}
}
