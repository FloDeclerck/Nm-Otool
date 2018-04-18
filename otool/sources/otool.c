/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otool.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeclerc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 17:27:11 by fdeclerc          #+#    #+#             */
/*   Updated: 2018/04/18 12:30:33 by fdeclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/otool.h"

void			ft_handle_otool(void *ptr, struct load_command *lc, size_t size)
{
	int			res;
	uint32_t	ncmds;

	res = 0;
	ncmds = ((struct mach_header *)lc)->ncmds;
	lc = (void *)lc + size;
	while (ncmds-- > 0)
	{
		if (lc->cmd == LC_SEGMENT)
		{
			res |= ft_handle_otool32(ptr, (void *)lc +
					sizeof(struct segment_command),
					((struct segment_command *)lc)->nsects);
		}
		if (lc->cmd == LC_SEGMENT_64)
		{
			res |= ft_handle_otool64(ptr, (void *)lc +
					sizeof(struct segment_command_64),
					((struct segment_command_64 *)lc)->nsects);
		}
		lc = (void *)lc + lc->cmdsize;
	}
	if (res == 0)
		ft_putstr("__TEXT Section Unknown\n");
}

int		ft_otool(t_data *data)
{
	if (data->magic_number == MH_MAGIC_64)
		ft_handle_otool(data, data->ptr, sizeof(struct mach_header_64));
	else if (data->magic_number == MH_MAGIC)
		ft_handle_otool(data, data->ptr, sizeof(struct mach_header));
//	else if (data->magic_number == FAT_CIGAM)
//		return (ft_handle_otoolfat(data->ptr, 0) + 2);
	else
		return (0);
	return (1);
}
