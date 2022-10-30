/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   organize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 17:18:01 by dpestana          #+#    #+#             */
/*   Updated: 2022/10/30 23:24:05 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

// deu error, verificar, add_first_token arranjar maneira de simplificar linha de codigo, como no tenho estado a alterar no execute
// ls ; cat filer | grep "bla" | wc | wc ; lol
// ls ; cat filer | grep "bla" | wc 	-> memory leak
// ls ; cat filer | grep "bla"			-> shows null in "bla"

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
		printf("TOKEN - %s\n", token);
		if (is_cmd_delimiter(token) == NO)
		{
			if (is_first_cmd(data) == YES)
			{
				if (is_first_table(data) == YES)
					add_first_table(data);
				add_first_cmd(data);
			}
			add_token(data, token);
		}
		else if (is_cmd_delimiter(token) == YES)
		{
			if (is_table_delimiter(token) == YES)
				add_another_table(data);
			else
				add_another_cmd(data);
			free(token);
		}
	}
	printf("YAH - %s\n", *(((data->store.table + 1)->cmd + 0)->token + 0));
	testing_stuffs(data);
}
