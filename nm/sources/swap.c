/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeclerc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 10:45:07 by fdeclerc          #+#    #+#             */
/*   Updated: 2018/04/17 16:09:45 by fdeclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/nm.h"

void		ft_swap_addr(void *a, void *b, size_t size)
{
	size_t	i;
	unsigned char tmp;
	unsigned char *addr_a;
	unsigned char *addr_b;

	addr_a = (unsigned char *)a;
	addr_b = (unsigned char *)b;

	i = 0;

	while (i < size)
	{
		tmp = addr_a[i];
		addr_a[i] = addr_b[i];
		addr_b[i] = tmp;
		i++;
	}
}

uint32_t		ft_swap_uint32(uint32_t num)
{
	num = ((num << 8) & 0xFF00FF00) | ((num >> 8) & 0xFF00FF);
	return (num >> 16) | (num << 16);
}

int32_t			ft_swap_int32(int32_t num)
{
	num = ((num << 8) & 0xFF00FF00) | ((num >> 8) & 0xFF00FF);
	return (num << 16) | ((num >> 16) & 0xFFFF);
}
