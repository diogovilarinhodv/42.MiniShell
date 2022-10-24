/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 17:57:13 by dpestana          #+#    #+#             */
/*   Updated: 2022/10/23 15:05:26 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	create_token(t_data *data, int pos_beg, int pos_end, char *token)
{
	token = ft_substr(data->input.line, pos_beg, pos_end - pos_beg);
}