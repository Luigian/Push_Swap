/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_swap_05.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 19:12:44 by lusanche          #+#    #+#             */
/*   Updated: 2020/02/06 20:45:10 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_dora(char *s, t_stack *a, t_stack *b, t_doop *d)
{
	ra(a, b);
	if (d->op == 0)
		d->op = 1;
	else if (d->op == 1)
		d->fd ? ft_putendl_fd(s, d->fd) : ft_printf("%s\n", s);
	else if (d->op == 2)
	{
		d->fd ? ft_putendl_fd("rr", d->fd) : ft_printf("rr\n");
		d->op = 0;
	}
	else if (d->op == 3)
	{
		d->fd ? ft_putendl_fd("rra", d->fd) : ft_printf("rra\n");
		d->op = 1;
	}
	else if (d->op == 4)
	{
		d->fd ? ft_putendl_fd("rrb", d->fd) : ft_printf("rrb\n");
		d->op = 1;
	}
}

void	ps_dorb(char *s, t_stack *a, t_stack *b, t_doop *d)
{
	rb(a, b);
	if (d->op == 0)
		d->op = 2;
	else if (d->op == 1)
	{
		d->fd ? ft_putendl_fd("rr", d->fd) : ft_printf("rr\n");
		d->op = 0;
	}
	else if (d->op == 2)
		d->fd ? ft_putendl_fd(s, d->fd) : ft_printf("%s\n", s);
	else if (d->op == 3)
	{
		d->fd ? ft_putendl_fd("rra", d->fd) : ft_printf("rra\n");
		d->op = 2;
	}
	else if (d->op == 4)
	{
		d->fd ? ft_putendl_fd("rrb", d->fd) : ft_printf("rrb\n");
		d->op = 2;
	}
}

void	ps_dorra(char *s, t_stack *a, t_stack *b, t_doop *d)
{
	rra(a, b);
	if (d->op == 0)
		d->op = 3;
	else if (d->op == 1)
	{
		d->fd ? ft_putendl_fd("ra", d->fd) : ft_printf("ra\n");
		d->op = 3;
	}
	else if (d->op == 2)
	{
		d->fd ? ft_putendl_fd("rb", d->fd) : ft_printf("rb\n");
		d->op = 3;
	}
	else if (d->op == 3)
		d->fd ? ft_putendl_fd(s, d->fd) : ft_printf("%s\n", s);
	else if (d->op == 4)
	{
		d->fd ? ft_putendl_fd("rrr", d->fd) : ft_printf("rrr\n");
		d->op = 0;
	}
}

void	ps_dorrb(char *s, t_stack *a, t_stack *b, t_doop *d)
{
	rrb(a, b);
	if (d->op == 0)
		d->op = 4;
	else if (d->op == 1)
	{
		d->fd ? ft_putendl_fd("ra", d->fd) : ft_printf("ra\n");
		d->op = 4;
	}
	else if (d->op == 2)
	{
		d->fd ? ft_putendl_fd("rb", d->fd) : ft_printf("rb\n");
		d->op = 4;
	}
	else if (d->op == 3)
	{
		d->fd ? ft_putendl_fd("rrr", d->fd) : ft_printf("rrr\n");
		d->op = 0;
	}
	else if (d->op == 4)
		d->fd ? ft_putendl_fd(s, d->fd) : ft_printf("%s\n", s);
}

void	ps_doophelper(char *s, t_stack *a, t_stack *b, t_doop *d)
{
	if (ft_strcmp(s, "ra") == 0)
		ps_dora(s, a, b, d);
	else if (ft_strcmp(s, "rb") == 0)
		ps_dorb(s, a, b, d);
	else if (ft_strcmp(s, "rra") == 0)
		ps_dorra(s, a, b, d);
	else if (ft_strcmp(s, "rrb") == 0)
		ps_dorrb(s, a, b, d);
}
