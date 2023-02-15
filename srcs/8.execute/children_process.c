/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   children_process.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 19:24:06 by dpestana          #+#    #+#             */
/*   Updated: 2023/02/15 16:53:50 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	children_process(t_data *data)
{
	char	***env;

	env = &data->env.full;
	set_dup2(data);
	signal(SIGINT, SIG_DFL);
	close_all_fd(data);
	path_handler(data);
	set_env_var_full(data);
	printf("%s\n", *data->cur.cmd->token);
	if (execve(*data->cur.cmd->token, data->cur.cmd->token, *env) == -1)
		execve_error(data);
}
