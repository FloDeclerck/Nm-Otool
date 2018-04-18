/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeclerc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 12:18:02 by fdeclerc          #+#    #+#             */
/*   Updated: 2018/04/18 12:30:56 by fdeclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NM_H
# define NM_H

# include <stdio.h>
# include <sys/mman.h>
# include <mach-o/loader.h>
# include <mach-o/nlist.h>
# include <mach-o/fat.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <stdlib.h>
# include <stdarg.h>

# include "../../libft/libft.h"

typedef struct		s_data
{
	struct stat		buf;
	unsigned int	magic_number;
	void			*ptr;
}					t_data;

typedef struct		s_section
{
	uint32_t		text;
	uint32_t		data;
	uint32_t		bss;
	uint32_t		nsects;
}					t_section;

t_data		*ft_read_file(char *filename);

int			ft_nm(t_data *data);

void		ft_handle_64(struct mach_header_64 *header, struct symtab_command *sym);
void		ft_handle_32(struct mach_header *header, struct symtab_command *symtab);
int			ft_handle_fat(struct fat_header *header, uint32_t nfat_arch);

uint32_t	ft_swap_uint32(uint32_t num);

void		*ft_init_sections(t_section *sect);

void		ft_get_sections(t_section *sect, uint32_t i, struct section *s, size_t size);

t_section	*ft_section_number(struct load_command *lc, uint32_t ncmds);

void		ft_swap_addr(void *a, void *b, size_t size);

void		ft_print_addr(char *ptr, unsigned long addr, int size);

void		ft_sort_symbols(char **a, size_t size);

char		ft_get_type(uint16_t n_type, uint16_t n_sect, uint64_t n_value);

#endif
