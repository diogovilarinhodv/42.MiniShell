/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 17:39:35 by dpestana          #+#    #+#             */
/*   Updated: 2022/12/15 17:40:51 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

char	*get_input_str(t_data *data, char *buf, int i)
{
	char	*input;

	*(buf + i - 1) = '\0';
	input = ft_strdup(buf);
	if (input == NULL)
		end_program(data, FAIL);
	return (input);
}
