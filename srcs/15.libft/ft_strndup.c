/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 15:47:00 by dpestana          #+#    #+#             */
/*   Updated: 2022/10/11 15:49:09 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

char	*ft_strndup(const char *s, int qty)
{
	char	*p;
	int		cnt;

	p = (char *)malloc(qty + 1);
	cnt = 0;
	if (p == NULL)
		return (NULL);
	while (cnt < qty)
	{
		*(p + cnt) = *(s + cnt);
		cnt++;
	}
	*(p + cnt) = '\0';
	return (p);
}
