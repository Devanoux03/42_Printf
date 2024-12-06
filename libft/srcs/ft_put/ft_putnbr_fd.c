/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 18:49:20 by dernst            #+#    #+#             */
/*   Updated: 2024/12/05 21:21:51 by dernst           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

size_t	ft_putnbr_fd(int n, int fd, size_t *len)
{
	char		current;
	long int	nb;

	nb = n;
	if (nb < 0)
	{
		write(fd, "-", 1);
		nb *= -1;
		*len += 1;
	}
	if (nb > 9)
	{
		current = (nb % 10) + '0';
		ft_putnbr_fd(nb / 10, fd, len);
		write(fd, &current, 1);
		*len += 1;
	}
	else
	{
		*len += 1;
		current = nb + '0';
		write(fd, &current, 1);
	}
	return (*len);
}
