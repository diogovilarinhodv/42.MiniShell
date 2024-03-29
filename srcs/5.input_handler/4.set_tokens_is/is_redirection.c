/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_redirection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:31:06 by dpestana          #+#    #+#             */
/*   Updated: 2023/03/04 14:43:54 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incs/minishell.h"

int	is_redirection(char *token)
{
	if (ft_strcmp(token, "<") == 0)
		return (YES);
	else if (ft_strcmp(token, ">") == 0)
		return (YES);
	else if (ft_strcmp(token, ">>") == 0)
		return (YES);
	else if (ft_strcmp(token, "<<") == 0)
		return (YES);
	return (NO);
}
