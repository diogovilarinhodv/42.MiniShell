/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 10:05:50 by dpestana          #+#    #+#             */
/*   Updated: 2023/01/16 09:18:49 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	builtin_exit(t_data *data)
{
	write(1, "exit\n", ft_strlen("exit\n"));
	data->exit_status = SUCCESS;
	end_program(data);
}
