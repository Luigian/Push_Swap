/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 19:03:41 by lusanche          #+#    #+#             */
/*   Updated: 2020/01/22 10:52:56 by lusanche         ###   ########.fr       */
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

int		ps_validop(char *s)
{
	if (ft_strlen(s) == 2)
	{
		if (s[0] == 's' && (s[1] == 'a' || s[1] == 'b' || s[1] == 's'))
			return (1);
		else if (s[0] == 'p' && (s[1] == 'a' || s[1] == 'b'))
			return (1);
		else if (s[0] == 'r' && (s[1] == 'a' || s[1] == 'b' || s[1] == 'r'))
			return (1);
	}
	else if (s[0] == 'r' && s[1] == 'r' && (s[2] == 'a' || s[2] == 'b' ||\
				s[2] == 'r'))
		return (1);
	return (0);
}

void	ps_storebuff(char buff[MAXCAP][MAXCAP])
{
	int		i;
	int		j;
	int		nb;

	i = 0;
	j = 0;
	while ((nb = read(0, &buff[i][j], 1)) > 0)
	{
		if (buff[i][j] == '\n')
		{
			buff[i][j] = '\0';
			if (j == 1 || j > 3)
				ps_error();
			if (j == 0)
				break;
			if (ps_validop(buff[i]) == 0)
				ps_error();
			++i;
			j = 0;
		}
		else
			++j;
	}
}

/*	
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
*/

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

void	ps_putbuff(char buff[MAXCAP][MAXCAP])
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

void	ps_runbuff(char buff[MAXCAP][MAXCAP], t_stack *a, t_stack *b)
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

void	ps_check(t_stack *a, t_stack *b)
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
			ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

int		main(int argc, char **argv)
{
	t_stack		a;
	t_stack		b;
	char		buff[MAXCAP][MAXCAP];
	
	if (argc < 2)
		return (0);
	ps_storestacks(&a, &b, argc - 1, argv + 1);
	ps_storebuff(buff);
//	ps_putbuff(buff);
//	ps_putstack(&a);
//	ps_putstack(&b);
	ps_runbuff(buff, &a, &b);
	ps_check(&a, &b);
//	ps_putstack(&a);
//	ps_putstack(&b);
//	system("leaks checker");
	return (0);
}
