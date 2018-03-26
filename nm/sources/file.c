/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeclerc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 12:36:15 by fdeclerc          #+#    #+#             */
/*   Updated: 2018/03/26 12:58:01 by fdeclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/nm.h"

t_file		*ft_read_file(char *filename)
{
	int		fd;
	t_file	*file;

	file = (t_file*)malloc(sizeof(t_file));
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	if (fstat(fd, &file->buf) < 0)
		return (NULL);
	if ((file->ptr = mmap(0, file->buf.st_size, PROT_READ,
					MAP_PRIVATE, fd, 0)) == MAP_FAILED)
		return (NULL);
	return (file);
}
