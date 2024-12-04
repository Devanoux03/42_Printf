/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:30:15 by dernst            #+#    #+#             */
/*   Updated: 2024/12/04 17:53:13 by dernst           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ft_printf_H
# define ft_printf_H
		
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <libft.h>

int	ft_printf(const char *format, ...);
static void check_pourcent(char c, va_list args);

#endif