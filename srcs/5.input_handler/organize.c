/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   organize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 18:16:25 by dpestana          #+#    #+#             */
/*   Updated: 2023/02/06 18:17:29 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	organize(t_data *data)
{
	int		pos_beg;
	int		pos_end;
	char	*token;

	while (*(data->input.line + data->input.idx) != '\0')
	{
		get_tokens(data, &pos_beg, &pos_end);
		if (exist_token(data, pos_beg, pos_end) == END)
			break ;
		create_token(data, pos_beg, pos_end, &token);
		if (is_cmd_delimiter(token) == NO)
			token = cmd_limiter_run(data, token);
		else
			token = non_cmd_limiter_run(data, token);
	}
}
