/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeclerc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 12:36:15 by fdeclerc          #+#    #+#             */
/*   Updated: 2018/04/04 16:24:49 by fdeclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/nm.h"

t_data		*ft_read_file(char *file)
{
	int		fd;
	t_data	*data;

	data = (t_data*)malloc(sizeof(t_data));
	if ((fd = open(file, O_RDONLY)) < 0)
		ft_putstr("ERROR : Open\n");
	if (fstat(fd, &data->buf) < 0)
		ft_putstr("ERROR : Fstat\n");
	if ((data->ptr = mmap(0, data->buf.st_size, PROT_READ,
					MAP_PRIVATE, fd, 0)) == MAP_FAILED)
		printf("ERROR : Mmap\n");
	ft_nm(data);
	if (munmap(data->ptr, data->buf.st_size) < 0)
		ft_putstr("ERROR : Munmap");
	return (data);
}
