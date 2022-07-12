/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_invalid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 18:12:12 by dpestana          #+#    #+#             */
/*   Updated: 2022/07/12 19:14:08 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	invalid_line(t_data *data)
{
	printf("Error\n");
	freedom(data);
	exit(1);
}