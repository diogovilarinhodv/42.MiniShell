/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 21:34:57 by dpestana          #+#    #+#             */
/*   Updated: 2022/12/13 04:14:37 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

char	*ft_strchr(char *str, char ch)
{
	int		inc;

	inc = 0;
	if (str == NULL)
		return (NULL);
	if (*str == '\0')
		return (NULL);
	while (*(str + inc) != '\0')
	{
		if (*(str + inc) == ch)
			return ((str + inc));
		inc++;
	}
	return (NULL);
}
