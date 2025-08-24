/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joabotel <joabotel@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 16:55:42 by joabotel          #+#    #+#             */
/*   Updated: 2025/05/16 03:36:50 by joabotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check(char c, va_list ap)
{
	if (c == 'd' || c == 'i')
		return (ft_printnum(va_arg(ap, int)));
	else if (c == 'u')
		return (ft_printunit(va_arg(ap, unsigned int)));
	else if (c == 's')
		return (ft_printstr(va_arg(ap, char *)));
	else if (c == 'p')
		return (ft_printptr(va_arg(ap, unsigned long long)));
	else if (c == 'c')
		return (ft_printchr(va_arg(ap, int)));
	else if (c == 'x' || c == 'X')
		return (ft_printhex(va_arg(ap, unsigned int),
				c == 'x'));
	return (0);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		count;
	va_list	ap;

	if (!s)
		return (-1);
	i = -1;
	count = 0;
	va_start(ap, s);
	while (s[++i])
	{
		if (s[i] == '%')
		{
			if (s[i + 1] && s[i + 1] == '%' && ++count)
				write(1, &s[++i], 1);
			else if (s[i + 1])
				count += ft_check(s[++i], ap);
			else
				break ;
		}
		else
			count += write(1, &s[i], 1);
	}
	va_end(ap);
	return (count);
}
/*
  #include <stdio.h>
int	main(){
	char	*str;
	int	n = -1;
	int	j = 1;
	char	c = 'o';
	str = "Hello world!";
	ft_printf("no argument -> World hello!\n");
	ft_printf("string ->%s\n", str);
	ft_printf("char -> %c\n", c);
	ft_printf("int -> %d\n", n);
	ft_printf("unit -> %u\n", j);
	ft_printf("uppercase hex -> %X\n", n);
	printf("uppercase hex -> %X\n", n);
	ft_printf("lowercase hex -> %x\n", n);
	ft_printf("memory address -> %p\n", &str);
	ft_printf("percent sign -> %%");
}*/
