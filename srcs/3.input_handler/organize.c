/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   organize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 17:18:01 by dpestana          #+#    #+#             */
/*   Updated: 2022/10/13 22:25:49 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	organize(t_data *data)
{
	int		inc;
	int		pos_beg;
	int		pos_end;
	char	*token;

	inc = 0;
	while (*(data->input + inc) != '\0')
	{
		set_token(data, &inc, &pos_beg, &pos_end);
		create_token(data, pos_beg, pos_end, &token);
		if (is_pipe(token) == YES)
			add_cmd(data);
		else
			add_token(data, token);
		printf("%s\n", token);
	}
	testing_stuffs(data);
}
