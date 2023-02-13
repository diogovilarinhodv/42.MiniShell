/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jump_quotes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:33:33 by dpestana          #+#    #+#             */
/*   Updated: 2023/02/08 15:44:57 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	jump_quotes(char *str, int *inc)
{
	while (*(str + (*inc)) == '"' || *(str + (*inc)) == '\'')
	{
		if (*(str + (*inc)) == '"')
		{
			(*inc)++;
			while (*(str + (*inc)) == '"')
				(*inc)++;
		}
		if (*(str + (*inc)) == '\'')
		{
			(*inc)++;
			while (*(str + (*inc)) == '\'')
				(*inc)++;
		}
	}
}