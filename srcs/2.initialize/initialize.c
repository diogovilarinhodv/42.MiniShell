/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 14:19:50 by dpestana          #+#    #+#             */
/*   Updated: 2023/02/04 18:06:07 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	initialize(t_data *data, int argc, char **argv, char **env)
{
	(void) argc;
	(void) argv;
	initialize_env(data, env);
	initialize_table(data);
	initialize_history(data);
	initialize_termcaps(data);
	initialize_signals(data);
	data->exit_status = SUCCESS;
}
