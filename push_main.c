/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 09:42:37 by lusanche          #+#    #+#             */
/*   Updated: 2020/01/29 14:02:56 by lusanche         ###   ########.fr       */
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
//	if (i == a->top && b->top == 0)
	if (*nko == 0 && b->top == 0)
		return (1);
	if (b->top > 0)
		ps_checkpa(a, b, nko);
	return (0);
}

void	ps_printsol(t_node *node, t_stack *p)
{
	int		i;

	i = 0;
	while (i < p->top)
	{
		ft_printf("%s\n", node->br[p->array[i]]->name);
		node = node->br[p->array[i]];
		++i;
	}
}

int		ps_notviable(t_node *node, int ix)
{
	if (ix == 0 && node->a->top < 2)
		return (1);
	if (ix == 1 && node->b->top < 2)
		return (1);
	if (ix == 2 && node->b->top < 1)
		return (1);
	if (ix == 3 && node->a->top < 1)
		return (1);
	if (ix == 4 && node->a->top < 3)
		return (1);
	if (ix == 5 && node->b->top < 3)
		return (1);
	if (ix == 6 && node->a->top < 3)
		return (1);
	if (ix == 7 && node->b->top < 3)
		return (1);
	return (0);
}

int		ps_initnode(t_node *node, int ix)
{
	int		i;
	
	if (ps_notviable(node, ix))
		return (0);
	if (node->br[ix] == NULL)
	{
		node->br[ix] = malloc(sizeof(t_node));
		node->br[ix]->a = ps_stackdup(node->a);
		node->br[ix]->b = ps_stackdup(node->b);
		ps_runoper(node->br[ix], ix);
		node->br[ix]->p = ps_stackdup(node->p);
		node->br[ix]->p->array[node->p->top] = ix;
		node->br[ix]->p->top += 1;
		node->br[ix]->hd = node->hd;
		node->br[ix]->lv = node->lv;
		node->br[ix]->hko = node->hko;
		node->br[ix]->pko = node->nko;
		node->br[ix]->nko = 0;
		i = 0;
		while (i < 8)
			node->br[ix]->br[i++] = NULL;
		if (ps_checksort(node->br[ix]->a, node->br[ix]->b, &node->br[ix]->nko))
		{
			ps_printsol(node->br[ix]->hd, node->br[ix]->p);
			return (1);
		}
		ft_printf("%s\t", node->br[ix]->name);
		ft_printf("hko: %d, pko: %d, nko: %d\n", *node->br[ix]->hko,\
			node->br[ix]->pko, node->br[ix]->nko);
	}
	i = 0;
	while (i < 8 && node->br[ix]->p->top <= *node->br[ix]->lv &&\
			(node->br[ix]->nko <= node->br[ix]->pko))
	{
		if (ps_initnode(node->br[ix], i))
			return (1);
		++i;
	}
	return (0);
}	

int		ps_inithead(t_node *head, t_stack *a, t_stack *b)
{
	int		lv;
	int		i;

	head->name = "head";
	head->a = a;
	head->b = b;
	head->p = malloc(sizeof(t_stack));
	head->p->top = 0;
	head->hd = head;
	lv = 0;
	head->lv = &lv;
	if (ps_checksort(head->a, head->b, &head->nko))
		return (1);
	head->pko = head->nko;
	head->hko = &head->nko;
	ft_printf("%s\t", head->name);
	ft_printf("hko: %d, pko: %d, nko: %d\n", *head->hko, head->pko, head->nko);
	i = 0;
	while (i < 8)
	{
		head->br[i] = NULL;
		++i;
	}
	while (*head->lv < 10)
	{
		i = 0;
		while (i < 8)
		{
			if (ps_initnode(head, i))
				return (1);
			++i;
		}
		*head->lv += 1;
	}
	return (0);
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

int		main(int argc, char **argv)
{
	t_stack		a;
	t_stack		b;
	t_node		head;

	if (argc < 2)
		return (0);
	ps_storestacks(&a, &b, argc - 1, argv + 1);
//	ps_putstack(&a);
//	ps_putstack(&b);
	ps_inithead(&head, &a, &b);
//	ps_putnodes(&head);
	ps_freenodes(&head);
	system("leaks push_swap");
	return (0);
}
