/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 09:42:37 by lusanche          #+#    #+#             */
/*   Updated: 2020/01/25 21:08:55 by lusanche         ###   ########.fr       */
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

int		ps_validarg(char *s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (ft_isdigit(s[i]) || (i == 0 && (s[i] == '-' || s[i] == '+')))
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

void	ps_error(void)
{
		write(2, "Error\n", 6);
		exit (-1);
}

int		ps_atoi(const char *str)
{
	int		sign;
	long	result;

	if (ft_strcmp(str,"-2147483648") == 0)
		return (-2147483648);
	sign = 1;
	result = 0;
	while (ft_isspecial(*str))
		++str;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		++str;
	}
	while (ft_isdigit(*str))
	{
		result = (result * 10) + (*str - 48);
		++str;
	}
	if (result > 2147483647 || result < -2147483648)
		ps_error();
	return ((int)result * sign);
}

void	ps_storestacks(t_stack *a, t_stack *b, int argc, char **argv)
{
	a->top = 0;
	b->top = 0;
	while (argc--)
	{
		if (ps_validarg(argv[argc]) == 0)
			ps_error();
		a->array[a->top++] = ps_atoi(argv[argc]);
		if (ps_uniquearg(a) == 0)
			ps_error();
	}
}

t_stack		*ps_stackdup(t_stack *src)
{
	t_stack		*new;
	int			i;

	new = malloc(sizeof(t_stack));
	i = 0;
	while (i < src->top)
	{
		new->array[i] = src->array[i];
		++i;
	}
	new->top = src->top;
	return (new);
}


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

int		ps_checkoper(t_stack *a, t_stack *b)
{
	int		prev;
	int		i;

	i = 0;
	prev = a->array[i];
	while (i < a->top)
	{
		if (a->array[i] > prev)
			break;
		prev = a->array[i];
		++i;
	}
	if (i == a->top && b->top == 0)
			return (1);
	return (0);
}

void	ps_printsol(t_node *node, t_stack *p)
{
	int		i;

	i = 0;
	while (i < p->top)
	{
		ft_printf("%s\n", node->br[p->array[i]]->name);
		++i;
	}
}

int		ps_initnode(t_node *node, int ix)
{
	int		i;
	
	node->br[ix] = malloc(sizeof(t_node));
	node->br[ix]->a = ps_stackdup(node->a);
	node->br[ix]->b = ps_stackdup(node->b);
	ps_runoper(node->br[ix], ix);
	node->br[ix]->p = ps_stackdup(node->p);
	node->br[ix]->p->array[node->p->top] = ix;
	node->br[ix]->p->top += 1;
	i = 0;
	while (i < 8)
		node->br[ix]->br[i++] = NULL;
	if (ps_checkoper(node->br[ix]->a, node->br[ix]->b))
	{
		ps_printsol(node, node->br[ix]->p);
		return (1);
	}
	i = 0;
	while (i < 8 && node->br[ix]->p->top < 1)
	{
		ps_initnode(node->br[ix], i);
		++i;
	}
	return (0);
}	

void	ps_inithead(t_node *head, t_stack *a, t_stack *b)
{
	int		i;
	
	head = malloc(sizeof(t_node));
	head->name = "head";
	head->a = ps_stackdup(a);
	head->b = ps_stackdup(b);
	head->p = malloc(sizeof(t_stack));
	head->p->top = 0;
	i = 0;
	while (i < 8)
	{
		head->br[i] = NULL;
		++i;
	}
	i = 0;
	while (i < 8)
	{
		if (ps_initnode(head, i))
			break ;
		++i;
	}
}	

void	ps_freenodes(t_node *head)
{
	int		i;

//	(void)head;
	i = 0;
	while (i < 8 /*&& head->br[i]*/)
	{	
		free(head->br[0]->a);
		free(head->br[0]->b);
		free(head->br[0]->p);
		free(head->br[0]);
		++i;
	}
	free(head->a);
	free(head->b);
	free(head->p);
	free(head);
}

int		main(int argc, char **argv)
{
	t_stack		a;
	t_stack		b;
	t_node		*head;

	if (argc < 2)
		return (0);
	ps_storestacks(&a, &b, argc - 1, argv + 1);
	ps_putstack(&a);
	ps_putstack(&b);
	head = NULL;
	ps_inithead(head, &a, &b);
//	ps_freenodes(head);
	system("leaks push_swap");
	return (0);
}
