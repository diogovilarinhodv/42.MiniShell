/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   non_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 17:01:54 by dpestana          #+#    #+#             */
/*   Updated: 2022/10/13 09:35:17 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"
// ping -c 5 google.com | grep rtt
// cat filer | grep bla | wc

void	non_builtin(t_data *data)
{
	set_absolute_path(data);
	set_dup2(data);
	if (execve(*data->cur.cmd->token, data->cur.cmd->token, NULL) == -1)
		kill(getpid(), SIGKILL);
}
