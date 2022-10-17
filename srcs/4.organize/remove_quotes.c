/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 11:01:08 by dpestana          #+#    #+#             */
/*   Updated: 2022/10/16 21:34:46 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	remove_quotes(t_data *data, int *pos_beg, int *pos_end)
{
	if (*(data->input + *pos_beg) == '"' && *(data->input + *pos_end - 1) == '"')
	{
		(*pos_beg)++;
		(*pos_end)--;
	}
	if (*(data->input + *pos_beg) == '\'' && *(data->input + *pos_end - 1) == '\'')
	{
		(*pos_beg)++;
		(*pos_end)--;
	}
}