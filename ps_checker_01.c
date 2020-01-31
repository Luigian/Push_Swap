/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_checker_01.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 20:48:12 by lusanche          #+#    #+#             */
/*   Updated: 2020/01/30 20:45:25 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	ps_storebuff(char buff[MAX][MAX])
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
				ps_error(-1);
			if (j == 0)
				break ;
			if (ps_validop(buff[i]) == 0)
				ps_error(-1);
			++i;
			j = 0;
		}
		else
			++j;
	}
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

void	ps_runbuff(char buff[MAX][MAX], t_stack *a, t_stack *b)
{
	t_funpa		f[343];
	int			i;

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
	i = 0;
	while (buff[i][0])
	{
		f[ps_hash(buff[i])](a, b);
		++i;
	}
}

void	ps_putbuff(char buff[MAX][MAX])
{
	int		i;

	i = 0;
	while (buff[i][0])
	{
		ft_printf("hash: [%d] buff[%d]: %s\n", ps_hash(buff[i]), i, buff[i]);
		++i;
	}
}
