/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 14:47:20 by dpestana          #+#    #+#             */
/*   Updated: 2022/06/22 14:47:29 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

char	*ft_strdup(const char *s)
{
	char	*p;
	int		cnt;

	p = (char *)malloc(ft_strlen(s) + 1);
	cnt = 0;
	if (p == NULL)
		return (NULL);
	while (*(s + cnt) != '\0')
	{
		*(p + cnt) = *(s + cnt);
		cnt++;
	}
	*(p + cnt) = '\0';
	return (p);
}
