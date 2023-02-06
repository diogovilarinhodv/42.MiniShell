/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_limiter_run.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 18:12:12 by dpestana          #+#    #+#             */
/*   Updated: 2023/02/06 18:35:42 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incs/minishell.h"

char	*cmd_limiter_run(t_data *data, char *token)
{
	if (is_first_cmd(data) == YES)
	{
		if (is_first_table(data) == YES)
			add_first_table(data);
		add_first_cmd(data);
	}
	set_cur(data);
	if (is_redirection(token) == YES)
		add_redirection_type(data, token);
	else if (data->cur.cmd->is_red == YES)
		add_redirection_token(data, token);
	else
		add_token(data, token);
	unset_cur(data);
	return (token);
}
