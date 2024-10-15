/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaoberso <yaoberso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:03:19 by yaoberso          #+#    #+#             */
/*   Updated: 2024/10/15 14:00:13 by yaoberso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>

void	check_format(int i, const char *str, va_list ap)
{
	if (str[i] == 'c')
	{
		char	arg;

		arg = (char)va_arg(ap, int);
		write(1, &arg, 1);
	}
	else if (str[i] == 's')
	{
		
	}
	else if (str[i] == 'p')
	{
		
	}
	else if (str[i] == 'd')
	{
		
	}
	else if (str[i] == 'i')
	{
		
	}
	else if (str[i] == 'u')
	{
		
	}
	else if (str[i] == 'x')
	{
		
	}
	else if (str[i] == 'X')
	{
		
	}
	else if (str[i] == '%')
	{
		write(1, "%", 1);
	}

}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		nb_arg;
	int		i;
	char	*cur_arg;

	va_start(ap, format);
	cur_arg = va_arg(ap, char *);
	nb_arg = 0;
	while (cur_arg != NULL)
	{
		i = 0;
		while (cur_arg[i] != '\0')
		{
			if (cur_arg[i] == '%')
			{
				nb_arg++;
				check_format((i + 1), cur_arg, ap);
			}
			i++;
		}
		cur_arg = va_arg(ap, char *);
	}
	va_end(ap);
	return (nb_arg);
}