/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:22:17 by dernst            #+#    #+#             */
/*   Updated: 2024/12/05 20:38:10 by dernst           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "limits.h"

// Check each malloc and check potential leaks with valgrind 
// If args == NULL so return NULL or print NULL i don't remember but do somethings

static void check_pourcent(char c, va_list args, size_t *temp_len)
{
	char ch;
	char *p_free;
	char *current;
	unsigned long int current_p;

	if(c == 'c')
	{
		ch = va_arg(args, int);
		*temp_len += ft_putchar_fd(ch, 1);
	}
	if (c == 's')
	{
		current = va_arg(args, char *);
		if (current == NULL)
		{
			write(1, "(null)", 6);
			*temp_len += 6;
		}
		*temp_len += ft_putstr_fd(current, 1);
	}
	if (c == 'p')
	{
		current_p = va_arg(args, long int);
		if (current_p <= 0)
		{
			write(1, "(nil)", 5);
			*temp_len += 5;
		}
		else
		{
			write(1, "0x", 2);
			p_free = ft_putunbr_base(current_p, "0123456789abcdef");
			*temp_len += ft_putstr_fd(p_free, 1);
			free(p_free);
			*temp_len += 2;
		}
	}
	if (c == 'x')
	{
		p_free = ft_putunbr_base(va_arg(args, unsigned int), "0123456789abcdef");
		*temp_len += ft_putstr_fd(p_free, 1);
		free(p_free);
	}
	if (c == 'X')
	{
		p_free = ft_putunbr_base(va_arg(args, unsigned int), "0123456789ABCDEF");
		*temp_len += ft_putstr_fd(p_free, 1);
		free(p_free);
		
	}
	if (c == '%')
		*temp_len += ft_putchar_fd('%', 1);
}

void	check_pourcent_str(char c, va_list args, size_t *len_write)
{
	char	*temp_free;
	char	*current;

	if (c == 's')
	{
		current = va_arg(args, char *);
		if (current == NULL)
		{
			write(1, "(null)", 6);
			*len_write += 6;
		}
		*len_write += ft_putstr_fd(current, 1);
	}
	
}

void	check_pourcent_int(char c, va_list args, size_t *len_write)
{
	char 	*temp_free;
	size_t	temp_int;
	
	if (c == 'd' || c == 'i')
		*len_write += ft_putnbr_fd(va_arg(args, int), 1, &temp_int);
	if (c == 'u')
	{
		temp_free = ft_putunbr_base(va_arg(args, unsigned int), "0123456789");
		*len_write += ft_putstr_fd(temp_free, 1);
		free(temp_free);
	}
}

int	ft_printf(const char *format, ...)
{
	int	i;
	size_t len;
	va_list args;
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
//	ft_printf("%d", ft_printf(NULL));
//	//printf("%d",printf(NULL));
//	return (0);
//}