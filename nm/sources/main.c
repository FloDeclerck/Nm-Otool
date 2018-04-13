/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeclerc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 12:25:33 by fdeclerc          #+#    #+#             */
/*   Updated: 2018/04/13 12:40:50 by fdeclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/nm.h"

t_data		*ft_read_file(char *file)
{
	int fd;
	t_data *data;

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
	data->magic_number = *(unsigned int*)(data->ptr);
	return (data);
}

void	ft_check_file(t_data *data)
{
	int arg;

	if (data == NULL)
		return (ft_putstr("ERROR : Not Access to the File\n"));
	arg = ft_nm(data);
	if (arg == 0)
		return (ft_putstr("ERROR : No Type for the File\n"));
	else if (arg == 2)
		return (ft_putstr("ERROR : Not contain known architecture\n"));
	munmap(data->ptr, data->buf.st_size);
	free(data);
}

void		ft_print_multi(int size, ...)
{
	int i;
	va_list strings;

	va_start(strings, size);
	i = 0;
	while (i++ < size)
		ft_putstr(va_arg(strings, char*));
	va_end(strings);
}

int		main(int ac, char **av)
{
	int i;

	if (ac < 2)
	{
		ft_check_file(ft_read_file("a.out"));
		return (0);
	}
	i = 0;
	while (++i < ac)
	{
		if (ac > 2)
			ft_print_multi(3, "\n", av[i], ":\n");
		ft_check_file(ft_read_file(av[i]));
	}
	return (0);
}
