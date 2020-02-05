/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_swap_03.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 11:04:19 by lusanche          #+#    #+#             */
/*   Updated: 2020/02/04 21:03:35 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ps_checksort02(t_stack *a, t_stack *b, int *nko)
{
	int		prev;
	int		i;

	i = 0;
	*nko = 0;
	prev = a->array[i];
	while (i < a->top)
	{
		if (a->array[i] > prev)
			*nko += 1;
		prev = a->array[i];
		++i;
	}
	if (*nko == 0 && b->top == 0)
		return (1);
	return (0);
}

void	ps_doop(char *s, t_stack *a, t_stack *b)
{
	if (ft_strcmp(s, "sa") == 0)
	{
		sa(a, b);
		ft_printf("sa\n");
	}
	else if (ft_strcmp(s, "sb") == 0)
	{
		sb(a, b);
		ft_printf("sb\n");
	}
	else if (ft_strcmp(s, "pa") == 0)
	{
		pa(a, b);
		ft_printf("pa\n");
	}
	else if (ft_strcmp(s, "pb") == 0)
	{
		pb(a, b);
		ft_printf("pb\n");
	}
	else if (ft_strcmp(s, "ra") == 0)
	{
		ra(a, b);
		ft_printf("ra\n");
	}
	else if (ft_strcmp(s, "rb") == 0)
	{
		rb(a, b);
		ft_printf("rb\n");
	}
	else if (ft_strcmp(s, "rra") == 0)
	{
		rra(a, b);
		ft_printf("rra\n");
	}
	else if (ft_strcmp(s, "rrb") == 0)
	{
		rrb(a, b);
		ft_printf("rrb\n");
	}
}

int		ps_findbigger(t_stack *b)
{
	int		i;
	int		bigger;
	int		ret;

	i = 0;
	bigger = b->array[i];
	ret = 0;
	while (i < b->top)
	{
		if (b->array[i] > bigger)
		{
			ret = i;
			bigger = b->array[i];
		}
		++i;
	}
	return (ret);
}

void	ps_movebigger(int i, t_stack *a, t_stack *b)
{
	if (i == b->top - 2)
		ps_doop("sb", a, b);
	else if (i >= b->top / 2)
	{
		while (i < b->top - 1)
		{
			ps_doop("rb", a, b);
			++i;
		}
	}
	else
	{
		while (i + 1 > 0)
		{
			ps_doop("rrb", a, b);
			--i;
		}
	}
}

void	ps_fillsort(int *sort, t_stack *a)
{
	int		i;
	int		j;

	i = 0;
	while (i < a->top)
	{
		j = 0;
		while (i && a->array[j] <= sort[i - 1])
			++j;
		sort[i] = a->array[j];
		while (j < a->top)
		{
			if (a->array[j] < sort[i] )
			{
				if (i == 0)
					sort[i] = a->array[j];
				else if (a->array[j] > sort[i - 1])
					sort[i] = a->array[j];
			}
			++j;
		}
		++i;
	}
}

int		ps_ingroup(int n, int *sort, int group)
{
	int		i;

	i = 0;
	while (i < group)
	{
		if (n == sort[i])
			return (1);
		++i;
	}
	return (0);
}

int		ps_findcloser(t_stack *a, int *sort, int group)
{
	int		i;
	int		left;
	int		right;

	i = 0;
	while (i < a->top)
	{
		if (ps_ingroup(a->array[i], sort, group))
		{
			left = i;
			break ;
		}
		++i;
	}
	if (i == a->top)
	   return (-1);
	i = a->top - 1;
	while (i >= 0)
	{
		if (ps_ingroup(a->array[i], sort, group))
		{
			right = i;
			break ;
		}
		--i;
	}
	if (i < 0)
	   return (-1);
	if (left < ((a->top - 1) - right))
		return (left);
	return (right);	
}

void	ps_movescloser(int i, t_stack *a, t_stack *b)
{
	if (i == a->top - 2)
		ps_doop("sa", a, b);
	else if (i >= a->top / 2)
	{
		while (i < a->top - 1)
		{
			ps_doop("ra", a, b);
			++i;
		}
	}
	else
	{
		while (i + 1 > 0)
		{
			ps_doop("rra", a, b);
			--i;
		}
	}
}

void	ps_selection(t_stack *a, t_stack *b)
{
	int		sort[a->top];
	int		i;
	int		group;
//	int		ko;

	ps_fillsort(sort, a);
/*	i = 0;
	while (i < a->top)
		ft_printf("%d ", sort[i++]);
	ft_printf("\n");
	ko = 0;
*/	group = 20;
	while (a->top)
	{
		i = ps_findcloser(a, sort, group);
		if (i == -1)
			group += 20; 
		else 
		{
			if (i != a->top - 1)
				ps_movescloser(i, a, b);
			ps_doop("pb", a, b);
		}
	}
//	ps_putstack(a);
//	ps_putstack(b);
	while (b->top)
	{
		if ((i = ps_findbigger(b)) != b->top - 1)
			ps_movebigger(i, a, b);
		ps_doop("pa", a, b);
	}
//	ps_putstack(a);
//	ps_putstack(b);
}



	
	
/*	
	
	ko = 0;
	while (ps_checksort02(a, b, &ko) == 0)
	{
		if (ko)
		{
//			range = a->top >= 50 ? 15 : 8; 
			range = 15; 
			if ((i = ps_findsmaller(a, range)) != a->top - 1)
				ps_movesmaller(i, a, b);
			ps_doop("pb", a, b);
		}
		else
		{
	   		if ((i = ps_findbigger(b)) != b->top - 1)
				ps_movebigger(i, a, b);
			ps_doop("pa", a, b);
		}
	}
}
*/
/*
int		ps_checksort02(t_stack *a, t_stack *b, int *nko)
{
	int		prev;
	int		i;

	i = 0;
	*nko = 0;
	prev = a->array[i];
	while (i < a->top)
	{
		if (a->array[i] > prev)
			*nko += 1;
		prev = a->array[i];
		++i;
	}
	if (*nko == 0 && b->top == 0)
		return (1);
	return (0);
}

void	ps_doop(char *s, t_stack *a, t_stack *b)
{
	if (ft_strcmp(s, "sa") == 0)
	{
		sa(a, b);
		ft_printf("sa\n");
	}
	else if (ft_strcmp(s, "pa") == 0)
	{
		pa(a, b);
		ft_printf("pa\n");
	}
	else if (ft_strcmp(s, "pb") == 0)
	{
		pb(a, b);
		ft_printf("pb\n");
	}
	else if (ft_strcmp(s, "ra") == 0)
	{
		ra(a, b);
		ft_printf("ra\n");
	}
	else if (ft_strcmp(s, "rra") == 0)
	{
		rra(a, b);
		ft_printf("rra\n");
	}
}

void	ps_movesmaller(int i, t_stack *a, t_stack *b)
{
	if (i == a->top - 2)
		ps_doop("sa", a, b);
	else if (i >= a->top / 2)
	{
		while (i < a->top - 1)
		{
			ps_doop("ra", a, b);
			++i;
		}
	}
	else
	{
		while (i + 1 > 0)
		{
			ps_doop("rra", a, b);
			--i;
		}
	}
}

int		ps_findsmaller(t_stack *a, int range)
{
	int		i;
	int		smaller;
	int		ret;

	i = 0;
	smaller = a->array[i];
	ret = 0;
	while (i < a->top && i < range)
	{
		if (a->array[i] < smaller)
		{
			ret = i;
			smaller = a->array[i];
		}
		++i;
	}
	i = a->top - 1;
	while (i >= 0 && i > a->top - range)
	{
		if (a->array[i] < smaller)
		{
			ret = i;
			smaller = a->array[i];
		}
		--i;
	}
	return (ret);
}


int		ps_findbigger(t_stack *b)
{
	int		i;
	int		bigger;
	int		ret;

	i = 0;
	bigger = b->array[i];
	ret = 0;
	while (i < b->top)
	{
		if (b->array[i] > bigger)
		{
			ret = i;
			bigger = b->array[i];
		}
		++i;
	}
	return (ret);
}

void	ps_movebigger(int i, t_stack *a, t_stack *b)
{
	if (i == b->top - 2)
		ps_doop("sb", a, b);
	else if (i >= b->top / 2)
	{
		while (i < b->top - 1)
		{
			ps_doop("rb", a, b);
			++i;
		}
	}
	else
	{
		while (i + 1 > 0)
		{
			ps_doop("rrb", a, b);
			--i;
		}
	}
}

void	ps_selection(t_stack *a, t_stack *b)
{
	int		ko;
	int		i;
	int		range;

	ko = 0;
	while (ps_checksort02(a, b, &ko) == 0)
	{
		if (ko)
		{
//			range = a->top >= 50 ? 15 : 8; 
			range = 15; 
			if ((i = ps_findsmaller(a, range)) != a->top - 1)
				ps_movesmaller(i, a, b);
			ps_doop("pb", a, b);
		}
		else
		{
	   		if ((i = ps_findbigger(b)) != b->top - 1)
				ps_movebigger(i, a, b);
			ps_doop("pa", a, b);
		}
	}
}
*/
/*
void	ps_selection(t_stack *a, t_stack *b)
{
	int		ko;
	int		i;
	int		range;

	ko = 0;
	i = 0;
	range = 6;
	while (ps_checksort02(a, b, &ko) == 0)
	{
		if (ko == 0)
			ps_doop("pa", a, b);
		else if ((i = ps_findsmall_2(a, range)) != a->top - 1)
			ps_movesmall(i, a, b);
		else
			ps_doop("pb", a, b);
		ko = 0;
	}		
}
*/	
/*
int		ps_checksort02(t_stack *a, t_stack *b, int *nko)
{
	int		prev;
	int		i;

	i = 0;
	prev = a->array[i];
	while (i < a->top)
	{
		if (a->array[i] > prev)
			*nko += 1;
		prev = a->array[i];
		++i;
	}
	if (*nko == 0 && b->top == 0)
		return (1);
	return (0);
}

void	ps_doop(char *s, t_stack *a, t_stack *b)
{
	if (ft_strcmp(s, "sa") == 0)
	{
		sa(a, b);
		ft_printf("sa\n");
	}
	else if (ft_strcmp(s, "pa") == 0)
	{
		pa(a, b);
		ft_printf("pa\n");
	}
	else if (ft_strcmp(s, "pb") == 0)
	{
		pb(a, b);
		ft_printf("pb\n");
	}
	else if (ft_strcmp(s, "ra") == 0)
	{
		ra(a, b);
		ft_printf("ra\n");
	}
	else if (ft_strcmp(s, "rra") == 0)
	{
		rra(a, b);
		ft_printf("rra\n");
	}
}

int		ps_findsmall(t_stack *a)
{
	int		i;
	int		small;
	int		ret;

	i = 0;
	small = a->array[i];
	ret = 0;
	while (i < a->top)
	{
		if (a->array[i] < small)
		{
			ret = i;
			small = a->array[i];
		}
		++i;
	}
	return (ret);
}

void	ps_movesmall(int i, t_stack *a, t_stack *b)
{
	if (i == a->top - 2)
		ps_doop("sa", a, b);
	else if (i >= a->top / 2)
	{
		while (i < a->top - 1)
		{
			ps_doop("ra", a, b);
			++i;
		}
	}
	else
	{
		while (i + 1 > 0)
		{
			ps_doop("rra", a, b);
			--i;
		}
	}
}

void	ps_selection(t_stack *a, t_stack *b)
{
	int		ko;
	int		i;

	ko = 0;
	i = 0;
	while (ps_checksort02(a, b, &ko) == 0)
	{
		if (ko == 0)
			ps_doop("pa", a, b);
		else if ((i = ps_findsmall(a)) != a->top - 1)
			ps_movesmall(i, a, b);
		else
			ps_doop("pb", a, b);
		ko = 0;
	}
}
*/
