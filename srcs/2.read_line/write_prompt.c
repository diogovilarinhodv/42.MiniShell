/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_prompt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 17:07:54 by dpestana          #+#    #+#             */
/*   Updated: 2022/12/15 17:10:37 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	write_prompt(t_data *data)
{
	if (data->exit_status == EXIT_SUCCESS)
		ft_putstr(BCYN "➜  " BGRN "MiniShell:" RST);
	else
		ft_putstr(BRED "➜  " BGRN "MiniShell:" RST);
}
