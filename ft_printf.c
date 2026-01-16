/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkim2 <jkim2@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 14:24:18 by jkim2             #+#    #+#             */
/*   Updated: 2026/01/16 14:48:28 by jkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_format(const char *str, va_list *par, int i)
{
	if (str[i] == 'c')
		return (ft_print_c((char)va_arg(*par, int)));
	else if (str[i] == 's')
		return (ft_print_s(va_arg(*par, char *)));
	else if (str[i] == 'd' || str[i] == 'i')
		return (ft_print_d(va_arg(*par, int)));
	else if (str[i] == 'u')
		return (ft_print_u(va_arg(*par, unsigned int)));
	else if (str[i] == 'x' || str[i] == 'X')
		return (ft_print_x(va_arg(*par, unsigned int), str[i]));
	else if (str[i] == 'p')
		return (ft_print_p((uintptr_t)va_arg(*par, void *)));
	else if (str[i] == '%')
		return (ft_print_c('%'));
	return (0);
}

static int	parse_format(const char *str, va_list *ap, int *i)
{
	if (str[*i] != '%')
		return (ft_print_c(str[*i]));
	(*i)++;
	if (!str[*i])
		return (-1);
	return (check_format(str, ap, *i));
}

int	ft_printf(const char *input_str, ...)
{
	va_list	params;
	int		i;
	int		count;
	int		ret;

	va_start(params, input_str);
	i = 0;
	count = 0;
	while (input_str[i])
	{
		ret = parse_format(input_str, &params, &i);
		if (ret < 0)
		{
			va_end(params);
			return (-1);
		}
		count += ret;
		i++;
	}
	va_end(params);
	return (count);
}
