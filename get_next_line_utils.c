/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joabotel <joabotel@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 18:54:57 by joabotel          #+#    #+#             */
/*   Updated: 2025/05/09 00:05:21 by joabotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_fake(char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_join(char *line, char *buff)
{
	size_t	i;
	size_t	j;
	char	*big;

	if (!line)
	{
		line = malloc(1);
		if (!line)
			return (NULL);
		line[0] = 0;
	}
	big = malloc((ft_strlen_fake(line) + ft_strlen_fake(buff) + 1) * sizeof(char));
	if (big)
	{
		i = -1;
		j = -1;
		while (line[++i])
			big[i] = line[i];
		while (buff[++j])
			big[i + j] = buff[j];
		big[i + j] = 0;
	}
	free (line);
	return (big);
}

ssize_t	ft_find_nl(char *str)
{
	ssize_t	i;

	if (!str)
		return (-1);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

void	ft_memmove_nl(char *buff)
{
	ssize_t	i;
	ssize_t	nl;

	i = 0;
	nl = ft_find_nl(buff);
	if (nl < 0)
		return ;
	nl++;
	while (buff[i + nl])
	{
		buff[i] = buff[i + nl];
		i++;
	}
	while (i < BUFFER_SIZE)
		buff[i++] = 0;
}

char	*ft_safe_free(char *line, char *buff)
{
	size_t	i;

	if (line)
		free(line);
	i = -1;
	while (++i < BUFFER_SIZE)
		buff[i] = 0;
	return (NULL);
}
