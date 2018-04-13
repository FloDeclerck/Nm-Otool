/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle64.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeclerc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 12:14:20 by fdeclerc          #+#    #+#             */
/*   Updated: 2018/04/13 13:13:31 by fdeclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/nm.h"

void		ft_print_64(char *ptr, int nsyms, struct nlist_64 *nl)
{
	int		i;
	char	hex[20];
	char	*strings[nsyms];

	i = -1;
	while (++i < nsyms)
	{
		ft_memset(hex, ' ', 19);
		hex[19] = 0;
		hex[17] = ft_get_type(nl[i].n_type, nl[i].n_sect,
				nl[i].n_value);
		if (nl[i].n_type != 0x1)
			ft_print_addr(hex, nl[i].n_value, 15);
		strings[i] = ft_strjoin(hex, ptr + nl[i].n_un.n_strx);
	}
	ft_sort_symbols(strings, nsyms);
	i = -1;
	while (++i < nsyms)
	{
		if (strings[i][17] != '-')
			ft_putendl(strings[i]);
		free(strings[i]);
	}
}

 void		ft_handle_64(struct mach_header_64 *header,
		struct symtab_command *sym)
{
	unsigned int		i;
	struct load_command *lc;

	lc = (struct load_command *)(header + 1);
	ft_section_number(lc,  header->ncmds);
	i = 0;
	while (i < header->ncmds)
	{
		if (lc->cmd == LC_SYMTAB)
		{
			sym = (void *)lc;
			break ;
		}
		lc = (void *)lc + lc->cmdsize;
	}
	if (sym == NULL)
		ft_putstr("No symbols found\n");
	ft_print_64((void *)header + sym->stroff, sym->nsyms, (void *)header +
			 sym->symoff);
}
