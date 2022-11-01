/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_program.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 14:30:23 by dpestana          #+#    #+#             */
/*   Updated: 2022/11/01 11:38:39 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	end_program(t_data *data, int status)
{
	free_env(data);
	free_input(data);
	free_pid(data);
	free_fd(data);
	free_store(data);
	exit(status);
}
