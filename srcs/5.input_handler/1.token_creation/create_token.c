/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 17:57:13 by dpestana          #+#    #+#             */
/*   Updated: 2023/03/03 17:56:35 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incs/minishell.h"

void	create_token(t_data *data, int pos_beg, int pos_end, char **token)
{
	*token = ft_substr(data->input.line, pos_beg, pos_end - pos_beg);
}
