/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_redirection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:32:19 by dpestana          #+#    #+#             */
/*   Updated: 2022/11/09 17:58:08 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	add_redirection(t_data *data, char *token)
{
	// malloc
	// have to do if is the first or another, do in func
	if (ft_strncmp(token, "<", 1) == 0)
		data->redirect->type = ft_strdup("<");
	else if (ft_strncmp(token, ">", 1) == 0)
		data->redirect->type = ft_strdup(">");
	else if (ft_strncmp(token, ">>", 2) == 0)
		data->redirect->type = ft_strdup(">>");
	data->redirect->is_redirect = YES;
	free(token);
}