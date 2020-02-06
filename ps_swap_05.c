/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_swap_05.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 19:12:44 by lusanche          #+#    #+#             */
/*   Updated: 2020/02/05 19:13:45 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_dora(char *s, t_stack *a, t_stack *b, int *ops)
{
	ra(a, b);
	if (*ops == 0)
		*ops = 1;
	else if (*ops == 1)
		ft_printf("%s\n", s);
	else if (*ops == 2)
	{
		ft_printf("rr\n");
		*ops = 0;
	}
	else if (*ops == 3)
	{
		ft_printf("rra\n");
		*ops = 1;
	}
	else if (*ops == 4)
	{
		ft_printf("rrb\n");
		*ops = 1;
	}
}

void	ps_dorb(char *s, t_stack *a, t_stack *b, int *ops)
{
	rb(a, b);
	if (*ops == 0)
		*ops = 2;
	else if (*ops == 1)
	{
		ft_printf("rr\n");
		*ops = 0;
	}
	else if (*ops == 2)
		ft_printf("%s\n", s);
	else if (*ops == 3)
	{
		ft_printf("rra\n");
		*ops = 2;
	}
	else if (*ops == 4)
	{
		ft_printf("rrb\n");
		*ops = 2;
	}
}

void	ps_dorra(char *s, t_stack *a, t_stack *b, int *ops)
{
	rra(a, b);
	if (*ops == 0)
		*ops = 3;
	else if (*ops == 1)
	{
		ft_printf("ra\n");
		*ops = 3;
	}
	else if (*ops == 2)
	{
		ft_printf("rb\n");
		*ops = 3;
	}
	else if (*ops == 3)
		ft_printf("%s\n", s);
	else if (*ops == 4)
	{
		ft_printf("rrr\n");
		*ops = 0;
	}
}

void	ps_dorrb(char *s, t_stack *a, t_stack *b, int *ops)
{
	rrb(a, b);
	if (*ops == 0)
		*ops = 4;
	else if (*ops == 1)
	{
		ft_printf("ra\n");
		*ops = 4;
	}
	else if (*ops == 2)
	{
		ft_printf("rb\n");
		*ops = 4;
	}
	else if (*ops == 3)
	{
		ft_printf("rrr\n");
		*ops = 0;
	}
	else if (*ops == 4)
		ft_printf("%s\n", s);
}

void	ps_doophelper(char *s, t_stack *a, t_stack *b, int *ops)
{
	if (ft_strcmp(s, "ra") == 0)
		ps_dora(s, a, b, ops);
	else if (ft_strcmp(s, "rb") == 0)
		ps_dorb(s, a, b, ops);
	else if (ft_strcmp(s, "rra") == 0)
		ps_dorra(s, a, b, ops);
	else if (ft_strcmp(s, "rrb") == 0)
		ps_dorrb(s, a, b, ops);
}
