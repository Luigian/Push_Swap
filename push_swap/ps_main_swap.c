/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_main_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 09:42:37 by lusanche          #+#    #+#             */
/*   Updated: 2020/02/07 13:24:26 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int		ps_inithead(t_node *head, t_stack *a, t_stack *b, int fd)
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
			if (ps_initnode(head, i, fd))
				return (1);
			++i;
		}
		*head->lv += 1;
	}
	return (0);
}

void	ps_writeflag(int *fd)
{
	char	*line;

	line = NULL;
	ft_printf("Enter destination file path:\n");
	get_next_line(0, &line);
	if (ft_strlen(line) > 100)
		ps_error(-3);
	if ((*fd = creat(line, 0644)) == -1)
		ps_error(-3);
}

int		main(int argc, char **argv)
{
	t_stack		a;
	t_stack		b;
	t_node		head;
	int			fd;
	int			i;

	if (argc < 2)
		return (0);
	fd = 0;
	i = 0;
	if (ft_strcmp("-w", argv[1]) == 0)
	{
		ps_writeflag(&fd);
		ps_storestacks(&a, &b, argc - 2, argv + 2);
	}
	else
		ps_storestacks(&a, &b, argc - 1, argv + 1);
	if (a.top <= 6)
	{
		ps_inithead(&head, &a, &b, fd);
		ps_freenodes(&head);
	}
	else if (ps_checksort(&a, &b, &i) == 0)
		ps_selection(&a, &b, fd);
	return (0);
}
