/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 09:39:59 by dpestana          #+#    #+#             */
/*   Updated: 2022/12/13 04:14:46 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	inc;

	inc = 0;
	while (*(s1 + inc) == *(s2 + inc))
	{
		if (*(s1 + inc) == '\0')
			return (0);
		inc++;
	}
	return (*(s1 + inc) - *(s2 + inc));
}
