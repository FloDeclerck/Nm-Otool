/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeclerc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 12:36:15 by fdeclerc          #+#    #+#             */
/*   Updated: 2018/04/05 15:20:21 by fdeclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/nm.h"

/*t_data		*ft_read_file(char *file)
{
	int		fd;
	t_data	*data;

	data = (t_data*)malloc(sizeof(t_data));
	fd = open(file, O_RDONLY);
	if (fd < 0 || fstat(fd, &data->buf) < 0 ||
			(data->ptr = mmap(0, data->buf.st_size, PROT_READ,
				MAP_PRIVATE, fd, 0)) == MAP_FAILED)
		return (NULL);
	ft_nm(data);
	data->magic_number = *(unsigned int *)(data->ptr);
	return (data);
}*/
