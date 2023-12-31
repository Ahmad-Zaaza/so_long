/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmadzaaza <ahmadzaaza@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 02:24:36 by azaaza            #+#    #+#             */
/*   Updated: 2023/10/31 00:20:29 by ahmadzaaza       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_mandatory.h"


void	init_map_queue(t_map_queue *queue)
{
	queue->first = NULL;
	queue->last = NULL;
}

void	enqueue(t_map_queue *queue, char *line)
{
	t_map_node	*node;

	node = (t_map_node *)malloc(sizeof(t_map_node));
	node->line = line;
	node->next = NULL;
	if (!queue->first)
	{
		queue->first = node;
		queue->last = node;
	}
	else
	{
		queue->last->next = node;
		queue->last = node;
	}
}

char	*dequeue(t_map_queue *queue)
{
	t_map_node	*tmp;
	char		*content;

	content = queue->first->line;
	tmp = queue->first;
	queue->first = queue->first->next;
	free(tmp);
	return (content);
}

int	queue_size(t_map_queue *queue)
{
	t_map_node	*tmp;
	int			size;

	size = 0;
	tmp = queue->first;
	while (tmp)
	{
		size++;
		tmp = tmp->next;
	}
	return (size);
}
