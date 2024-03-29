/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 22:58:56 by dpestana          #+#    #+#             */
/*   Updated: 2023/03/23 15:04:01 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	reset_line(t_data *data)
{
	write_str("^C\n");
	data->exit_status = EXIT_CMD_INTERRUPTED;
	set_exit_status_env(data);
	write_prompt(data);
	ft_bzero(data->input.buf, BUFSIZ);
	data->input.buf_idx = 0;
}
