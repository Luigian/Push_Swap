/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_main_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 19:03:41 by lusanche          #+#    #+#             */
/*   Updated: 2020/02/05 20:37:49 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int		main(int argc, char **argv)
{
	t_stack		a;
	t_stack		b;
	char		buffer[MAX];
	int			ret;
	int			v;

	if (argc < 2)
		return (0);
	v = 0;
	if (ft_strcmp("-v", argv[1]) == 0)
	{
		v = 1;			
		++argv;
		--argc;
	}
	ps_storestacks(&a, &b, argc - 1, argv + 1);
	if (v)
	{
		ps_putstack(&a);
		ps_putstack(&b);
	}
	ret = 1;
	while (ret)
	{
		ret = ps_storebuff(buffer);
		if (ret)
		{
			ps_runbuff(buffer, &a, &b);
			if (v)
			{
				ps_putstack(&a);
				ps_putstack(&b);
			}
		}
	}
	ps_check(&a, &b);
	return (0);
}
