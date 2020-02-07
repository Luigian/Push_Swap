/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_checker_01.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 20:48:12 by lusanche          #+#    #+#             */
/*   Updated: 2020/02/07 08:51:16 by lusanche         ###   ########.fr       */
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

int		ps_storebuff(char buffer[MAX], int fd)
{
	int		j;
	int		nb;

	j = 0;
	while ((nb = read(fd, &buffer[j], 1)) > 0)
	{
		if (buffer[j] == '\n')
		{
			buffer[j] = '\0';
			if (j < 2 || j > 3)
				ps_error(-1);
			if (ps_validop(buffer) == 0)
				ps_error(-1);
			return (1);
		}
		else
			++j;
	}
	if (j)
	{
		if (fd == 0)
			ft_printf("\n");
		ps_error(-1);
	}
	return (0);
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

void	ps_runbuff(char buffer[MAX], t_stack *a, t_stack *b)
{
	t_funpa		f[343];
	int			i;

	f[212] = &ps_sa;
	f[213] = &ps_sb;
	f[230] = &ps_ss;
	f[209] = &ps_pa;
	f[210] = &ps_pb;
	f[211] = &ps_ra;
	f[214] = &ps_rb;
	f[228] = &ps_rr;
	f[325] = &ps_rra;
	f[326] = &ps_rrb;
	f[342] = &ps_rrr;
	i = 0;
	f[ps_hash(buffer)](a, b);
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
