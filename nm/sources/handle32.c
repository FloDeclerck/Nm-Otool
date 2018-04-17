/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle32.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeclerc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 11:32:13 by fdeclerc          #+#    #+#             */
/*   Updated: 2018/04/17 16:47:05 by fdeclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/nm.h"

void		ft_print_32(char *ptr, int nsyms, struct nlist *nl)
{
	int		i;
	char	addr[20];
	char	*str[nsyms];

	i = 0;
	while (i < nsyms)
	{
		ft_memset(addr, ' ', 19);
		addr[19] = 0;
		if (nl[i].n_type != 0x1)
			ft_print_addr(addr, nl[i].n_value, 15);
		addr[17] = ft_get_type(nl[i].n_type, nl[i].n_sect, nl[i].n_value);
		str[i] = ft_strjoin(addr, ptr + nl[i].n_un.n_strx);
		i++;
	}
	ft_sort_symbols(str, nsyms);
	i = 0;
	while (i < nsyms)
	{
		if (str[i][17] != '-')
			ft_putendl(str[i] + 8);
		free(str[i]);
		i++;
	}

}

void		ft_handle_32(struct mach_header *header,
		struct symtab_command *symtab)
{
	unsigned int	i;
	struct load_command	*lc;

	i = 0;
	lc = (struct load_command *)(header + 1);
	ft_section_number(lc, header->ncmds);
	while (i < header->ncmds)
	{
		if (lc->cmd == LC_SYMTAB)
		{
			symtab = (void *)lc;
			break;
		}
		i++;
	}
	if (symtab == NULL)
		ft_putstr("No symbols found\n");
	ft_print_32((void *)header + symtab->stroff, symtab->nsyms,
			(void *)header + symtab->symoff);
}
