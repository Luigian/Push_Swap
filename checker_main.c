/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 19:03:41 by lusanche          #+#    #+#             */
/*   Updated: 2020/01/18 14:11:21 by lusanche         ###   ########.fr       */
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

void	ps_store(t_stack *a, int argc, char **argv)
{
	while (argc--)
		a->array[a->top++] = ft_atoi(argv[argc]);
}

int		main(int argc, char **argv)
{
	t_stack		a;
	t_stack		b;
	char		buff[3];
	int			nb;

	ps_store(&a, argc - 1, argv + 1);
	b.top = 0;
	while ((nb = read(0, buff, 4)) > 1)
	{
		buff[nb - 1] = '\0';
		ft_printf("nb: %d\tbuff:%s\n", nb, buff);
	}

	ps_putstack(&a);
	ps_putstack(&b);

	rra(&a);
	ps_putstack(&a);
	ps_putstack(&b);
	pb(&a, &b);
	ps_putstack(&a);
	ps_putstack(&b);
	sa(&a);
	ps_putstack(&a);
	ps_putstack(&b);
	rra(&a);
	ps_putstack(&a);
	ps_putstack(&b);
	pa(&a, &b);
	ps_putstack(&a);
	ps_putstack(&b);

	return (0);
}
