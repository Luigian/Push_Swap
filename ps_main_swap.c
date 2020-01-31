/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_main_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 09:42:37 by lusanche          #+#    #+#             */
/*   Updated: 2020/01/30 20:47:52 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_checkpa(t_stack *a, t_stack *b, int *nko)
{
	int		prev;
	int		i;

	if (b->array[b->top - 1] > a->array[a->top - 1])
		*nko += 1;
	i = 0;
	prev = b->array[i];
	while (i < b->top - 1)
	{
		if (b->array[i] < prev)
			*nko += 1;
		prev = b->array[i];
		++i;
	}
}

int		ps_checksort(t_stack *a, t_stack *b, int *nko)
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
	if (b->top > 0)
		ps_checkpa(a, b, nko);
	return (0);
}

int		ps_hdassign(t_node *head, t_stack *a, t_stack *b, int *lv)
{
	head->name = "head";
	head->a = a;
	head->b = b;
	if (!(head->p = malloc(sizeof(t_stack))))
		ps_error(-2);
	head->p->top = 0;
	head->hd = head;
	head->lv = lv;
	if (ps_checksort(head->a, head->b, &head->nko))
		return (1);
	head->pko = head->nko;
	head->hko = &head->nko;
	return (0);
}

int		ps_inithead(t_node *head, t_stack *a, t_stack *b)
{
	int		lv;
	int		i;

	lv = 0;
	if (ps_hdassign(head, a, b, &lv))
		return (1);
	i = 0;
	while (i < 8)
	{
		head->br[i] = NULL;
		++i;
	}
	while (*head->lv < 20)
	{
		i = 0;
		while (i < 8)
		{
			if (ps_initnode(head, i))
				return (1);
			++i;
		}
		*head->lv += 1;
	}
	return (0);
}

int		main(int argc, char **argv)
{
	t_stack		a;
	t_stack		b;
	t_node		head;

	if (argc < 2)
		return (0);
	ps_storestacks(&a, &b, argc - 1, argv + 1);
	ps_putstack(&a);
	ps_inithead(&head, &a, &b);
	ps_freenodes(&head);
	system("leaks push_swap");
	return (0);
}
