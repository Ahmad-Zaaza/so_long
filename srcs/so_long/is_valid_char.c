/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmadzaaza <ahmadzaaza@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 23:12:36 by ahmadzaaza        #+#    #+#             */
/*   Updated: 2023/11/08 23:48:24 by ahmadzaaza       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_mandatory.h"

int	is_valid_char(char c)
{
	int		i;
	char	valid_chars[6];

	valid_chars[0] = '1';
	valid_chars[1] = '0';
	valid_chars[2] = 'E';
	valid_chars[3] = 'C';
	valid_chars[4] = 'P';
	valid_chars[5] = '\0';
	i = 0;
	while (i < 5)
	{
		if (c == valid_chars[i])
			return (1);
		i++;
	}
	return (0);
}
