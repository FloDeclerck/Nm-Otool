/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle64.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeclerc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 12:14:20 by fdeclerc          #+#    #+#             */
/*   Updated: 2018/04/05 15:44:36 by fdeclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/nm.h"

void		ft_print_64(char *ptr, int nsyms, struct nlist_64 *nl)
{
	int		i;
	char	hex[20];
	char	*strings[nsyms];

	i = -1;
	while (i < nsyms)
	{
		printf("%s\n", ptr + nl[i].n_un.n_strx);
		i++;
	}
}

 void		ft_handle_64(struct mach_header_64 *header,
		struct symtab_command *sym)
{
	unsigned int		i;
	struct load_command *lc;

	i = 0;
	lc = (struct load_command *)(header + 1);
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
