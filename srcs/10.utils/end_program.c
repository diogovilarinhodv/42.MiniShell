/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_program.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 14:30:23 by dpestana          #+#    #+#             */
/*   Updated: 2022/12/14 03:13:40 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	end_program(t_data *data, int status)
{
	turn_on_canonical(data);
	free_env(data);
	free_input(data);
	free_fd(data);
	free_store(data);
	exit(status);
}
