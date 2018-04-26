/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otool.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeclerc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 17:28:33 by fdeclerc          #+#    #+#             */
/*   Updated: 2018/04/26 11:23:43 by fdeclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OTOOL_H
# define OTOOL_H

# include "../../libft/libft.h"
# include "../../nm/includes/nm.h"

int		ft_otool(t_data *data);

int		ft_handle_otool32(void *ptr, struct section *section, uint32_t nsects);

int		ft_handle_otool64(void *ptr, struct section_64 *sect, uint32_t nsects);

void	ft_print_section(t_data *data, struct section *sect, size_t size);

#endif
