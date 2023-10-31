/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmadzaaza <ahmadzaaza@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 23:12:36 by ahmadzaaza        #+#    #+#             */
/*   Updated: 2023/10/31 23:38:53 by ahmadzaaza       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_mandatory.h"

int	is_valid_char(char c)
{
	int i;
	char valid_chars[5] = "10ECP";

	i = 0;
	while (i < 5)
	{
		if (c == valid_chars[i])
			return (1);
		i++;
	}
	return (0);
}