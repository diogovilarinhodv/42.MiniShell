/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 18:27:18 by dpestana          #+#    #+#             */
/*   Updated: 2022/10/21 12:10:35 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	handle_input(t_data *data)
{
	inicialize_line(data);
	inicialize_tmp(data);
	organize(data);
	//organize2(data);
	execute(data);
	free_line(data);
	free_tmp(data);
}
