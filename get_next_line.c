/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjo <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 16:55:48 by hjo               #+#    #+#             */
/*   Updated: 2018/04/17 16:55:51 by hjo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_line(const int fd, const char **arr, char **line)
{
	const char	*tmp;
	size_t		i;

	i = 0;
	while (arr[fd][i] != '\n' && arr[fd][i] != '\0')
		i++;
	if (arr[fd][i] == '\n')
	{
		*line = ft_strsub(arr[fd], 0, i);
		tmp = ft_strdup(arr[fd] + i + 1);
		ft_strdel(&arr[fd]);
		arr[fd] = tmp;
		if (arr[fd][0] == '\0')
			ft_strdel(&data[fd]);
	}
	else if (arr[fd][i] == '\0')
	{
		*line = ft_strdup(arr[fd]);
		ft_strdel(&arr[fd]);
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	int			res;
	char		buf[BUFF_SIZE + 1];
	char		*tmp;
	static char	*arr[1023];

	if (!line || fd < 0 || !buf)
		return (-1);
	while (1 && (res = read(fd, buf, BUFF_SIZE) > 0))
	{
		buf[res] = '\0';
		if (arr[fd] == NULL)
			arr[fd] = ft_strnew(1);
		tmp = ft_strjoin(arr[fd], buf);
		ft_strdel(&arr[fd]);
		arr[fd] = tmp;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (res < 0)
		return (-1);
	else if (res == 0 && arr[fd] == NULL)
		return (0);
	return (get_line(fd, arr, line));
}

int		main(int ac, char **av)
{
	if (ac != 2)
		return (0); 

	char	*line = NULL;
	int		fd = open(av[1], O_RDONLY);

	while (get_next_line(fd, &line) > 0)
	{
		printf("%s\n", line);
		free(line);
		line = NULL;
	}
	return (0);
}
/*
int		read_buf(int fd, char *buf, size_t *nbyte)
{
	char	temp[BUFF_SIZE + 1];
	char	*temp2;

	*nbyte = read(fd, temp, BUFF_SIZE);
	temp[*nbyte] = '\0';
	temp2 = buf;
	if (!(buf = ft_strjoin(buf, temp)))
		return (NULL);
	free(&temp2);
	return (buf);
}

int		get_next_line(int fd, char **line)
{
	int		ans;
	char	*str;
	char	*buf;
	char	*temp;

	ans = 1;
	if (!line || fd < 0 || (!buf))
		return (-1);
	while (1)
	{
		if ((str = ft_strchr(buf, '\n')) != NULL)
		{
			*str = '\0';
			if (!(*line = ft_strcpy(temp, buf)))
				return (-1);
			ft_memmove(temp, str + 1, ft_strlen(str + 1) + 1);
			return (1);
		}
		if (!(buf = read_buf(fd, buf, nbyte)))

	}
	ft_bzero(&str, strlen(str));
}
*/