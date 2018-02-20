/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isstrdigit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 18:33:42 by lmarques          #+#    #+#             */
/*   Updated: 2018/02/20 19:06:47 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isstrdigit(const char *s)
{
	int	count;

	count = -1;
	while (s[++count])
		if (!ft_isdigit(s[count]))
			return (0);
	return (1);
}
