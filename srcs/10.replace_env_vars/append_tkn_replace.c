/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_tkn_replace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 02:57:18 by dpestana          #+#    #+#             */
/*   Updated: 2022/12/13 02:57:30 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

char	*append_tkn_replace(t_data *data, int str_one_pos, char *token)
{
	char	*new_str;
	char	*new_token;

	new_str = ft_strdup((data->cur.token + str_one_pos));
	new_token = ft_strjoin(token, new_str);
	free_str(&new_str);
	free_str(&token);
	return (new_token);
}
