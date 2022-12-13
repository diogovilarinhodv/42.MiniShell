/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tkn_replace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 02:55:25 by dpestana          #+#    #+#             */
/*   Updated: 2022/12/13 02:55:45 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

char	*create_tkn_replace(char *str_one, char *str_two, char *new_token)
{
	char	*clone;

	if (new_token != NULL)
	{
		clone = ft_strjoin(new_token, str_one);
		free_str(&new_token);
		new_token = clone;
		if (str_two != NULL)
		{
			clone = ft_strjoin(new_token, str_two);
			free_str(&new_token);
			new_token = clone;
		}
	}
	else
	{
		if (str_two != NULL)
			new_token = ft_strjoin(str_one, str_two);
		else
			new_token = ft_strdup(str_one);
	}
	return (new_token);
}
