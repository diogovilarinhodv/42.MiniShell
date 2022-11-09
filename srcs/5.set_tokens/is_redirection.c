/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_redirection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:31:06 by dpestana          #+#    #+#             */
/*   Updated: 2022/11/09 17:37:15 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

int	is_redirection(t_data *data, char *token)
{
	if (ft_strncmp(token, "<", 1) == 0)
		return (YES);
	else if (ft_strncmp(token, ">", 1) == 0)
		return (YES);
	else if (ft_strncmp(token, ">>", 2) == 0)
		return (YES);
	return (NO);
}