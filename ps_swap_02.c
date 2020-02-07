/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_swap_02.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 19:44:25 by lusanche          #+#    #+#             */
/*   Updated: 2020/02/06 17:39:34 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_runhelper(t_node *node, int ix)
{
	if (ix == 4)
	{
		node->name = "ra";
		ra(node->a, node->b);
	}
	else if (ix == 5)
	{
		node->name = "rb";
		rb(node->a, node->b);
	}
	else if (ix == 6)
	{
		node->name = "rra";
		rra(node->a, node->b);
	}
	else if (ix == 7)
	{
		node->name = "rrb";
		rrb(node->a, node->b);
	}
}

void	ps_runoper(t_node *node, int ix)
{
	if (ix == 0)
	{
		node->name = "sa";
		sa(node->a, node->b);
	}
	else if (ix == 1)
	{
		node->name = "sb";
		sb(node->a, node->b);
	}
	else if (ix == 2)
	{
		node->name = "pa";
		pa(node->a, node->b);
	}
	else if (ix == 3)
	{
		node->name = "pb";
		pb(node->a, node->b);
	}
	else
		ps_runhelper(node, ix);
}

void	ps_putnodes(t_node *node)
{
	int		i;

	i = 0;
	while (i < 8)
	{
		if (node->br[i])
			ps_putnodes(node->br[i]);
		++i;
	}
	ft_printf("%s ", node->name);
	if (ft_strcmp(node->name, "head") == 0)
		ft_printf("\n");
}

void	ps_printsol(t_node *node, t_stack *p, int fd)
{
	int		i;

	i = 0;
	while (i < p->top)
	{
		if (fd)
			ft_putendl_fd(node->br[p->array[i]]->name, fd);
		else
			ft_printf("%s\n", node->br[p->array[i]]->name);
		node = node->br[p->array[i]];
		++i;
	}
	if (fd)
		ft_printf("Done!\n");
}

void	ps_freenodes(t_node *node)
{
	int		i;

	i = 0;
	while (i < 8)
	{
		if (node->br[i])
			ps_freenodes(node->br[i]);
		++i;
	}
	if (ft_strcmp(node->name, "head"))
	{
		free(node->a);
		free(node->b);
		free(node->p);
		free(node);
	}
	else
		free(node->p);
}
