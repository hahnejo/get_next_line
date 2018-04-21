/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjo <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 16:55:58 by hjo               #+#    #+#             */
/*   Updated: 2018/04/17 16:56:00 by hjo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef GET_NEXT_LINE
# define GET_NEXT_LINE

#include "./src/libft/libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

# define BUFF_SIZE 8

int		get_next_line	(const int fd, char **line);
int		get_line		(int fd, char **arr, char **line);

#endif