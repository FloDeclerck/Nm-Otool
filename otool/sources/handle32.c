/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle32.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeclerc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 11:16:38 by fdeclerc          #+#    #+#             */
/*   Updated: 2018/04/26 13:28:02 by fdeclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/otool.h"

int		ft_handle_otool32(void *ptr, struct section *section, uint32_t nsects)
{
	while (nsects--)
	{
		if (ft_strcmp(section->sectname, SECT_TEXT) == 0 &&
				ft_strcmp(section->segname, SEG_TEXT) == 0)
		{
			ft_print_section(ptr, (void *)section, sizeof(*section));
			return (1);
		}
		section += 1;
	}
	return (0);
}
