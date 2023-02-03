/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_signals.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 22:46:09 by dpestana          #+#    #+#             */
/*   Updated: 2023/02/02 22:56:27 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	initialize_signals(t_data *data);
{
	signal(SIGINT, catch_sigint);
	signal(SIGQUIT, catch_sigquit);
	data->exit_status = SUCCESS;
}
