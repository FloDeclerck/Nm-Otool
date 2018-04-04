/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeclerc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 12:18:02 by fdeclerc          #+#    #+#             */
/*   Updated: 2018/04/04 16:24:43 by fdeclerc         ###   ########.fr       */
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

# include "../../libft/libft.h"

typedef struct		s_data
{
	struct stat		buf;
	unsigned int	magic_number;
	void			*ptr;
}					t_data;

t_data		*ft_read_file(char *filename);

int			ft_nm(t_data *data);

void		ft_handle_64(struct mach_header_64 *header, struct symtab_command *sym);

#endif
