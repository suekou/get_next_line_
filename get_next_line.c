/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuenaga <ksuenaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 15:26:41 by ksuenaga          #+#    #+#             */
/*   Updated: 2024/02/13 23:44:16 by ksuenaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_line(int fd, char *buf, char *save)
{
	char	*tmp;
	int		read_status;

	if (ft_locate_char(save, '\n') >= 0)
		return (save);
	while (1)
	{
		read_status = read(fd, buf, BUFFER_SIZE);
		if (read_status == -1)
			return (NULL);
		if (read_status == 0 && !save)
			return (NULL);
		if (read_status == 0)
			break;
		buf[read_status] = '\0';
		if (!save)
			save = ft_strdup(buf);
		else
		{
			tmp = ft_strjoin(save, buf);
			free(save);
			save = tmp;
		}
		if (ft_locate_char(save, '\n') >= 0 || read_status == 0)
			break;
	}
	return (save);
}

static char *extract_line(char **save)
{
	char	*line;
	char	*new_save;
	int		newline_index;

	newline_index = ft_locate_char(*save, '\n');
	if (newline_index < 0)
	{
		line = ft_strdup(*save);
		free(*save);
		*save = NULL;
		return (line);
	}
	line = ft_substr(*save, 0, newline_index + 1);
	if ((*save)[newline_index + 1] != '\0')
		new_save = ft_strdup(*save + newline_index + 1);
	else
		new_save = NULL;
	free(*save);
	*save = new_save;
	return (line);
}

char	*get_next_line(int fd)
{
	char		*buf;
	char		*line;
	static char	*save;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = (char *)malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	save = read_line(fd, buf, save);
	free(buf);
	if (!save)
		return (NULL);
	line = extract_line(&save);
	return (line);
}
