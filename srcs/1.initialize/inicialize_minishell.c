/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inicialize_minishell.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 01:04:46 by dpestana          #+#    #+#             */
/*   Updated: 2023/01/16 09:16:17 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	initialize_minishell(t_data *data)
{
	if (isatty(STDIN_FILENO) == NO)
	{
		data->exit_status = FAIL;
		end_program(data);
	}
	unset_env(data, "OLDPWD");
	set_shlvl_env(data);
	initialize_termcaps(data);
	signal(SIGINT, catch_sigint);
	signal(SIGQUIT, catch_sigquit);
}
