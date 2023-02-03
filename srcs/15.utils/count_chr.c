/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_chr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 20:23:34 by dpestana          #+#    #+#             */
/*   Updated: 2022/12/02 20:52:19 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

int	count_chr(char *str, char c)
{
	int	inc;
	int	count;

	inc = 0;
	count = 0;
	if (str == NULL)
		return (count);
	while (*(str + inc) != '\0')
	{
		if (*(str + inc) == c)
			count++;
		inc++;
	}
	return (count);
}
