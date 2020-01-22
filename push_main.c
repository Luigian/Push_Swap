/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 09:42:37 by lusanche          #+#    #+#             */
/*   Updated: 2020/01/22 10:52:26 by lusanche         ###   ########.fr       */
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

int		main(int argc, char **argv)
{
	t_stack		a;
	t_stack		b;
//	char		buff[MAXCAP][MAXCAP];

	if (argc < 2)
		return (0);
	ps_storestacks(&a, &b, argc - 1, argv + 1);
//	ps_storebuff(buff);
//	ps_putbuff(buff);
	ps_putstack(&a);
	ps_putstack(&b);
//	ps_runbuff(buff, &a, &b);
//	ps_check(&a, &b);
//	ps_putstack(&a);
//	ps_putstack(&b);
//	system("leaks checker");
	return (0);
}
