/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_std_fd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 16:33:59 by dpestana          #+#    #+#             */
/*   Updated: 2023/03/23 13:34:14 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	save_std_fd(t_data *data)
{
	data->stdin_saved = dup(STDIN_FILENO);
	data->stdout_saved = dup(STDOUT_FILENO);
}
