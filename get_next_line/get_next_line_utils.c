/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaaza <azaaza@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 10:51:26 by azaaza            #+#    #+#             */
/*   Updated: 2023/08/20 02:28:28 by azaaza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_line(t_queue *queue) {
  int count;
  char *str;
  t_node *tmp;

  tmp = queue->first;
  count = 0;
  while (tmp && tmp->content != '\n') {
    count++;
    tmp = tmp->next;
  }
  str = (char *)malloc(sizeof(char) * count + 2);
  if (!str)
    return (NULL);
  count = 0;
  while (queue->first && queue->first->content != '\n')
    str[count++] = unshift_queue(queue);
  str[count++] = unshift_queue(queue);
  str[count] = '\0';
  return (str);
}

char *get_rest(t_queue *queue) {
  t_node *tmp;
  char *line;
  int count;

  tmp = queue->first;
  count = 0;
  while (tmp) {
    count++;
    tmp = tmp->next;
  }
  line = (char *)malloc(count + 1);
  count = 0;
  while (queue->first) {
    line[count++] = unshift_queue(queue);
  }
  line[count] = '\0';
  return (line);
}

char unshift_queue(t_queue *queue) {
  t_node *tmp;
  char c;

  c = queue->first->content;
  tmp = queue->first;
  queue->first = queue->first->next;
  free(tmp);
  return (c);
}

void push_queue(t_queue *queue, char content) {
  t_node *new;

  new = ft_lstnew(content);
  if (!new)
    return;
  if (!queue->first) {
    queue->first = new;
    queue->last = new;
  } else {
    queue->last->next = new;
    queue->last = new;
  }
}

t_node *ft_lstnew(char content) {
  t_node *lst;

  lst = (t_node *)malloc(sizeof(t_node));
  if (!lst)
    return (NULL);
  lst->content = content;
  lst->next = NULL;
  return (lst);
}