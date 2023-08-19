/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaaza <azaaza@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 00:20:26 by ahmadzaaza        #+#    #+#             */
/*   Updated: 2023/08/20 02:28:07 by azaaza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

#include "fcntl.h"
#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"

typedef struct s_node {
  char content;
  struct s_node *next;
} t_node;
typedef struct s_queue {
  t_node *first;
  t_node *last;

} t_queue;

char *get_next_line(int fd);
void init_queue(t_queue *queue);
char unshift_queue(t_queue *queue);
void push_queue(t_queue *queue, char content);
int has_newline(t_queue *queue);
char *get_line(t_queue *queue);
char *handle_read(int fd, int readed, char *buffer, t_queue *queue);
int queue_empty(t_queue *queue);
char *get_rest(t_queue *queue);
t_node *ft_lstnew(char content);

#endif