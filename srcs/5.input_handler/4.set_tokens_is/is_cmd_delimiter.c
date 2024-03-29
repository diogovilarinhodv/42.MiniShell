/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_cmd_delimiter.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 13:43:28 by dpestana          #+#    #+#             */
/*   Updated: 2023/02/06 18:35:50 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incs/minishell.h"

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
