/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmadzaaza <ahmadzaaza@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 10:58:03 by azaaza            #+#    #+#             */
/*   Updated: 2023/10/31 00:20:29 by ahmadzaaza       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/so_long_mandatory.h"

#ifndef ANIMATIONS_H
#define ANIMATIONS_H

typedef struct s_animation {
  void *images[4];
  int current_frame;
} t_animation;



#endif