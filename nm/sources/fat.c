/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeclerc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 15:53:49 by fdeclerc          #+#    #+#             */
/*   Updated: 2018/04/26 12:53:19 by fdeclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/nm.h"

int			ft_handle_fat(struct fat_header *header, uint32_t nfat_arch)
{
	t_data				data;
	struct fat_arch		*arch;
	struct mach_header	*mach;

	nfat_arch = ft_swap_uint32(header->nfat_arch);
	arch = (void *)(header + 1);
	while (nfat_arch--)
	{
		mach = (void *)((void *)header + ft_swap_uint32(arch->offset));
		if (mach->magic == MH_MAGIC_64 && mach->cputype == CPU_TYPE_X86_64)
		{
			data.ptr = (void *)header + ft_swap_uint32(arch->offset);
			if (__POINTER_WIDTH__ == 64)
				break ;
		}
		if (mach->magic == MH_MAGIC && mach->cputype == CPU_TYPE_X86)
		{
			data.ptr = (void *)header + ft_swap_uint32(arch->offset);
			if (__POINTER_WIDTH__ == 32)
				break ;
		}
		arch = arch + 1;
	}
	data.magic_number = *(unsigned int *)data.ptr;
	return (ft_nm(&data));
}
