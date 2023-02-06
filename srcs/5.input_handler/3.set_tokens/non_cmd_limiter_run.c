/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   non_cmd_limiter_run.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 18:12:42 by dpestana          #+#    #+#             */
/*   Updated: 2023/02/06 18:35:46 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incs/minishell.h"

char	*non_cmd_limiter_run(t_data *data, char *token)
{
	if (is_table_delimiter(token) == YES)
	{
		set_cur(data);
		add_delimiter(data, token);
		unset_cur(data);
		add_another_table(data);
	}
	else
		add_another_cmd(data);
	free(token);
	return (token);
}
