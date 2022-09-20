/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:56:16 by dpestana          #+#    #+#             */
/*   Updated: 2022/07/16 15:56:32 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	set_cmd(t_data *data, int *have_cmd, int pos_beg, int pos_end)
{
	data->lst_cmd->cmd = ft_substr(data->line, pos_beg, pos_end - pos_beg);
	*have_cmd = 1;
}
