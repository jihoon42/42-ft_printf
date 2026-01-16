/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_S.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkim2 <jkim2@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 14:18:11 by jkim2             #+#    #+#             */
/*   Updated: 2026/01/16 15:15:10 by jkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_s(char *s)
{
	int		i;
	char	*str;

	i = 0;
	str = s;
	if (!str)
		str = "(null)";
	while (str[i])
	{
		if (ft_print_c(str[i]) == -1)
			return (-1);
		i++;
	}
	return (i);
}
