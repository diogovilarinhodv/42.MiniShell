/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_cipher.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 09:44:04 by dpestana          #+#    #+#             */
/*   Updated: 2023/03/14 11:26:35 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incs/minishell.h"

void	replace_cipher(t_data *data)
{
	char	*aft_cipher_str;
	char	*new_tkn;
	char	*first_str_part;

	aft_cipher_str = NULL;
	new_tkn = NULL;
	first_str_part = get_first_str_part(data);
	if (first_str_part == NULL)
	{
		new_tkn = ft_strdup(data->cur.token + data->cur.idx_chr);
		data->cur.idx_chr = 0;
	}
	else
	{
		aft_cipher_str = ft_strdup((data->cur.token + data->cur.idx_chr));
		new_tkn = ft_strjoin(first_str_part, aft_cipher_str);
		data->cur.idx_chr = ft_strlen(first_str_part);
		free_str(&aft_cipher_str);
		free_str(&first_str_part);
	}
	free_str(&data->cur.token);
	data->cur.token = new_tkn;
}
