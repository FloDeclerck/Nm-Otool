/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle64.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeclerc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 12:14:20 by fdeclerc          #+#    #+#             */
/*   Updated: 2018/04/26 14:17:34 by fdeclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/nm.h"

void					ft_print_64(char *ptr, int nsyms, struct nlist_64 *nl)
{
	int					i;
	char				addr[20];
	char				*str[nsyms];

	i = -1;
	while (++i < nsyms)
	{
		ft_memset(addr, ' ', 19);
		addr[19] = 0;
		addr[17] = ft_get_type(nl[i].n_type, nl[i].n_sect,
				nl[i].n_value);
		if (nl[i].n_type != 0x1)
			ft_print_addr(addr, nl[i].n_value, 15);
		str[i] = ft_strjoin(addr, ptr + nl[i].n_un.n_strx);
	}
	ft_sort_symbols(str, nsyms);
	i = -1;
	while (++i < nsyms)
	{
		if (str[i][17] != '-')
			ft_putendl(str[i]);
		free(str[i]);
	}
}

void					ft_handle_64(struct mach_header_64 *header,
		struct symtab_command *sym)
{
	unsigned int		i;
	struct load_command	*lc;

	lc = (struct load_command *)(header + 1);
	ft_section_number(lc, header->ncmds);
	i = 0;
	while (i++ < header->ncmds)
	{
		if (lc->cmd == LC_SYMTAB)
		{
			sym = (void *)lc;
			break ;
		}
		lc = (void *)lc + lc->cmdsize;
	}
	if (sym == NULL)
		return (ft_putstr("No symbols found\n"));
	ft_print_64((void *)header + sym->stroff, sym->nsyms, (void *)header +
			sym->symoff);
}
