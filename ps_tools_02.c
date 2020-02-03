/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_tools_02.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 19:43:59 by lusanche          #+#    #+#             */
/*   Updated: 2020/02/03 11:48:23 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_error(int code)
{
	if (code == -2)
	{
		write(2, "Malloc Error\n", 13);
		exit(-2);
	}
	else if (code == -1)
	{
		write(2, "Error\n", 6);
		exit(-1);
	}
}

int		ps_atoi(const char *str)
{
	int		sign;
	long	result;

	if (ft_strcmp(str, "-2147483648") == 0)
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
		ps_error(-1);
	return ((int)result * sign);
}

int		ps_splitlen(char **m)
{
	int		i;

	i = 0;
	while (m[i])
		++i;
	return (i);
}

void	ps_storehelper(char *s, t_stack *a)
{
	char	**m;
	int		i;

	m = ft_strsplit(s, ' ');
	i = ps_splitlen(m);
	while (i--)
	{
		a->array[a->top++] = ps_atoi(m[i]);
		if (ps_uniquearg(a) == 0)
			ps_error(-1);
	}
}

void	ps_storestacks(t_stack *a, t_stack *b, int ac, char **av)
{
	int		mult;

	mult = 0;
	a->top = 0;
	b->top = 0;
	while (ac--)
	{
		if (ps_validarg(av[ac], &mult) == 0)
			ps_error(-1);
		if (mult)
		{
			ps_storehelper(av[ac], a);
			mult = 0;
		}
		else
		{
			a->array[a->top++] = ps_atoi(av[ac]);
			if (ps_uniquearg(a) == 0)
				ps_error(-1);
		}
	}
}
