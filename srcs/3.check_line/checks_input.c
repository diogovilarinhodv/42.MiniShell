/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 15:40:44 by dpestana          #+#    #+#             */
/*   Updated: 2022/12/16 23:36:09 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

int	checks_input(t_data *data)
{
	if (first_check(data) == FAIL)
		return (FAIL);
	remove_spaces_bysides(data);
	if (second_check(data) == FAIL)
		return (FAIL);
	return (SUCCESS);
}
