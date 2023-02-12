/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_number.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 13:49:50 by dpestana          #+#    #+#             */
/*   Updated: 2023/02/12 13:51:50 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

int	is_number(char *str)
{
	int	inc;

	inc = 0;
	while (*(str + inc) != '\0')
	{
		if (*(str + inc) < '0' || *(str + inc) > '9')
			return (NO);
		inc++;
	}
	return (YES);
}
