/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readcolor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohelly <ohelly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 14:46:30 by ohelly            #+#    #+#             */
/*   Updated: 2019/04/26 18:47:13 by ohelly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_base(char *str, int *base)
{
	int		i;

	*base = 10;
	i = 0;
	if (str[i])
	{
		if (str[i] == '0')
		{
			i++;
			if (ft_toupper(str[i]) == 'X')
			{
				*base = 16;
				i++;
			}
			else if (ft_toupper(str[i]) == 'B')
			{
				*base = 2;
				i++;
			}
			else
				*base = 8;
		}
	}
	return (i);
}

int		ft_readcolor(char *str, int ind)
{
	int		base;
	int		digit;
	int		res;
	int		i;

	i = ft_base(str, &base);
	res = 0;
	digit = 0;
	while (i <= ind)
	{
		digit = ft_toupper(str[i++]);
		digit = (digit >= 'A') ? digit - 'A' + 0x0a : digit - '0';
		if (digit >= 0 && digit < base)
			res = res * base + digit;
		else
			return (0);
	}
	return (res);
}
