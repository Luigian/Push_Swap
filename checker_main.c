/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 19:03:41 by lusanche          #+#    #+#             */
/*   Updated: 2020/01/20 13:47:57 by lusanche         ###   ########.fr       */
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

void	ps_storestacks(t_stack *a, t_stack *b, int argc, char **argv)
{
	a->top = 0;
	b->top = 0;
	while (argc--)
		a->array[a->top++] = ft_atoi(argv[argc]);
}
	
void	ps_storebuff(char buff[100][100])
{
	int		i;
	int		nb;

	i = 0;
	while ((nb = read(0, buff[i], 100)) > 2)
	{
		buff[i][nb - 1] = '\0';
		++i;
	}
	buff[i][nb - 1] = '\0';
}
	
int		ps_hash(char *s)
{
	int		hash;

	hash = 0;
	while (*s)
	{
		hash = *s + hash;
		++s;
	}
	if (hash == 212 && *(s - 2) == 'r')
		hash += 2;
	return (hash);
}

void	ps_putbuff(char buff[100][100])
{
	int		i;

	i = 0;
	while (buff[i][0])
	{
		ft_printf("hash: [%d] buff[%d]: %s\n", ps_hash(buff[i]), i, buff[i]);
		++i;
	}
}

void	ps_funfill(t_funpa f[])
{
	f[212] = &sa;
	f[213] = &sb;
	f[230] = &ss;
	f[209] = &pa;
	f[210] = &pb;
	f[211] = &ra;
	f[214] = &rb;
	f[228] = &rr;
	f[325] = &rra;
	f[326] = &rrb;
	f[342] = &rrr;
}

void	ps_runbuff(char buff[100][100], t_stack *a, t_stack *b)
{
	t_funpa		f[343];
	int		i;

	ps_funfill(f);
	i = 0;
	while (buff[i][0])
	{
		f[ps_hash(buff[i])](a, b);
		++i;
	}
}

int		main(int argc, char **argv)
{
	t_stack		a;
	t_stack		b;
	char		buff[100][100];

	ps_storestacks(&a, &b, argc - 1, argv + 1);
	ps_storebuff(buff);
	
	ps_putbuff(buff);
	ps_putstack(&a);
	ps_putstack(&b);
	
	ps_runbuff(buff, &a, &b);
	
	ps_putstack(&a);
	ps_putstack(&b);
	return (0);
}
