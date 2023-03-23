/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 17:14:58 by dpestana          #+#    #+#             */
/*   Updated: 2023/03/23 14:06:18 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	execute(t_data *data)
{
	if (data->exit_status == EXIT_SUCCESS)
		if (builtins(data) == NO)
			non_builtin(data);
	close_fd(data);
}
