/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_spaces_bysides.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 15:41:30 by dpestana          #+#    #+#             */
/*   Updated: 2022/12/13 03:56:27 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

static void	remove_left_spaces(t_data *data)
{
	int		inc;
	char	*clone;

	inc = 0;
	while (*(data->input.line + inc) != '\0')
	{
		if (ft_isspace(*(data->input.line + inc)) == 0)
			break ;
		inc++;
	}
	clone = ft_strdup(data->input.line + inc);
	free(data->input.line);
	data->input.line = clone;
}

static void	remove_right_spaces(t_data *data)
{
	int		dec;
	char	*clone;

	dec = ft_strlen(data->input.line);
	while (dec > 0)
	{
		if (ft_isspace(*(data->input.line + dec - 1)) == 0)
			break ;
		dec--;
	}
	clone = ft_strndup(data->input.line, dec);
	free(data->input.line);
	data->input.line = clone;
}

void	remove_spaces_bysides(t_data *data)
{
	remove_left_spaces(data);
	remove_right_spaces(data);
}
