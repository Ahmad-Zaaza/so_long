/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmadzaaza <ahmadzaaza@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 00:20:26 by ahmadzaaza        #+#    #+#             */
/*   Updated: 2023/10/17 02:14:04 by ahmadzaaza       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef MAX_FD
#  define MAX_FD 1000
# endif

# include "fcntl.h"
# include "stdio.h"
# include "stdlib.h"
# include "unistd.h"

typedef struct s_list
{
	char			content;
	struct s_list	*next;
}					t_list;

typedef struct s_queue
{
	t_list			*first;
	t_list			*last;

}					t_queue;

typedef struct s_table_item
{
	t_queue			queue;
	int				init;
}					t_table_item;

char				*get_next_line(int fd);
void				init_queue(t_queue *queue);
char				unshift_queue(t_queue *queue);
void				push_queue(t_queue *queue, char content);
int					has_newline(t_queue *queue);
char				*get_line(t_queue *queue);
char				*handle_read(int fd, int readed, char *buffer,
						t_queue *queue);
int					queue_empty(t_queue *queue);
char				*get_rest(t_queue *queue);
t_list				*ft_lstnew(char content);
#endif