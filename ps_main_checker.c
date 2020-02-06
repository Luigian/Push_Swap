/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_main_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 19:03:41 by lusanche          #+#    #+#             */
/*   Updated: 2020/02/06 14:03:56 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_putstacks(t_stack *a, t_stack *b)
{
	int		i;
	int		size;

	i = 0;
	size = a->top + b->top;
	while (i < size)
	{
		if (i < a->top)
			ft_printf("[%d]", a->array[i]);
		else
			ft_printf("[ ]");
		++i;
	}
	ft_printf("\tA | elements: %d\n", a->top);
	i = 0;
	while (i < size)
	{
		if (i < b->top)
			ft_printf("[%d]", b->array[i]);
		else
			ft_printf("[ ]");
		++i;
	}
}

void	ps_putstatus(t_stack *a, t_stack *b, int v)
{
	int		n;
	int		ret;

	n = 0;
	ret = ps_checksort(a, b, &n);
	if (ret)
		ft_printf("SOLVED IN %d MOVEMENTS\n", v);
	else
	{
		if (v == 0)
			ft_printf("Start\n");
		else
			ft_printf("movement #%d\n", v);
	}
	ps_putstacks(a, b);
	ft_printf("\tB | elements: %d%s", b->top, ret ? "\n" : "\n\n");
	if (ret)
		exit(1);
}

void	ps_check(t_stack *a, t_stack *b)
{
	int		prev;
	int		i;

	i = 0;
	prev = a->array[i];
	while (i < a->top)
	{
		if (a->array[i] > prev)
			break ;
		prev = a->array[i];
		++i;
	}
	if (i == a->top && b->top == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

void	ps_initchecker(t_checker *c, t_stack *a, t_stack *b)
{
	char	*line;

	line = NULL;
	c->v = 0;
	c->fd = 0;
	if (ft_strcmp("-v", c->av[1]) == 0)
	{
		ps_storestacks(a, b, c->ac - 2, c->av + 2);
		ps_putstatus(a, b, 0);
		c->v = 1;
	}
	else if (ft_strcmp("-r", c->av[1]) == 0)
	{
		ps_storestacks(a, b, c->ac - 2, c->av + 2);
		ft_printf("Enter source file path:\n");
		get_next_line(0, &line);
		if ((c->fd = open(line, O_RDONLY)) == -1)
			ps_error(-3);
	}
	else
		ps_storestacks(a, b, c->ac - 1, c->av + 1);
}

int		main(int argc, char **argv)
{
	t_stack		a;
	t_stack		b;
	t_checker	c;
	char		buffer[MAX];

	if (argc < 2)
		return (0);
	c.ac = argc;
	c.av = argv;
	ps_initchecker(&c, &a, &b);
	while (ps_storebuff(buffer, c.fd))
	{
		ps_runbuff(buffer, &a, &b);
		if (c.v)
			ps_putstatus(&a, &b, c.v++);
	}
	ps_check(&a, &b);
	return (0);
}
