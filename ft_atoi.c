/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joabotel <joabotel@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 20:36:43 by joabotel          #+#    #+#             */
/*   Updated: 2025/10/20 18:13:39 by joabotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	nb;
	int	min;

	nb = 0;
	min = 0;
	while ((*str >= 9 && *str <= 13) || (*str == ' '))
		str++;
	if ((*str == '-') || (*str == '+'))
	{
		if (*str == '-')
			min++;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		nb *= 10;
		nb += *str - 48;
		if ((min == 0 && nb > INT_MAX) || (min == -1
				&& (long)nb > (long)INT_MAX + 1))
			return (0);
		str++;
	}
	if (min % 2 == 0)
		return (nb);
	return (-nb);
}
/*
#include <stdio.h>

int	main(int ac, char **av){
	(void)ac;
	printf("%d\n", ft_atoi(av[1]));
}
*/
