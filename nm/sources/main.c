/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeclerc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 12:25:33 by fdeclerc          #+#    #+#             */
/*   Updated: 2018/04/04 16:43:06 by fdeclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/nm.h"

//void	ft_read_args()

int		main(int ac, char **av)
{

	if (ac != 2)
	{
		ft_putstr("ERROR : Not enough arguments\n");
		return (-1);
	}
	ft_read_file(av[1]);
	return (0);
}
