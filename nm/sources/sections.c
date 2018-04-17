/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sections.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeclerc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 11:01:56 by fdeclerc          #+#    #+#             */
/*   Updated: 2018/04/17 16:38:08 by fdeclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/nm.h"

void			*ft_init_sections(t_section *sect)
{
	if (sect == NULL)
		sect = malloc(sizeof(t_section));
	sect->text = 0;
	sect->data = 0;
	sect->bss = 0;
	sect->nsects = 1;
	return (sect);
}

void			ft_get_sections(t_section *sect, uint32_t i,
		struct section *s, size_t size)
{
	while (i > 0)
	{
		if (ft_strcmp(s->sectname, SECT_TEXT) == 0 &&
				ft_strcmp(s->segname, SEG_TEXT) == 0)
			sect->text = sect->nsects;
		else if (ft_strcmp(s->sectname, SECT_DATA) == 0 &&
				ft_strcmp(s->segname, SEG_DATA) == 0)
			sect->data = sect->nsects;
		else if (ft_strcmp(s->sectname, SECT_BSS) == 0 &&
			ft_strcmp(s->segname, SEG_DATA) == 0)
				sect->bss = sect->nsects;
		s = (void *)s + size;
		sect->nsects++;
		i--;
	}
}

t_section		*ft_section_number(struct load_command *lc, uint32_t ncmds)
{
	static t_section	*sect = NULL;

	if (lc == NULL)
		return (sect);
	sect = ft_init_sections(sect);
	while (ncmds > 0)
	{
		if (lc->cmd == LC_SEGMENT)
			ft_get_sections(sect, ((struct segment_command*)lc)->nsects,
					(void *)lc + sizeof(struct segment_command),
					sizeof(struct section));
		if (lc->cmd == LC_SEGMENT_64)
			ft_get_sections(sect, ((struct segment_command_64*)lc)->nsects,
					(void *)lc + sizeof(struct segment_command_64),
					sizeof(struct section_64));
		lc = (void *)lc + lc->cmdsize;
		ncmds--;
	}
	return (sect);
}
