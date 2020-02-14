/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_tools_01.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 19:35:52 by lusanche          #+#    #+#             */
/*   Updated: 2020/02/06 11:03:59 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_checkpa(t_stack *a, t_stack *b, int *nko)
{
	int		prev;
	int		i;

	if (b->array[b->top - 1] > a->array[a->top - 1])
		*nko += 1;
	i = 0;
	prev = b->array[i];
	while (i < b->top - 1)
	{
		if (b->array[i] < prev)
			*nko += 1;
		prev = b->array[i];
		++i;
	}
}

int		ps_checksort(t_stack *a, t_stack *b, int *nko)
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
	if (b->top > 0)
		ps_checkpa(a, b, nko);
	return (0);
}

int		ps_validarg(char *s, int *mult)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == ' ')
			*mult = 1;
		if (ft_isdigit(s[i]) || (i == 0 && (s[i] == '-' || s[i] == '+'))\
			|| s[i] == ' ')
			++i;
		else
			return (0);
	}
	return (1);
}

int		ps_uniquearg(t_stack *a)
{
	int		i;

	i = 0;
	while (i < a->top - 1)
	{
		if (a->array[i] == a->array[a->top - 1])
			return (0);
		++i;
	}
	return (1);
}
