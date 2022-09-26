/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inicialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 14:19:50 by dpestana          #+#    #+#             */
/*   Updated: 2022/09/26 10:47:36 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	inicialize(t_data *data, int argc, char **argv, char **env)
{
	(void) argc;
	(void) argv;
	data->tmp.cmd = NULL;
	inicialize_env(data, env);
	inicialize_input(data);
	inicialize_line(data);
	data->tmp.idx = 0;
	data->tmp.fd = malloc(sizeof(int) * 2);
	pipe(data->tmp.fd);
}
