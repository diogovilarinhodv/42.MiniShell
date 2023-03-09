/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_number.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 13:49:50 by dpestana          #+#    #+#             */
/*   Updated: 2023/03/08 23:30:02 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

int	is_number(char *str)
{
	int	inc;

	inc = 0;
	if (*(str + inc) == '-')
		inc++;
	while (*(str + inc) != '\0')
	{
		if (*(str + inc) < '0' || *(str + inc) > '9')
			return (NO);
		inc++;
	}
	return (YES);
}
