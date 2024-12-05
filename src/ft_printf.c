/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:22:17 by dernst            #+#    #+#             */
/*   Updated: 2024/12/05 22:55:07 by dernst           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "limits.h"

// Check each malloc with valgrind to see if it's create leaks 
// Dont have a git inside a git
// Check if we have the last version of libft inside the printfs
// Delete the main
// Find better name function to looks less mess
// Patch the makefiles

void	check_pourcent_str(char c, va_list args, size_t *len_write, char **temp)
{
	char	*current;

	if (c == 's')
	{
		current = va_arg(args, char *);
		if (current == NULL)
			*len_write += ft_putstr_fd("(null)", 1);
		*len_write += ft_putstr_fd(current, 1);
	}
	if (c == 'x')
	{
		*temp = ft_putunbr_base(va_arg(args, unsigned int), "0123456789abcdef");
		*len_write += ft_putstr_fd(*temp, 1);
	}
	if (c == 'X')
	{
		*temp = ft_putunbr_base(va_arg(args, unsigned int), "0123456789ABCDEF");
		*len_write += ft_putstr_fd(*temp, 1);
	}
}

void	check_pourcent_p(char c, va_list args, size_t *len_write, char **temp)
{
	unsigned long int	current_p;

	if (c == 'p')
	{
		current_p = va_arg(args, long int);
		if (current_p <= 0)
			*len_write += ft_putstr_fd("(nil)", 1);
		else
		{
			*temp = ft_putunbr_base(current_p, "0123456789abcdef");
			*len_write += ft_putstr_fd("0x", 1);
			*len_write += ft_putstr_fd(*temp, 1);
		}
	}
}

void	check_pourcent_i_c(char c, va_list args, size_t *len_write, char **temp)
{
	char	current;
	size_t	temp_int;

	temp_int = 0;
	if (c == 'd' || c == 'i')
		*len_write += ft_putnbr_fd(va_arg(args, int), 1, &temp_int);
	if (c == 'u')
	{
		*temp = ft_putunbr_base(va_arg(args, unsigned int), "0123456789");
		*len_write += ft_putstr_fd(*temp, 1);
	}
	if (c == 'c')
	{
		current = va_arg(args, int);
		*len_write += ft_putchar_fd(current, 1);
	}
	if (c == '%')
		*len_write += ft_putchar_fd('%', 1);
}

void	check_pourcent(char c, va_list args, size_t *len_write)
{
	char	*temp_free;

	temp_free = NULL;
	if (c == 's' || c == 'x' || c == 'X')
		check_pourcent_str(c, args, len_write, &temp_free);
	if (c == 'd' || c == 'i' || c == 'u' || c == 'c' || c == '%')
		check_pourcent_i_c(c, args, len_write, &temp_free);
	if (c == 'p')
		check_pourcent_p(c, args, len_write, &temp_free);
	free(temp_free);
}

int	ft_printf(const char *format, ...)
{
	int			i;
	size_t		len;
	va_list		args;

	if (format)
	{
		va_start(args, format);
		len = 0;
		i = 0;
		while (format[i])
		{
			if (format[i] == '%')
				check_pourcent(format[++i], args, &len);
			else
			{
				ft_putchar_fd(format[i], 1);
				len++;
			}
			i++;
		}
		va_end(args);
		return (len);
	}
	else
		return (-1);
}

//int main(void)
//{
//	//char *str = "0";
//	//char *test = "test";
//	int i;
//	i = 0;
//	ft_printf("\n%d\n", ft_printf("%u", 15));	
//	return (0);
//}