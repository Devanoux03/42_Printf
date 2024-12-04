/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:22:17 by dernst            #+#    #+#             */
/*   Updated: 2024/11/28 22:06:12 by dernst           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

// If args == NULL so return NULL or print NULL i don't remember but do somethings
// If printf(0) return -1; or an error i don't remember too but don't worry all will be fine

static void check_pourcent(char c, va_list args)
{
	if(c == 'c')
		ft_putchar_fd(c, 1);
	if (c == 's')
		ft_putstr_fd(va_arg(args,char *), 1);
	if (c == 'p')
	{
		ft_putstr_fd("0x", 1);
		ft_putstr_fd(ft_putnbr_base(va_arg(args, long int), "0123456789abcdef"), 1);
	}
	if (c == 'd')
		ft_putnbr_fd(va_arg(args, int), 1);
	if (c == 'i')
		ft_putnbr_fd(va_arg(args, int), 1);
	if (c == 'u')
		ft_putstr_fd(ft_putunbr_base(va_arg(args, int), "0123456789"), 1);
	if (c == 'x')
		ft_putstr_fd(ft_putunbr_base(va_arg(args, int), "0123456789abcdef"), 1);
	if (c == 'X')
		ft_putstr_fd(ft_putunbr_base(va_arg(args, int), "0123456789ABCDEF"), 1);
	if (c == '%')
		ft_putchar_fd('%', 1);
}


int	ft_printf(const char *format, ...)
{
	int	i;
	va_list args;
	va_start(args, format);
	
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
			check_pourcent(format[++i], args);
		else
			ft_putchar_fd(format[i], 1);
		i++;
	}
	
	va_end(args);
	// if error inside the printf return -1
	//return(-1);
	return (0);
}

//int main(void)
//{

//	char *str = "0";
//	char *test = "test";
//	//int  i = -1234;
//	ft_printf("ft_printf : %p %p\n", test, str);
//	printf("printf : %p %p\n", test, str);
//	return (0);
//}