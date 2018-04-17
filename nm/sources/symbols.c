/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   symbols.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeclerc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 10:24:51 by fdeclerc          #+#    #+#             */
/*   Updated: 2018/04/17 16:48:34 by fdeclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/nm.h"

void		ft_print_addr(char *ptr, unsigned long addr, int size)
{
	if (size > 0)
		ft_print_addr(ptr, addr >> 4, size - 1);
	addr -= (addr >> 4) << 4;
	if (addr < 10)
		addr += '0';
	else
		addr += 'a' - 10;
	ptr[size] = addr;
	//write(1, &addr, 1);
}

void		ft_sort_symbols(char **a, size_t size)
{
	int		res;
	size_t	i;
	size_t	j;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			res = ft_strcmp(a[j] + 19, a[j + 1] + 19);
			if (res > 0 || (res == 0 && ft_strncmp(a[j] + 17,
							a[j + 1] + 17, 1) < 0))
				ft_swap_addr(a + j, a + j + 1, sizeof(char *));
			j++;
		}
		i++;
	}
}
char		ft_get_type(uint16_t n_type, uint16_t n_sect, uint64_t n_value)
{
	char	c;

	c = n_type;
	if (c & N_STAB)
		return ('-');
	c = c & N_TYPE;
	if (c == N_UNDF && n_value != 0)
		c = 'c';
	else if ((c == N_UNDF && n_value == 0) || c == N_PBUD)
		c = 'u';
	else if (c == N_ABS)
		c = 'a';
	else if (c == N_SECT && n_sect == ft_section_number(NULL, 0)->text)
		c = 't';
	else if (c == N_SECT && n_sect == ft_section_number(NULL, 0)->data)
		c = 'd';
	else if (c == N_SECT && n_sect == ft_section_number(NULL, 0)->bss)
		c = 'b';
	else if (c == N_SECT)
		c = 's';
	else
		c = (c == N_INDR ? 'i' : '?');
	if ((n_type & N_EXT) && c != '?')
		c -= 32;
	return (c);
}
