/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_std_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 16:43:44 by dpestana          #+#    #+#             */
/*   Updated: 2023/03/23 13:58:11 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	close_std_fd(t_data *data)
{
	dup2(data->stdin_saved, STDIN_FILENO);
	dup2(data->stdout_saved, STDOUT_FILENO);
	close(data->stdin_saved);
	close(data->stdout_saved);
}
