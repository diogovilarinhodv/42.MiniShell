/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 16:56:20 by dpestana          #+#    #+#             */
/*   Updated: 2022/09/23 09:09:09 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	execute_input(t_data *data)
{
	int	is_builtin;

	return ;
	if (data->line.cmd == NULL)
		return ;
	is_builtin = builtins(data);
	if (is_builtin == NO)
		non_builtin(data);
}