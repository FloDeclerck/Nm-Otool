/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nm.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeclerc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 12:13:24 by fdeclerc          #+#    #+#             */
/*   Updated: 2018/04/17 16:33:01 by fdeclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/nm.h"

int		ft_nm(t_data *data)
{
	if (data->magic_number == MH_MAGIC_64)
		ft_handle_64(data->ptr, NULL);
	else if (data->magic_number == MH_MAGIC)
		ft_handle_32(data->ptr, NULL);
	else if (data->magic_number == FAT_CIGAM)
		return (ft_handle_fat(data->ptr, 0) + 2);
	else
		return (0);
	return (1);
}
