/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaaza <azaaza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 22:30:02 by ahmadzaaza        #+#    #+#             */
/*   Updated: 2023/07/25 11:17:57 by azaaza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

void	ft_parse(char c, va_list *args, int *count)
{
	if (c == 'c')
		*count += ft_putchar(va_arg(*args, int));
	else if (c == 's')
		*count += ft_putstr(va_arg(*args, char *));
	else if (c == 'p')
		*count += ft_putmem(va_arg(*args, unsigned long int));
	else if (c == 'd')
		ft_putnbr(va_arg(*args, int), count);
	else if (c == 'i')
		ft_putnbr(va_arg(*args, int), count);
	else if (c == 'x' || c == 'X')
		ft_puthex(va_arg(*args, unsigned int), count, c);
	else if (c == 'u')
		ft_putunbr(va_arg(*args, unsigned int), count);
	else if (c == '%')
		*count += ft_putchar('%');
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		count;

	count = 0;
	i = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			ft_parse(str[i], &args, &count);
			i++;
		}
		else
		{
			count += ft_putchar(str[i]);
			i++;
		}
	}
	va_end(args);
	return (count);
}
