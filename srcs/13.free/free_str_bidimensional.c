/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_dual_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 20:11:15 by dpestana          #+#    #+#             */
/*   Updated: 2022/12/02 20:19:08 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	free_str_bidimensional(char ***str)
{
	int	inc;

	inc = 0;
	if (*str != NULL)
	{
		while (*(*str + inc) != NULL)
		{
			free(*(*str + inc));
			*(*str + inc) = NULL;
			inc++;
		}
		free(*str);
		*str = NULL;
	}
}