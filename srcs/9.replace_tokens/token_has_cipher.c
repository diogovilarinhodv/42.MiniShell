/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_has_cipher.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 10:00:10 by dpestana          #+#    #+#             */
/*   Updated: 2022/12/13 04:05:55 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

int	token_has_cipher(t_data *data)
{
	int	inc_chr;

	inc_chr = 0;
	while (*(data->cur.token + inc_chr) != '\0')
	{
		if (*(data->cur.token + inc_chr) == '$')
			return (YES);
		inc_chr++;
	}
	return (NO);
}
