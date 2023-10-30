/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmadzaaza <ahmadzaaza@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 00:39:55 by ahmadzaaza        #+#    #+#             */
/*   Updated: 2023/10/31 00:20:29 by ahmadzaaza       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_mandatory.h"

void	*xpm_to_image(t_game **game, char *file)
{
	int height;
	int width;
	void *ptr;

	ptr = (mlx_xpm_file_to_image((*game)->mlx, file, &width, &height));
	return (ptr);
}