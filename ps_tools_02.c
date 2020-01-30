/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_tools_02.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 19:43:59 by lusanche          #+#    #+#             */
/*   Updated: 2020/01/29 20:13:16 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_error(void)
{
	write(2, "Error\n", 6);
	exit(-1);
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
		ps_error();
	return ((int)result * sign);
}

void	ps_storestacks(t_stack *a, t_stack *b, int ac, char **av)
{
	a->top = 0;
	b->top = 0;
	while (ac--)
	{
		if (ps_validarg(av[ac]) == 0)
			ps_error();
		a->array[a->top++] = ps_atoi(av[ac]);
		if (ps_uniquearg(a) == 0)
			ps_error();
	}
}
