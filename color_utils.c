/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaaza <azaaza@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 20:49:41 by azaaza            #+#    #+#             */
/*   Updated: 2023/08/18 20:51:25 by azaaza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int create_trgb(int t, int r, int g, int b) {
  return (t << 24 | r << 16 | g << 8 | b);
}

int get_t(int trgb) { return trgb >> 24 & 0xFF; }
int get_r(int trgb) { return trgb >> 16 & 0xFF; }
int get_g(int trgb) { return trgb >> 8 & 0xFF; }
int get_b(int trgb) { return trgb & 0xFF; }