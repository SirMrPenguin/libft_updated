/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joabotel <joabotel@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 17:11:52 by joabotel          #+#    #+#             */
/*   Updated: 2025/05/16 03:39:45 by joabotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);

size_t	ft_strlen(char *str);
char	*ft_join(char *line, char *buffer);
ssize_t	ft_find_nl(char *str);
void	ft_memmove_nl(char *str);
char	*ft_safe_free(char *line, char *buffer);

#endif
