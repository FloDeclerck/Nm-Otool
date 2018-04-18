/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   section.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeclerc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 11:45:53 by fdeclerc          #+#    #+#             */
/*   Updated: 2018/04/18 12:24:56 by fdeclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/otool.h"

void		ft_print_hexa(uint64_t num, int depth)
{
	if (depth == 0)
		return ;
	ft_print_hexa(num >> 4, depth - 1);
	num = num & 0xF;
	if (num < 10)
		num += '0';
	else
		num += 'a' - 10;
	write(1, &num, 1);
}

void		ft_init_section(struct section_64 *sect64, struct section *sect,
		size_t size)
{
	ft_memcpy(sect64, sect, size);
	if (size == sizeof(struct section_64))
		return ;
	sect64->addr = sect->addr;
	sect64->size = sect->size;
	sect64->offset = sect->offset;
	sect64->align = sect->align;
	sect64->reloff = sect->reloff;
	sect64->nreloc = sect->nreloc;
	sect64->flags = sect->flags;
}

void		ft_print_schema(struct section_64 sect64)
{
	ft_putchar('(');
	ft_putstr(sect64.segname);
	ft_putchar(',');
	ft_putstr(sect64.sectname);
	ft_putstr(") section\n");
}

void		ft_print_section(t_data *data, struct section *sect, size_t size)
{
	void		*start;
	uint32_t	offset;
	uint32_t	i;
	uint8_t		word_byte;
	struct section_64 sect64;

	ft_init_section(&sect64, sect, size);
	ft_print_schema(sect64);
	start = (void *)data->ptr + sect64.offset;
	offset = 0;

	while (offset < sect64.size)
	{
		ft_print_hexa((uint64_t)(sect64.addr + offset),
				(data->magic_number == MH_MAGIC ? 8 : 16));
		i = 0 * (int)write(1, " ", 1);
		while (i < 16 * sizeof(char) && offset + i < sect64.size)
		{
			word_byte = *(uint8_t*)(start + offset + i);
			ft_print_hexa(word_byte, 2);
			write(1, " ", 1);
			i += sizeof(char);
		}
		write(1, "\n", 1);
		offset += i;
	}
}
