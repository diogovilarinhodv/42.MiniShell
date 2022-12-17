/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inicialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 14:19:50 by dpestana          #+#    #+#             */
/*   Updated: 2022/12/17 04:11:10 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	initialize(t_data *data, int argc, char **argv, char **env)
{
	(void) argc;
	(void) argv;
	initialize_env(data, env);
	initialize_input(data);
	initialize_table(data);
	initialize_history(data);
	initialize_minishell(data);
	data->exit_status = SUCCESS;
}
