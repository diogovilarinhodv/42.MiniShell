/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 22:58:56 by dpestana          #+#    #+#             */
/*   Updated: 2022/12/18 18:05:50 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	reset_line(t_data *data)
{
	write(STDOUT_FILENO, "^C\n", ft_strlen("^C\n"));
	data->exit_status = EXIT_CMD_INTERRUPTED;
	write_prompt(data);
	ft_bzero(data->input.buf, BUFSIZ);
	data->input.buf_idx = 0;
}
