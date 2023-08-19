/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaaza <azaaza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 23:16:06 by ahmadzaaza        #+#    #+#             */
/*   Updated: 2023/07/25 11:30:42 by azaaza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putmem(unsigned long n)
{
	int	count;

	ft_putchar(48);
	ft_putchar('x');
	count = 2;
	if (!n)
	{
		ft_puthex(0, &count, 'x');
		return (count);
	}
	ft_puthex(n, &count, 'x');
	return (count);
}

void	ft_putnbr(int n, int *count)
{
	long int	nb;

	nb = n;
	if (nb < 0)
	{
		nb = -nb;
		*count += ft_putchar('-');
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10, count);
	}
	*count += ft_putchar(nb % 10 + 48);
}

void	ft_putunbr(unsigned int n, int *count)
{
	long int	nb;

	nb = n;
	if (nb < 0)
	{
		nb = -nb;
		*count += ft_putchar('-');
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10, count);
	}
	*count += ft_putchar(nb % 10 + 48);
}
