/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inicialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 14:19:50 by dpestana          #+#    #+#             */
/*   Updated: 2022/06/21 18:28:58 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	inicialize(t_data *data, int argc, char **argv, char **env)
{
	(void) argc;
	(void) argv;
	if (env == NULL)
		env_empty();
	inicialize_env(data, env);
	data->input.line = NULL;
	data->input.cmd = NULL;
	data->input.args = NULL;
	data->pwd = NULL;
	data->input.qty_args = 0;
}
