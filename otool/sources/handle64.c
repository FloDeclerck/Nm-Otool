/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle64.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeclerc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 11:46:16 by fdeclerc          #+#    #+#             */
/*   Updated: 2018/04/18 12:24:15 by fdeclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/otool.h"

int		ft_handle_otool64(void *ptr, struct section_64 *sect, uint32_t nsects)
{
	while (nsects--)
	{
		if (ft_strcmp(sect->sectname, SECT_TEXT) == 0 &&
				ft_strcmp(sect->segname, SEG_TEXT) == 0)
		{
			ft_print_section(ptr, (void*)sect, sizeof(*sect));
			return (1);
		}
		sect += 1;
	}
	return (0);
}
