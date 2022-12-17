/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inicialize_minishell.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 01:04:46 by dpestana          #+#    #+#             */
/*   Updated: 2022/12/16 23:17:11 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	initialize_minishell(t_data *data)
{
	if (isatty(STDIN_FILENO) == NO)
		end_program(data, FAIL);
	unset_env(data, "OLDPWD");
	set_shlvl_env(data);
	initialize_termcaps(data);
	signal(SIGINT, catch_sigint);
	signal(SIGQUIT, catch_sigquit);
}
