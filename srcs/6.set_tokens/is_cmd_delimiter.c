/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_cmd_delimiter.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 13:43:28 by dpestana          #+#    #+#             */
/*   Updated: 2022/12/13 04:04:02 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

int	is_cmd_delimiter(char *token)
{
	if (*token == ';')
		return (YES);
	if (*token == '|')
		return (YES);
	if (*token == '&')
		return (YES);
	return (NO);
}
