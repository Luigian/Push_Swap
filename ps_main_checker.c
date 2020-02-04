/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_main_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 19:03:41 by lusanche          #+#    #+#             */
/*   Updated: 2020/02/03 18:52:19 by lusanche         ###   ########.fr       */
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
	int			mov;

	if (argc < 2)
		return (0);
	ps_storestacks(&a, &b, argc - 1, argv + 1);
	ps_putstack(&a);
	ps_putstack(&b);
	ret = 1;
	mov = 0;
	while (ret)
	{
		ret = ps_storebuff(buffer);
		if (ret)
		{
			ps_runbuff(buffer, &a, &b);
			ft_printf("mov: %d\n", ++mov);
			ps_putstack(&a);
			ps_putstack(&b);
		}
	}
	ps_check(&a, &b);
	return (0);
}
