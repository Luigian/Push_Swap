/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 19:12:42 by lusanche          #+#    #+#             */
/*   Updated: 2020/01/17 20:45:21 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ulibft/libft.h"
# define MAX_CAPACITY 10

typedef struct	s_stack
{
	int			array[MAX_CAPACITY];
	int			top;
}				t_stack;

void			ps_putstack(t_stack *a);

#endif