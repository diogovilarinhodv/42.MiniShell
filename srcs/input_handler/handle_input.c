/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 18:27:18 by dpestana          #+#    #+#             */
/*   Updated: 2022/10/11 13:20:16 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	handle_input(t_data *data)
{
	if (organize_input(data) == SUCCESS)
		execute_input(data);
	testing_stuffs(data);
	freedom(data, FREEDOM_LINE);
	freedom_tmp(data);
	inicialize_tmp(data);
}
