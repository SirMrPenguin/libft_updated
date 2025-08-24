/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joabotel <joabotel@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 17:11:48 by joabotel          #+#    #+#             */
/*   Updated: 2025/05/09 18:55:16 by joabotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_handle_nl(char *buff, char *new_line)
{
	int	i;

	i = ft_find_nl(new_line);
	if (i >= 0 && new_line[i + 1])
		new_line[i + 1] = 0;
	ft_memmove_nl(buff);
	return (new_line);
}

static char	*ft_read_loop(char *buff, char *new_line, int fd)
{
	ssize_t	bytes_read;

	ft_memmove_nl(buff);
	while (1)
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read < 0)
			return (ft_safe_free(new_line, buff));
		buff[bytes_read] = 0;
		if (bytes_read == 0)
			break ;
		new_line = ft_join(new_line, buff);
		if (!new_line)
			return (NULL);
		if (ft_find_nl(buff) >= 0)
			break ;
		ft_memmove_nl(buff);
	}
	return (new_line);
}

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	char		*new_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	new_line = NULL;
	if (buff[0])
		new_line = ft_join(new_line, buff);
	if (ft_find_nl(buff) >= 0)
		return (ft_handle_nl(buff, new_line));
	new_line = ft_read_loop(buff, new_line, fd);
	if (!new_line)
		return (NULL);
	new_line = ft_handle_nl(buff, new_line);
	return (new_line);
}
/*
#include <fcntl.h>
#include <stdio.h>

int main(){

	int fd = open("get_next_line.c", O_RDONLY);
	char *line;

	while ((line = get_next_line(fd)))
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
}

int	main(){
	int fd = open("get_next_line.c", O_RDONLY);
	char *line = get_next_line(fd);
	printf("%s", line);
	free(line);
	close(fd);
}
*/
