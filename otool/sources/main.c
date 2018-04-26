/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeclerc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 17:27:30 by fdeclerc          #+#    #+#             */
/*   Updated: 2018/04/26 13:36:58 by fdeclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/otool.h"

t_data		*ft_read_file(char *file)
{
	int		fd;
	t_data	*data;

	fd = open(file, O_RDONLY);
	data = (t_data *)malloc(sizeof(t_data));
	if (fd < 0)
		return (NULL);
	if (fstat(fd, &(data->buf)) < 0)
		return (NULL);
	if ((data->ptr = mmap(0, data->buf.st_size, PROT_READ, MAP_PRIVATE, fd, 0))
			== MAP_FAILED)
		return (NULL);
	close(fd);
	data->magic_number = *(unsigned int *)(data->ptr);
	return (data);
}

void		ft_check_otool(t_data *data)
{
	int		arg;

	if (data == NULL)
		return (ft_putstr("ERROR: Not Valid File\n"));
	arg = ft_otool(data);
	if (arg == 0)
		return (ft_putstr("ERROR: Unkmown Type\n"));
	else if (arg == 2)
		return (ft_putstr("ERROR: Unknown Architecture\n"));
	munmap(data->ptr, data->buf.st_size);
	free(data);
}

int			main(int ac, char **av)
{
	int		i;

	if (ac < 2)
	{
		ft_putstr("Usage: ./ft_otool FILE1 [FILE2 ...]");
		return (1);
	}
	i = 1;
	while (i < ac)
	{
		ft_putstr(av[i]);
		ft_putstr(":\n");
		ft_check_otool(ft_read_file(av[i]));
		i++;
	}
	return (0);
}
