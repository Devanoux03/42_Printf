/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 14:30:51 by dernst            #+#    #+#             */
/*   Updated: 2024/12/05 21:21:01 by dernst           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_intlen(long int n)
{
	size_t	count;

	if (n < 0)
		n *= -1;
	count = 0;
	if (n == 0)
		n++;
	while (n > 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}
