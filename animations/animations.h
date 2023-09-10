/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaaza <azaaza@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 10:58:03 by azaaza            #+#    #+#             */
/*   Updated: 2023/09/10 11:27:18 by azaaza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../so_long.h"

#ifndef ANIMATIONS_H
#define ANIMATIONS_H

typedef struct s_animation {
  void *images[4];
  int current_frame;
} t_animation;



#endif