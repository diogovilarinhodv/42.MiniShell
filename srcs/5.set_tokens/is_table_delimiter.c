/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_table_delimiter.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 13:43:58 by dpestana          #+#    #+#             */
/*   Updated: 2022/12/13 04:04:11 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

int	is_table_delimiter(char *token)
{
	if (*token == ';')
		return (YES);
	if (*token == '|' && *(token + 1) == '|')
		return (YES);
	if (*token == '&' && *(token + 1) == '&')
		return (YES);
	return (NO);
}
